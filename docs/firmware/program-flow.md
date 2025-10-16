---
title: Program Flow
subtitle:
description: Execution flow, state diagrams, and operational logic
status:
icon: material/chart-timeline-variant
---

<!-- LICENSE INFORMATION
Copyright (C) 2025 ATARI Research Lab
Permission is granted to copy, distribute and/or modify this document
under the terms of the GNU Free Documentation License, Version 1.3
or any later version published by the Free Software Foundation;
with no Invariant Sections, no Front-Cover Texts, and no Back-Cover Texts.
A copy of the license is included in the section entitled "GNU
Free Documentation License".
-->

## Overview

The CICERONE AirLink firmware executes in two distinct phases: **Setup** (initialization) and
**Main Loop** (continuous operation). This page details the execution flow and logic for both phases.

## Setup Phase

<!-- markdownlint-disable MD046 -->
??? "Setup Phase Diagram"

    ``` mermaid
        flowchart TD

        n1["Start"] --> rtc_init
        rtc_init["Initialize RTC and periodic alarms"] --> t6793_init["Initialize T6793 CO₂ sensor"]
        t6793_init --> sen5x_init["Initialize SEN54 PM/VOC sensor"]
        sen5x_init --> if_nbiot{"Enable NB-IoT?"}
        if_nbiot -- Yes --> nbiot_init["Initialize NB-IoT module SIM7020G"]
        if_nbiot -- No --> setup_done("Setup Complete")
        nbiot_init --> setup_done

        n1@{ shape: start}

        class n1,setup_done final;
        classDef default stroke-width:1px, stroke-dasharray:none, stroke:#374D7C, fill:#E2EBFF, color:#000000
        classDef final stroke-width:4px, stroke-dasharray: 0, stroke:#00C853, fill:#C8E6C9, color:#000000
    ```
<!-- markdownlint-enable MD046 -->

### Execution Sequence

The `setup()` function executes once at power-on or reset:

#### 1. Serial Communication

```cpp
#if DEBUG_LEVEL > 0
    Serial.begin(115200);
    while (!Serial) {
        ; // Wait for serial port to connect
    }
    DEBUG_INFO("CICERONE AirLink starting...");
#endif
```

**Purpose**: Initialize UART for debug output

**Baud Rate**: 115200

**Conditional**: Only if `DEBUG_LEVEL > 0`

#### 2. RTC Initialization

```cpp
rtc_inicializar();
rtc_alarma_inicializar();
```

**Purpose**: Configure DS3231M real-time clock

**Tasks**:

- Verify I2C communication
- Set initial time (if needed)
- Configure 10-minute alarm schedule
- Enable alarm interrupts

**Critical**: If RTC fails, system halts (time is essential)

#### 3. T6793 CO₂ Sensor Initialization

```cpp
t6793_inicializar();
```

**Purpose**: Initialize Telaire T6793-5K CO₂ sensor

**Tasks**:

- Configure I2C communication (address 0x15)
- Verify sensor response
- Set measurement mode
- Wait for sensor stabilization

**Fallback**: Continue if sensor fails (log error, skip readings)

#### 4. SEN54 Sensor Initialization

```cpp
sen5x_inicializar();
```

**Purpose**: Initialize Sensirion SEN54 PM/VOC sensor

**Tasks**:

- Configure I2C communication (address 0x69)
- Soft reset sensor
- Start measurement mode
- Wait for warm-up period (~30 seconds for VOC accuracy)

**Fallback**: Continue if sensor fails (log error, skip readings)

#### 5. NB-IoT Initialization (Conditional)

```cpp
#if HABILITAR_NBIOT
    nbiot_inicializar();
#endif
```

**Purpose**: Initialize SIM7020G NB-IoT module

**Tasks**:

- Configure UART communication (Serial1)
- Send AT commands to module
- Verify SIM card detection
- Register with network (may take 30-60 seconds)
- Configure APN settings

