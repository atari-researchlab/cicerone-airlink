---
title: Debug Configuration
subtitle:
description:
status:
icon: material/bug
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

The `Debug.h` file provides a comprehensive debug message management system for the CICERONE AirLink firmware. It implements a multi-level logging framework that allows you to control the verbosity of debug output on a per-module basis through the serial monitor.

!!! info "File Location"
    The debug configuration file is located at: `firmware/Debug.h`

!!! tip "Memory Optimization"
    When `DEBUG_LEVEL` is set to 0, all debug macros compile to empty statements. The compiler optimizes them out completely, saving both flash memory and RAM while improving performance.

## Debug System Architecture

### Message Format

Debug messages follow a standardized format that includes three key components:

```text
[LEVEL][TIMESTAMP][MODULE] Message content
```

**Example output:**

```text
[ERROR][1543][RTC] Unable to establish communication with RTC
[INFO][5012][SEN5X] Sensor initialized successfully
[VERBOSE][10234][NBIOT] AT+CGATT response: +CGATT: 1
```

### Components Breakdown

1. **LEVEL**: Message severity (`ERROR`, `WARN`, `INFO`, `VERBO`)
2. **TIMESTAMP**: Milliseconds since device startup (from `millis()`)
3. **MODULE**: Source module identifier (defined by `DEBUG_TAG`)
4. **Message**: Formatted debug message content

## Debug Levels

The debug system implements a hierarchical logging system with four severity levels:

| Level | Value | Name | Description | Use Case |
|-------|-------|------|-------------|----------|
| **0** | 0 | **Disabled** | No debug output | Production deployment |
| **1** | 1 | **ERROR** | Critical errors only | Minimal debugging |
| **2** | 2 | **WARN** | Errors + warnings | Standard operation |
| **3** | 3 | **INFO** | General program flow | Recommended for development |
| **4** | 4 | **VERBOSE** | Detailed information | Deep debugging (e.g., sensor readings every 5s) |

!!! note "Hierarchical System"
    Setting a debug level automatically enables all lower levels. For example, `DEBUG_LEVEL = 3` (INFO) will also display WARN and ERROR messages.

## Configuration Parameters

### Global Debug Level

#### `DEBUG_LEVEL`

Controls the global verbosity threshold for all debug messages.

**Default value:**

```cpp
#define DEBUG_LEVEL 3
```

**Options:**

- `0` - Disable all debug output (production mode)
- `1` - Show only ERROR messages
- `2` - Show ERROR + WARN messages
- `3` - Show ERROR + WARN + INFO messages (recommended for development)
- `4` - Show all messages including VERBOSE details

**Usage:**

Set this value based on your debugging needs. For production deployments, always set to `0` to save memory and improve performance.

**Examples:**

```cpp
#define DEBUG_LEVEL 0    // Production: no debug output
#define DEBUG_LEVEL 3    // Development: general debugging
#define DEBUG_LEVEL 4    // Deep debugging: all details
```

### Per-Module Debug Levels

The debug system allows fine-grained control over each firmware module independently. This is useful when troubleshooting a specific component without being overwhelmed by messages from other modules.

#### `DEBUG_ALARMA`

Controls debug output from the timing and data acquisition loop (`Alarma.cpp`).

**Default value:**

```cpp
#define DEBUG_ALARMA 2
```

**Messages include:**

- 5-second alarm triggers
- 10-minute alarm triggers
- Data accumulation events
- Averaging calculations

#### `DEBUG_SEN5X`

Controls debug output from the SEN54 particulate matter and VOC sensor (`SEN5X_API.cpp`).

**Default value:**

```cpp
#define DEBUG_SEN5X 2
```

**Messages include:**

- Sensor initialization status
- I2C communication errors
- Sensor readings (at VERBOSE level)
- Data quality warnings

#### `DEBUG_T6793`

Controls debug output from the Telaire T6793-5K CO₂ sensor (`T6793_API.cpp`).

**Default value:**

```cpp
#define DEBUG_T6793 2
```

**Messages include:**

- Sensor initialization status
- I2C communication errors
- CO₂ readings (at VERBOSE level)
- Calibration status

