---
title: Sensor Interfaces
subtitle:
description: Sensor communication protocols, specifications, and calibration
status:
icon: material/chip
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

<!-- markdownlint-disable MD024 -->

## Overview

The CICERONE AirLink device integrates three primary sensors for comprehensive air quality
monitoring. All sensors communicate via I2C protocol, sharing the same bus with different addresses.

## I2C Bus Configuration

**Bus**: Wire (Arduino standard I2C library)

**Speed**: 100 kHz (standard mode)

**Pull-ups**: External 4.7kΩ resistors on PCB

**Voltage**: 5V logic level (with level shifters if needed)

### I2C Address Map

| Device | Address | Conflict Resolution |
|--------|---------|---------------------|
| SEN54 | 0x69 | Fixed by manufacturer |
| T6793 | 0x15 | Configurable (factory default) |
| DS3231M | 0x68 | Fixed by manufacturer |

!!! success "No Address Conflicts"
    All I2C devices use different addresses, avoiding conflicts on the shared bus.

## SEN54 Particulate Matter & VOC Sensor

### Specifications

**Manufacturer**: Sensirion

**Model**: SEN54

**Communication**: I2C (address 0x69)

**Supply Voltage**: 4.5-5.5V

**Power Consumption**: ~60 mA typical

**Warm-up Time**: ~30 seconds for VOC accuracy

### Measured Parameters

| Parameter | Range | Accuracy | Units |
|-----------|-------|----------|-------|
| **PM1.0** | 0-1000 | ±10 µg/m³ | µg/m³ |
| **PM2.5** | 0-1000 | ±10 µg/m³ | µg/m³ |
| **PM4.0** | 0-1000 | ±25 µg/m³ | µg/m³ |
| **PM10** | 0-1000 | ±25 µg/m³ | µg/m³ |
| **VOC Index** | 1-500 | - | Index |
| **Temperature** | -10 to 50 | ±0.5°C | °C |
| **Humidity** | 0-100 | ±4.5% RH | % |

### Library

**Name**: Sensirion I2C SEN5X

**Version**: 0.3.0 (official from Sensirion)

**Installation**:

```bash
arduino-cli lib install "Sensirion I2C SEN5X" "Sensirion Core"
```

### Initialization Sequence

```cpp
bool sen5x_inicializar() {
    Wire.begin();
    sen5x.begin(Wire);

    // Soft reset
    error = sen5x.deviceReset();
    if (error) {
        DEBUG_ERROR("SEN5X reset failed");
        return false;
    }

    delay(100);  // Wait for reset

    // Start measurement
    error = sen5x.startMeasurement();
    if (error) {
        DEBUG_ERROR("Failed to start measurement");
        return false;
    }

    DEBUG_INFO("SEN5X initialized successfully");
    return true;
}
```

### Reading Data

```cpp
bool sen5x_leer() {
    uint16_t error;

    error = sen5x.readMeasuredValues(
        sen5x_mc_1p0,
        sen5x_mc_2p5,
        sen5x_mc_4p0,
        sen5x_mc_10p0,
        sen5x_hum,
        sen5x_temp,
        sen5x_voc_index,
        sen5x_nox_index
    );

    if (error) {
        DEBUG_WARN("SEN5X read error: %d", error);
        return false;
    }

    DEBUG_VERBOSE("PM2.5: %.2f, VOC: %d, Temp: %.1f°C",
                  sen5x_mc_2p5, sen5x_voc_index, sen5x_temp);

    return true;
}
```

### VOC Index Explained

**Scale**: 1-500 (100 = neutral)

**Interpretation**:

- **1-100**: Clean air
- **100-200**: Moderate VOC levels
- **200-300**: Elevated VOC levels
- **300-500**: High VOC levels

**Algorithm**: Sensirion's proprietary VOC algorithm adapts to environment over 12-24 hours

**Initial Values**: May be unreliable for first ~30 seconds after power-on

### Troubleshooting

**Sensor Not Responding**:

1. Check I2C connections (SDA, SCL, GND, VCC)
2. Verify 5V power supply
3. Check I2C address with scanner
4. Ensure sensor is properly seated

**Incorrect Readings**:

1. Allow 30-second warm-up for VOC
2. Check for physical obstructions blocking air inlet
3. Verify sensor is not exposed to extreme temperatures