**Conditional**: Only if `HABILITAR_NBIOT = 1`

**Fallback**: Continue if fails (log error, local logging only)

### Initialization Order Rationale

The specific order (RTC → T6793 → SEN54 → NB-IoT) ensures:

1. **Timing First**: RTC must be functional before scheduling data collection
2. **Sensors Before Network**: Sensors need warm-up time during network registration
3. **Critical to Optional**: Essential components before optional features
4. **Fast to Slow**: Quick initializations before time-consuming network setup

### Typical Setup Duration

| Component | Duration | Notes |
|-----------|----------|-------|
| Serial | <100ms | Nearly instant |
| RTC | ~200ms | I2C communication + config |
| T6793 | ~500ms | Sensor wake-up |
| SEN54 | ~1-2s | Soft reset + measurement start |
| NB-IoT | 30-60s | Network registration varies |
| **Total** | **~35-65s** | Mostly network registration |

!!! tip "Reducing Setup Time"
    During development, disable NB-IoT (`HABILITAR_NBIOT = 0`) to reduce setup time to ~3-5 seconds.

## Main Loop Phase

<!-- markdownlint-disable MD046-->
??? "Main Loop Diagram"

    ``` mermaid
        flowchart TB

        setup_done["Setup"] --> check_alarm_5s["Check if 5 seconds have elapsed"]
        check_alarm_5s --> check_alarm_10min["Check if 10 minutes have elapsed"]
        check_alarm_10min --> if_alarm_5s{"5-second flag active?"}
        if_alarm_5s -- No --> if_alarm_10min{"10-minute flag active?"}
        if_alarm_5s -- Yes --> accumulate_data["Read sensors and accumulate data"]
        accumulate_data --> reset_alarm_5s["Reset 5-second flag"]
        reset_alarm_5s --> if_alarm_10min

        if_alarm_10min -- No --> check_alarm_5s
        if_alarm_10min -- Yes --> average_data["Calculate average of accumulated readings"]
        average_data --> if_nbiot2{"Enable NB-IoT?"}
        if_nbiot2 -- No --> reset_alarm_10min
        if_nbiot2 -- Yes --> transmit_data["Transmit averaged data via HTTP POST"]
        transmit_data --> reset_alarm_10min["Reset 10-minute flag and counters"]
        reset_alarm_10min --> check_alarm_5s

        setup_done:::final

        classDef default stroke-width:1px, stroke-dasharray:none, stroke:#374D7C, fill:#E2EBFF, color:#000000
        classDef final stroke-width:4px, stroke-dasharray: 0, stroke:#00C853, fill:#C8E6C9, color:#000000
    ```
<!-- markdownlint-enable MD046-->

### Main Loop Structure

The `loop()` function runs continuously with minimal blocking:

```cpp
void loop() {
    // Check timers
    check_alarma_5s();
    check_alarma_10min();

    // Handle 5-second cycle
    if (alarma_5s) {
        acumular_datos();
        alarma_5s = false;
    }

    // Handle 10-minute cycle
    if (alarma_10min) {
        promediar_datos();

        #if HABILITAR_NBIOT
            String json = nbiot_paquete();
            nbiot_enviar(json);
        #endif

        alarma_10min = false;
    }
}
```

## 5-Second Cycle (Data Acquisition)

```cpp
void check_alarma_5s() {
    unsigned long current_millis = millis();

    if (current_millis - prev_millis_5s >= 5000) {
        prev_millis_5s = current_millis;
        alarma_5s = true;
    }
}
```

**Non-blocking**: Function returns immediately

**Accuracy**: ±10ms (millis() resolution)

**Overflow Handling**: Subtraction math handles millis() rollover (every 49.7 days)

### Data Accumulation