#### `DEBUG_DS3231M`

Controls debug output from the DS3231M Real-Time Clock (`DS3231M.cpp`).

**Default value:**

```cpp
#define DEBUG_DS3231M 2
```

**Messages include:**

- RTC initialization status
- Time synchronization events
- I2C communication errors
- Temperature readings from RTC

#### `DEBUG_NBIOT`

Controls debug output from the SIM7020G NB-IoT module (`Transmision_NBIOT.cpp`).

**Default value:**

```cpp
#define DEBUG_NBIOT 2
```

**Messages include:**

- Module initialization sequence
- Network registration status
- AT command exchanges (at VERBOSE level)
- HTTP POST request/response
- Connection errors

!!! example "Per-Module Configuration Example"
    To debug only the NB-IoT module while keeping other modules quiet:
    <!-- markdownlint-disable MD046 -->
    ```cpp
    #define DEBUG_LEVEL 4        // Enable all message types
    #define DEBUG_ALARMA 0       // Disable alarm messages
    #define DEBUG_SEN5X 0        // Disable SEN5X messages
    #define DEBUG_T6793 0        // Disable T6793 messages
    #define DEBUG_DS3231M 0      // Disable RTC messages
    #define DEBUG_NBIOT 4        // Show verbose NB-IoT messages
    ```

## Testing Configuration

### `TEST_MINUTAL`

Enables per-minute data transmission instead of the standard 10-minute interval.

**Default value:**

```cpp
#define TEST_MINUTAL 1
```

**Options:**

- `1` - Enable 1-minute transmission interval (testing mode)
- `0` - Use standard 10-minute interval (production mode)

**Usage:**

This is extremely useful for:

- Testing data transmission without waiting 10 minutes
- Debugging server communication
- Validating sensor readings quickly
- Verifying JSON packet format

!!! warning "Testing Only"
    Always disable `TEST_MINUTAL` (set to `0`) for production deployments. Sending data every minute significantly increases:
    <!-- markdownlint-disable MD046 -->
    - Power consumption
    - Data costs
    - Server load
    - SIM card data usage

## Debug Macros

The debug system provides four macros that work like `printf()` with automatic formatting and module tagging.

### Available Macros

#### `DEBUG_ERROR(format, ...)`

Prints critical error messages. Always use for fatal errors that prevent normal operation.

**Example:**

```cpp
DEBUG_ERROR("Unable to establish communication with RTC");
DEBUG_ERROR("Sensor initialization failed with error code: %d", error_code);
```

**Output:**

```text
[ERROR][1543][RTC] Unable to establish communication with RTC
[ERROR][1544][SEN5X] Sensor initialization failed with error code: -1
```

#### `DEBUG_WARN(format, ...)`

Prints warning messages for non-critical issues that should be investigated.

**Example:**

```cpp
DEBUG_WARN("Temperature reading out of expected range: %.2f°C", temp);
DEBUG_WARN("Network registration took longer than expected");
```

**Output:**

```text
[WARN][5234][T6793] Temperature reading out of expected range: 45.23°C
[WARN][12456][NBIOT] Network registration took longer than expected
```

#### `DEBUG_INFO(format, ...)`

Prints informational messages about normal program flow and state changes.

**Example:**

```cpp
DEBUG_INFO("Sensor initialized successfully");
DEBUG_INFO("Connected to network, signal strength: %d", rssi);
```

**Output:**

```text
[INFO][3421][SEN5X] Sensor initialized successfully
[INFO][45678][NBIOT] Connected to network, signal strength: -72
```

#### `DEBUG_VERBOSE(format, ...)`

Prints detailed diagnostic information, typically sensor readings or low-level communication details.

**Example:**

```cpp
DEBUG_VERBOSE("PM2.5: %.2f, PM10: %.2f, VOC: %d", pm25, pm10, voc);
DEBUG_VERBOSE("AT command: %s, Response: %s", cmd, response);
```

**Output:**

```text
[VERBO][10234][SEN5X] PM2.5: 12.34, PM10: 23.45, VOC: 156
[VERBO][10456][NBIOT] AT command: AT+CGATT?, Response: +CGATT: 1
```

