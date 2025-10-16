---
title: Device description
subtitle:
description:
status:
icon: material/list-box-outline
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

![CICERONE Airlink final design][airlink-final]

## Overview

The CICERONE AirLink firmware is a embedded system designed for continuous indoor air quality
monitoring with remote telemonitoring capabilities. Built on the Arduino framework for the **Nano 33
BLE Sense Rev2**, the firmware implements a non-blocking, timer-based architecture that ensures
reliable data collection and transmission.

### Key Features

- **Multi-Sensor Integration**: Seamlessly interfaces with SEN54 (particulate matter & VOC) and T6793-5K (CO₂) sensors
- **Periodic Data Acquisition**: Sensor readings every 5 seconds with 10-minute averaging cycles (144 data points per day)
- **NB-IoT Connectivity**: Optional wireless data transmission via SIM7020G module
- **Real-Time Clock**: Accurate timestamping using DS3231M RTC with battery backup
- **Modular Design**: Clean separation of concerns with dedicated APIs for each component
- **Debug System**: Multi-level logging framework for development and troubleshooting
- **Low Power**: Optimized for battery-powered deployment scenarios
- **Production Ready**: Conditional compilation eliminates unused code for minimal footprint

### Technical Specifications

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

[airlink-final]: ../img/airlink-final-device.png