```cpp
void acumular_datos() {
    DEBUG_VERBOSE("Reading sensors...");

    // Read SEN54 sensor
    if (sen5x_leer()) {
        sum_sen5x_mc_1p0 += sen5x_mc_1p0;
        sum_sen5x_mc_2p5 += sen5x_mc_2p5;
        sum_sen5x_mc_4p0 += sen5x_mc_4p0;
        sum_sen5x_mc_10p0 += sen5x_mc_10p0;
        sum_sen5x_voc_index += sen5x_voc_index;
        sum_sen5x_temp += sen5x_temp;
        sum_sen5x_hum += sen5x_hum;
        cont1++;
    }

    // Read T6793 sensor
    if (t6793_leer()) {
        sum_t6793_co2 += t6793_co2;
        cont2++;
    }

    DEBUG_VERBOSE("Samples: SEN54=%d, T6793=%d", cont1, cont2);
}
```

### Accumulation Strategy

**Separate Counters**: `cont1` (SEN54) and `cont2` (T6793)

**Rationale**:

- Sensors may have different reliability
- Failed reads don't corrupt averages
- Allows for different sampling rates

**Floating-Point Precision**: All accumulation uses `float` to preserve decimal places

**Error Handling**: Failed sensor reads skip accumulation (counter not incremented)

### Expected Sample Count

Over 10 minutes:

- **Target**: 120 samples per sensor (12/minute × 10 minutes)
- **Typical**: 118-120 samples (some reads may fail)
- **Minimum Acceptable**: 100 samples (if below, may indicate sensor issue)

## 10-Minute Cycle (Averaging & Transmission)

```cpp
void check_alarma_10min() {
    DateTime now = rtc.getRTCTime();

    // Check if current minute is multiple of 10
    if (now.minute() % 10 == 0 && now.second() < 5) {
        if (!alarm_10min_triggered) {
            alarma_10min = true;
            alarm_10min_triggered = true;
        }
    } else {
        alarm_10min_triggered = false;  // Reset for next 10-minute mark
    }
}
```

**RTC-Based**: Uses real-time clock, not millis()

**Accuracy**: ±1 second

**Trigger Points**: :00, :10, :20, :30, :40, :50 of each hour

**Debounce**: `alarm_10min_triggered` prevents multiple triggers

### Data Averaging

```cpp
void promediar_datos() {
    DEBUG_INFO("Calculating averages...");

    // Calculate SEN54 averages
    if (cont1 > 0) {
        avg_sen5x_mc_1p0 = sum_sen5x_mc_1p0 / cont1;
        avg_sen5x_mc_2p5 = sum_sen5x_mc_2p5 / cont1;
        avg_sen5x_mc_4p0 = sum_sen5x_mc_4p0 / cont1;
        avg_sen5x_mc_10p0 = sum_sen5x_mc_10p0 / cont1;
        avg_sen5x_voc_index = sum_sen5x_voc_index / cont1;
        avg_sen5x_temp = sum_sen5x_temp / cont1;
        avg_sen5x_hum = sum_sen5x_hum / cont1;
    }

    // Calculate T6793 averages
    if (cont2 > 0) {
        avg_t6793_co2 = sum_t6793_co2 / cont2;
    }

    // Get timestamp from RTC
    DateTime now = rtc.getRTCTime();
    fecha = formatDate(now);
    hora = formatTime(now);

    DEBUG_INFO("PM2.5: %.2f, CO2: %.0f", avg_sen5x_mc_2p5, avg_t6793_co2);
}
```

### Averaging Algorithm

**Method**: Simple arithmetic mean

**Formula**: `average = sum / count`

**Advantages**:

- Memory-efficient (no array storage needed)
- Computationally simple
- Suitable for air quality data (outliers are rare)

**Alternative Approaches** (not implemented):

- Median filtering (requires storing all samples)
- Weighted average (more complex, minimal benefit)
- Outlier rejection (adds complexity, sensor failures already handled)

### Reset Accumulators

```cpp
void reset_accumulators() {
    // Reset SEN54 sums
    sum_sen5x_mc_1p0 = 0.0f;
    sum_sen5x_mc_2p5 = 0.0f;
    // ... (all other sums)

    // Reset counters
    cont1 = 0;
    cont2 = 0;
}
```