## Module Identification with DEBUG_TAG

Each source file (`.cpp`) defines its own `DEBUG_TAG` macro to identify the source of debug messages. This tag appears in the `[MODULE]` field of every debug message.

### How DEBUG_TAG Works

**At the beginning of each `.cpp` file, define:**

```cpp
#define DEBUG_TAG "MODULE_NAME"
```

**This tag is then automatically included in all debug messages from that file.**

### Standard DEBUG_TAG Definitions

| File | DEBUG_TAG | Description |
|------|-----------|-------------|
| `Alarma.cpp` | `"ALARMA"` | Timing and data acquisition loop |
| `SEN5X_API.cpp` | `"SEN5X"` | SEN54 sensor communication |
| `T6793_API.cpp` | `"T6793"` | CO₂ sensor communication |
| `DS3231M.cpp` | `"RTC"` | Real-time clock |
| `Transmision_NBIOT.cpp` | `"NBIOT"` | NB-IoT module |
| `firmware.ino` | `"MAIN"` | Main program setup |

### Example Implementation

**In `SEN5X_API.cpp`:**

```cpp
#include "Debug.h"

// Define module identifier for debug messages
#define DEBUG_TAG "SEN5X"

void sen5x_inicializar() {
  DEBUG_INFO("Initializing SEN54 sensor...");

  if (sen5x.begin(Wire) != 0) {
    DEBUG_ERROR("Failed to initialize sensor");
    return;
  }

  DEBUG_INFO("Sensor initialized successfully");
}

void sen5x_leer() {
  if (DEBUG_SEN5X >= 4) {
    DEBUG_VERBOSE("Reading sensor values...");
    DEBUG_VERBOSE("PM2.5: %.2f µg/m³", pm25);
    DEBUG_VERBOSE("PM10: %.2f µg/m³", pm10);
  }
}
```

**Output:**

```text
[INFO][2341][SEN5X] Initializing SEN54 sensor...
[INFO][2456][SEN5X] Sensor initialized successfully
[VERBO][5012][SEN5X] Reading sensor values...
[VERBO][5013][SEN5X] PM2.5: 12.34 µg/m³
[VERBO][5014][SEN5X] PM10: 23.45 µg/m³
```

!!! tip "Creating New Modules"
    When adding new source files to the firmware:
    <!-- markdownlint-disable MD046 -->
    1. Include `Debug.h` at the top
    2. Define a descriptive `DEBUG_TAG` (uppercase, max 8 characters recommended)
    3. Use debug macros throughout your code
    4. Optionally add a module-specific debug level in `Debug.h`

## Serial Monitor Configuration

To view debug messages, configure your serial monitor with the following settings:

**Baud rate:** `115200`

**Line ending:** `Newline` or `NL`

### Using Arduino IDE Serial Monitor

1. Open `Tools` → `Serial Monitor`
2. Set baud rate to `115200` in the bottom right
3. Set line ending to `Newline`

### Using Arduino CLI

```powershell
arduino-cli monitor -p COM3 -c baudrate=115200
```

## Practical Usage Examples

### Example 1: Production Configuration

Minimal debug output for deployed devices:

```cpp
#define TEST_MINUTAL 0      // 10-minute transmission
#define DEBUG_LEVEL 1       // Errors only
#define DEBUG_ALARMA 1
#define DEBUG_SEN5X 1
#define DEBUG_T6793 1
#define DEBUG_DS3231M 1
#define DEBUG_NBIOT 1
```

### Example 2: Development Configuration

Standard debugging during development:

```cpp
#define TEST_MINUTAL 1      // 1-minute transmission for testing
#define DEBUG_LEVEL 3       // Info level
#define DEBUG_ALARMA 3
#define DEBUG_SEN5X 3
#define DEBUG_T6793 3
#define DEBUG_DS3231M 2
#define DEBUG_NBIOT 3
```

### Example 3: Deep Sensor Debugging

Troubleshooting SEN54 sensor communication:

