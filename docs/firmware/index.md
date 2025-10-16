---
title: Firmware Overview
subtitle:
description: Comprehensive firmware documentation for CICERONE AirLink
status:
icon: octicons/file-code-16
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

<!-- markdownlint-disable MD033 MD030 -->

## Welcome

The CICERONE AirLink firmware is an embedded system designed for continuous indoor air quality
monitoring with remote telemonitoring capabilities. Built on the Arduino framework for the
**Nano 33 BLE Sense Rev2**, it implements a non-blocking, timer-based architecture that ensures
reliable data collection and transmission.

## Key Features

<div class="grid cards" markdown>

-   :material-timer: **Non-Blocking Architecture**

    ---

    Dual-timer system with 5-second sensor sampling and 10-minute data averaging cycles.

-   :material-gauge: **Multi-Sensor Integration**

    ---

    SEN54 (PM/VOC), T6793-5K (CO₂), and DS3231M RTC for comprehensive air quality monitoring.

-   :material-antenna: **NB-IoT Connectivity**

    ---

    Optional wireless data transmission via SIM7020G module with HTTP POST.

-   :material-puzzle: **Modular Design**

    ---

    Clean separation of concerns with dedicated APIs for each component.

-   :material-bug-check: **Debug System**

    ---

    Multi-level logging framework with per-module configuration.

-   :material-memory: **Memory Efficient**

    ---

    Static allocation, minimal dynamic strings, optimized for long-term deployment.

</div>

## Documentation Sections

### :material-sitemap: [Architecture](architecture.md)

Learn about the system architecture, modular component structure, data flow pipeline, and memory
management strategies.

**Topics covered**:

- Non-blocking timer system (5s and 10min)
- Module organization and dependencies
- Data accumulation and averaging
- Conditional compilation for feature control

[:octicons-arrow-right-24: Read Architecture Documentation](architecture.md)

---

### :material-chart-timeline-variant: [Program Flow](program-flow.md)

Understand the detailed execution flow from device startup through continuous operation.

**Topics covered**:

- Setup phase initialization sequence
- Main loop structure and timing
- 5-second data acquisition cycle
- 10-minute averaging and transmission cycle

[:octicons-arrow-right-24: Read Program Flow Documentation](program-flow.md)

---

### :material-chip: [Sensor Interfaces](sensor-interfaces.md)

Explore sensor communication protocols, specifications, and calibration procedures.

**Topics covered**:

- SEN54 particulate matter and VOC sensor
- T6793-5K CO₂ sensor with ABC algorithm
- DS3231M real-time clock with battery backup
- I2C bus configuration and troubleshooting

[:octicons-arrow-right-24: Read Sensor Documentation](sensor-interfaces.md)

---

### :material-cloud-upload: [Data Transmission](data-transmission.md)

Discover how data is formatted and transmitted via NB-IoT cellular connectivity.

**Topics covered**:

- JSON packet format and generation
- NB-IoT communication protocol (SIM7020G)
- AT command sequences
- Power consumption optimization

[:octicons-arrow-right-24: Read Transmission Documentation](data-transmission.md)

---

## Quick Start

### Building and Uploading

```powershell
# Compile firmware
arduino-cli compile --profile nano33ble --build-path firmware/build firmware/

# Upload to board
arduino-cli upload --profile nano33ble --input-dir firmware/build

# Monitor serial output
arduino-cli monitor -p COM3 -c baudrate=115200
```

See the [project README](https://github.com/atari-researchlab/cicerone-airlink) for detailed
build instructions.

### Configuration

Before uploading, configure the device in `firmware/Configuracion.h`:

```cpp
#define ID_USUARIO "AIRLINK_01"              // Device ID
#define HABILITAR_NBIOT 1                     // Enable NB-IoT
#define SERVIDOR_IP "http://example.com"      // Server URL
#define APN_NBIOT "iot.1nce.net"              // Network APN
```

See [Firmware Configuration Guide](../user-guide/firmware-configuration.md) for detailed
configuration options.

### Debug Output

Enable debug output in `firmware/Debug.h`:

```cpp
#define DEBUG_LEVEL 3        // 0-4 (0=disabled, 3=recommended)
#define DEBUG_SEN5X 3        // Per-module debug levels
#define DEBUG_NBIOT 3
```

See [Debug Configuration Guide](../user-guide/debug-configuration.md) for debugging options.

---

## Technical Specifications

| Parameter | Value | Notes |
|-----------|-------|-------|
| **Platform** | Arduino Mbed OS Nano | Nano 33 BLE Sense Rev2 |
| **Language** | C/C++ | Arduino framework |
| **Compiler** | GCC ARM | Via Arduino CLI |
| **Flash Memory** | ~100-150 KB | Depends on enabled modules |
| **RAM Usage** | ~20-30 KB | Dynamic allocation minimal |
| **Sampling Rate** | 5 seconds | Configurable in code |
| **Averaging Period** | 10 minutes | 120 samples per average |
| **Transmission Interval** | 10 minutes | 144 transmissions/day |
| **Power Consumption** | ~120-180 mA | Average (5V input) |
| **Battery Life** | ~5 hours | With 900 mAh battery + NB-IoT |

---

## API Reference

Complete API documentation is available through Doxygen-generated references:

:material-book-open-variant: **[API Documentation](api/files.md)** - Generated from `firmware/`
source code

The API documentation includes:

- Function prototypes and parameters
- Variable definitions and usage
- Module dependencies
- Code examples
- Implementation notes

---

## Additional Resources

### Configuration Guides

- :material-tune: [Firmware Configuration](../user-guide/firmware-configuration.md) - Configure
   device settings
- :material-bug: [Debug Configuration](../user-guide/debug-configuration.md) - Debug system setup

### Hardware Documentation

- :material-chip: [Hardware Description](../description/electronics.md) - PCB design and electronics
- :material-cube-outline: [Enclosure Design](../description/enclosure.md) - 3D model and assembly
- :material-tools: [Assembly Guide](../user-guide/assembly.md) - Physical device assembly

### Project Resources

- :fontawesome-brands-github: [Source Code Repository](https://github.com/atari-researchlab/cicerone-airlink)
- :material-file-document: [Project Documentation](https://atari-researchlab.github.io/cicerone-airlink/)
- :material-email: [Contact & Support](mailto:gruboibt@uca.es)

---

## License

The firmware is licensed under the **GNU General Public License v3.0 or later**.

See [LICENSE.md](https://github.com/atari-researchlab/cicerone-airlink/blob/main/firmware/LICENSE.md)
for full license text.