**When**: After transmission (or averaging if NB-IoT disabled)

**Purpose**: Prepare for next 10-minute cycle

**Critical**: Must reset to avoid overflow and incorrect averages

### Data Transmission

```cpp
#if HABILITAR_NBIOT
    String json = nbiot_paquete();
    bool success = nbiot_enviar(json);

    if (success) {
        DEBUG_INFO("Data transmitted successfully");
    } else {
        DEBUG_ERROR("Transmission failed");
    }
#endif
```

**Conditional**: Only if `HABILITAR_NBIOT = 1`

**JSON Format**: See [Data Transmission](data-transmission.md)

**Retry Logic**: Handled within `nbiot_enviar()`

**Duration**: 30-60 seconds typically

## Timing Characteristics

### 5-Second Cycle

| Metric | Value | Notes |
|--------|-------|-------|
| **Interval** | 5000ms | Configurable in code |
| **Accuracy** | ±10ms | Based on millis() |
| **Duration** | ~100-200ms | Sensor I2C reads |
| **Blocking** | Minimal | I2C reads are brief |
| **CPU Usage** | <5% | Most time idle |

### 10-Minute Cycle

| Metric | Value | Notes |
|--------|-------|-------|
| **Interval** | 600s (10 min) | Based on RTC |
| **Accuracy** | ±1s | RTC precision |
| **Duration** | 30-60s | Mostly NB-IoT transmission |
| **Blocking** | Significant | AT commands wait for response |
| **CPU Usage** | ~80% | During transmission |

### Daily Operation

- **Data Points**: 144 per day (1 every 10 minutes)
- **Sensor Readings**: 17,280 per day (144 × 120 samples)
- **Transmissions**: 144 per day (if NB-IoT enabled)
- **Total Uptime**: 24 hours (no sleep modes)

## Error Handling During Operation

### Sensor Read Failures

**Strategy**: Skip sample, continue operation

```cpp
if (!sen5x_leer()) {
    DEBUG_WARN("SEN5X read failed, skipping sample");
    // Counter not incremented, sum not updated
    return;
}
```

**Impact**: Slight reduction in sample count (e.g., 118 instead of 120)

**Recovery**: Automatically retries next 5-second cycle

### RTC Failures

**Strategy**: Halt or use backup timing

```cpp
if (!rtc.isRunning()) {
    DEBUG_ERROR("RTC stopped, check battery");
    // Option 1: Halt (safe but stops data collection)
    while(1);

    // Option 2: Fall back to millis() timing (less accurate)
    use_millis_timing = true;
}
```

**Critical**: RTC failure affects timestamps (data integrity issue)

### NB-IoT Transmission Failures

**Strategy**: Log error, continue to next cycle

```cpp
if (!nbiot_enviar(json)) {
    DEBUG_ERROR("Transmission failed, data lost");
    // Data is lost (no local storage)
    // Next 10-minute cycle will try again with new data
}
```

**Impact**: Data gap on server

## Performance Monitoring

### Debug Output Example

```text
[INFO][5012][MAIN] Setup complete
[VERBO][10234][ALARMA] Reading sensors... (sample 1/120)
[VERBO][15234][ALARMA] Reading sensors... (sample 2/120)
...
[INFO][610234][ALARMA] Calculating averages... (120 samples)
[INFO][610235][ALARMA] PM2.5: 12.34, CO2: 687
[INFO][610250][NBIOT] Transmitting data...
[INFO][645123][NBIOT] Transmission successful (response: 200 OK)
```

## Related Documentation

- [Architecture](architecture.md) - System architecture and modular design
- [Data Transmission](data-transmission.md) - Network communication details
- [Sensor Interfaces](sensor-interfaces.md) - Sensor communication protocols
- [Debug Configuration](../user-guide/debug-configuration.md) - Debug system setup