```cpp
#define TEST_MINUTAL 1      // Fast testing
#define DEBUG_LEVEL 4       // Verbose
#define DEBUG_ALARMA 2      // Reduce noise from timer
#define DEBUG_SEN5X 4       // Full sensor details
#define DEBUG_T6793 2
#define DEBUG_DS3231M 0     // Disable RTC messages
#define DEBUG_NBIOT 0       // Disable NB-IoT messages
```

### Example 4: NB-IoT Network Troubleshooting

Diagnosing connectivity issues:

```cpp
#define TEST_MINUTAL 1      // Test transmissions every minute
#define DEBUG_LEVEL 4       // Verbose
#define DEBUG_ALARMA 2
#define DEBUG_SEN5X 0       // Disable sensor messages
#define DEBUG_T6793 0
#define DEBUG_DS3231M 0
#define DEBUG_NBIOT 4       // Show all AT commands and responses
```

## Memory Considerations

### Flash Memory Impact

Debug strings are stored in flash memory. The approximate memory usage:

| Configuration | Flash Usage | Notes |
|---------------|-------------|-------|
| `DEBUG_LEVEL = 0` | ~0 bytes | All debug code removed |
| `DEBUG_LEVEL = 1` | ~2-4 KB | Error messages only |
| `DEBUG_LEVEL = 3` | ~6-10 KB | Standard debugging |
| `DEBUG_LEVEL = 4` | ~10-15 KB | Full verbose output |

### RAM Impact

The debug system uses a static buffer for formatting messages:

**Buffer size:** `256 bytes` (defined by `DEBUG_PRINTF_BUFFER_SIZE`)

!!! info "Buffer Overflow Prevention"
    Keep debug messages under 256 characters. Longer messages will be truncated. If you need longer messages, increase `DEBUG_PRINTF_BUFFER_SIZE` in `Debug.h`.

## Troubleshooting

### No Debug Output

**Possible causes:**

1. **Serial monitor not connected**: Ensure USB cable is connected and correct COM port selected
2. **Wrong baud rate**: Must be set to `115200`
3. **DEBUG_LEVEL = 0**: Debug output is disabled
4. **Module debug level = 0**: Specific module output is disabled

**Solution:**

```cpp
#define DEBUG_LEVEL 3       // Enable INFO level
#define DEBUG_ALARMA 3      // Enable module output
```

### Garbled Output

**Possible causes:**

1. **Incorrect baud rate**: Check serial monitor settings
2. **Buffer overrun**: Messages too long for buffer

**Solution:**

- Set baud rate to `115200`
- Shorten debug messages or increase `DEBUG_PRINTF_BUFFER_SIZE`

### Missing Timestamps

**Possible cause:** Serial monitor capturing partial messages

**Solution:** Reset the device to see messages from startup

### Memory Warnings During Compilation

**Possible cause:** Debug level too high, consuming too much flash memory

**Solution:** Reduce `DEBUG_LEVEL` or disable verbose modules

## Compilation Notes

### Preprocessor Optimization

The debug system uses preprocessor conditionals to completely eliminate debug code when disabled:

```cpp
#if DEBUG_LEVEL == 0
#define DEBUG_ERROR(format, ...)
#define DEBUG_WARN(format, ...)
#define DEBUG_INFO(format, ...)
#define DEBUG_VERBOSE(format, ...)
#endif
```

When `DEBUG_LEVEL = 0`, the macros expand to nothing, and the compiler's optimization pass removes all debug-related code, resulting in:

- Smaller binary size
- No runtime overhead
- No memory usage
- Faster execution

!!! success "Zero-Cost Abstraction"
    When debugging is disabled, there is literally **zero performance or memory cost** - it's as if the debug code never existed.

## Related Documentation

- [Firmware Configuration](firmware-configuration.md) - Configure device ID, server, and NB-IoT settings
- [API Reference](../firmware/files.md) - Complete firmware documentation
- [Hardware Assembly](assembly.md) - Physical device setup

## See Also

- **`Configuracion.h`** - Device configuration parameters
- **`Datetime_helper.h`** - Timezone configuration
- **Firmware API Documentation** - Complete code reference with Doxygen