**Communication Errors**:

```text
[WARN][5012][SEN5X] SEN5X read error: 4
```

**Common Error Codes**:

- `1`: I2C communication timeout
- `2`: Checksum error (data corruption)
- `4`: Sensor not ready (still warming up)

## T6793-5K CO₂ Sensor

### Specifications

**Manufacturer**: Amphenol Advanced Sensors (Telaire)

**Model**: T6793-5K

**Communication**: I2C (address 0x15)

**Supply Voltage**: 4.5-5.5V

**Power Consumption**: ~35 mA typical

**Warm-up Time**: <60 seconds

**Measurement Range**: 0-5000 ppm CO₂

**Accuracy**: ±(50 ppm + 5% of reading)

### Technology

**Method**: Non-Dispersive Infrared (NDIR)

**Calibration**: ABC (Automatic Baseline Correction)

**Expected Lifetime**: >15 years

### Custom Driver

Since there's no official Arduino library, we implement a custom driver:

**Files**: `T67XX.h` / `T67XX.cpp` and `T6793_API.h` / `T6793_API.cpp`

**Features**:

- Low-level I2C communication
- Command/response protocol
- Error detection

### Initialization Sequence

```cpp
bool t6793_inicializar() {
    // Initialize sensor object
    airSensor.begin(Wire);

    // Verify communication
    if (!airSensor.isConnected()) {
        DEBUG_ERROR("T6793 not detected");
        return false;
    }

    // Enable ABC algorithm
    airSensor.setABC(true);

    DEBUG_INFO("T6793 initialized successfully");
    return true;
}
```

### Reading Data

```cpp
bool t6793_leer() {
    t6793_co2 = airSensor.getCO2();

    if (t6793_co2 < 0) {
        DEBUG_WARN("T6793 read error");
        return false;
    }

    DEBUG_VERBOSE("CO2: %.0f ppm", t6793_co2);

    return true;
}
```

### ABC Algorithm

**Purpose**: Automatic calibration to 400 ppm (outdoor CO₂ level)

**Operation**:

- Monitors minimum CO₂ values over 24-hour periods
- Assumes sensor is periodically exposed to fresh air
- Gradually adjusts baseline to account for sensor drift

**Requirements**:

- Device should see fresh air at least once per day
- Not suitable for continuously sealed environments
- Can be disabled if manual calibration preferred

**Configuration**:

```cpp
airSensor.setABC(true);   // Enable ABC (recommended)
airSensor.setABC(false);  // Disable ABC (manual calibration)
```

### Typical CO₂ Levels

| Environment | CO₂ Level | Air Quality |
|-------------|-----------|-------------|
| **Outdoor** | 400 ppm | Baseline |
| **Well-ventilated room** | 400-600 ppm | Excellent |
| **Occupied room** | 600-1000 ppm | Good |
| **Poorly ventilated** | 1000-2000 ppm | Poor |
| **Very poor ventilation** | >2000 ppm | Unhealthy |

### Troubleshooting

**Sensor Not Detected**:

1. Verify I2C address (0x15)
2. Check power supply (5V)
3. Ensure proper I2C connections

**Unrealistic Readings**:

1. Allow 60-second warm-up after power-on
2. Verify sensor is not in sealed enclosure
3. Check for calibration issues

**Calibration Issues**:

If ABC is enabled but readings seem incorrect:

```cpp
// Manual calibration to 400 ppm (expose to fresh outdoor air)
airSensor.calibrateSingle(400);
```

## DS3231M Real-Time Clock

### Specifications

**Manufacturer**: Maxim Integrated (Analog Devices)

**Model**: DS3231M

**Communication**: I2C (address 0x68)

**Supply Voltage**: 2.3-5.5V

**Battery Backup**: CR2032 coin cell

**Accuracy**: ±5ppm (±2 minutes per year)

**Temperature Range**: -40 to +85°C

### Features

**TCXO**: Temperature-compensated crystal oscillator

**Alarm Functions**: Two programmable alarms

**32kHz Output**: Optional square wave output

**Aging Offset**: Software-adjustable for long-term accuracy

### Library

**Name**: Custom implementation (DS3231M.h/cpp)

**Based on**: Maxim DS3231 datasheet

### Initialization

```cpp
bool rtc_inicializar() {
    if (!rtc.begin()) {
        DEBUG_ERROR("RTC not found");
        while (1);  // Halt (RTC is critical)
    }

    if (rtc.lostPower()) {
        DEBUG_WARN("RTC lost power, setting time");
        // Set time from compile time or user input
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }

    DEBUG_INFO("RTC initialized");
    return true;
}
```

### Setting Time

**From Compile Time** (during upload):

```cpp
rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
```

**Manual** (specific date/time):

```cpp
// Set to October 16, 2025, 14:30:00
rtc.adjust(DateTime(2025, 10, 16, 14, 30, 0));
```

### Reading Time

```cpp
DateTime now = rtc.getRTCTime();

Serial.print(now.year());
Serial.print("/");
Serial.print(now.month());
Serial.print("/");
Serial.print(now.day());
Serial.print(" ");
Serial.print(now.hour());
Serial.print(":");
Serial.print(now.minute());
Serial.print(":");
Serial.println(now.second());
```

### Alarm Configuration

```cpp
void rtc_alarma_inicializar() {
    // Set alarm to trigger every 10 minutes
    // (triggered when minute == 0, 10, 20, 30, 40, 50)

    rtc.disableAlarm(1);
    rtc.disableAlarm(2);
    rtc.clearAlarm(1);
    rtc.clearAlarm(2);

    // Configure alarm 1 to match minutes
    rtc.setAlarm(ALM1_MATCH_MINUTES, 0, 0, 0, 1);

    DEBUG_INFO("RTC alarms configured");
}
```

### Battery Backup

**Purpose**: Maintains time during power loss

**Battery**: CR2032 (3V, ~200mAh)

**Expected Lifetime**: 5-10 years (depending on temperature)

**Replacement**: When time is lost after power cycles

### Temperature Reading

The DS3231M includes a temperature sensor for crystal compensation:

```cpp
float rtc_temp = rtc.getTemperature();
Serial.print("RTC Temperature: ");
Serial.print(rtc_temp);
Serial.println("°C");
```

**Accuracy**: ±3°C (not calibrated for ambient measurement)

**Update Rate**: Every 64 seconds

**Use Case**: Monitoring RTC temperature, not air temperature

### Troubleshooting

**RTC Not Detected**:

1. Check I2C connections
2. Verify power supply
3. Ensure address is 0x68

**Time Lost After Power Cycle**:

1. Replace CR2032 backup battery
2. Check battery holder connections
3. Re-set time after battery replacement

**Incorrect Time**:

1. Verify timezone configuration in `Datetime_helper.h`
2. Check if daylight saving time adjustment is needed
3. Manually set time if necessary

## I2C Bus Troubleshooting

### I2C Scanner

Use this sketch to detect all I2C devices:

```cpp
#include <Wire.h>

void setup() {
  Serial.begin(115200);
  Wire.begin();

  Serial.println("I2C Scanner");
  Serial.println("Scanning...");

  byte count = 0;
  for (byte i = 1; i < 127; i++) {
    Wire.beginTransmission(i);
    byte error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Device found at 0x");
      if (i < 16) Serial.print("0");
      Serial.println(i, HEX);
      count++;
    }
  }

  Serial.print("Found ");
  Serial.print(count);
  Serial.println(" device(s)");
}

void loop() {}
```

**Expected Output**:

```text
Device found at 0x15  (T6793)
Device found at 0x68  (DS3231M)
Device found at 0x69  (SEN54)
Found 3 device(s)
```

### Common I2C Issues

**No Devices Found**:

- Check SDA/SCL connections
- Verify pull-up resistors (4.7kΩ)
- Ensure 5V power to sensors

**Communication Errors**:

- Reduce I2C bus speed
- Shorten wire lengths
- Check for electromagnetic interference

**Intermittent Failures**:

- Verify power supply stability
- Check for loose connections
- Monitor for voltage drops during transmission

## Related Documentation

- [Program Flow](program-flow.md) - How sensors are read in main loop
- [Architecture](architecture.md) - System architecture overview
- [Data Transmission](data-transmission.md) - How sensor data is transmitted
- [Firmware Configuration](../user-guide/firmware-configuration.md) - Device configuration
