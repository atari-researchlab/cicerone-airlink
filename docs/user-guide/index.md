---
title: User Guide
subtitle:
description: Complete guide for building, configuring, and deploying CICERONE AirLink devices
status:
icon: fontawesome/solid/user-gear
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

This user guide provides comprehensive instructions for assembling, configuring, and deploying
CICERONE AirLink indoor air quality monitoring devices. Whether you're building your first device
or customizing firmware parameters, you'll find detailed step-by-step guidance here.

## Getting Started

The deployment process consists of three main stages:

<div class="grid cards" markdown>

-   :material-soldering-iron: **[Hardware Assembly](assembly.md)**

    ---

    Learn how to assemble the PCB, connect sensors, and integrate all components into the custom
    enclosure. Includes detailed diagrams and step-by-step instructions.

    [:octicons-arrow-right-24: Assembly Instructions](assembly.md)

-   :material-tune: **[Firmware Configuration](firmware-configuration.md)**

    ---

    Configure device parameters through `Configuracion.h`: set device ID, NB-IoT credentials,
    server endpoints, and enable/disable modules.

    [:octicons-arrow-right-24: Configuration Guide](firmware-configuration.md)

-   :material-bug: **[Debug Configuration](debug-configuration.md)**

    ---

    Set up the debug system through `Debug.h`: control logging verbosity, enable per-module
    debugging, and optimize for production deployment.

    [:octicons-arrow-right-24: Debug System](debug-configuration.md)

</div>

## Quick Reference

!!! tip "Typical Workflow"
    1. **Build the hardware** following the [assembly instructions](assembly.md)
    2. **Configure the firmware** by editing [`Configuracion.h`](firmware-configuration.md) with
    your device ID and network settings
    3. **Set debug level** in [`Debug.h`](debug-configuration.md) (use `DEBUG_LEVEL 3` for testing,
    `0` for production)
    4. **Compile and upload** the firmware to your Arduino Nano 33 BLE Sense Rev2
    5. **Validate operation** using the serial monitor with debug output enabled

## Additional Resources

- **[Firmware Architecture](../firmware/index.md)**: Understand the internal architecture, timer system, and data flow
- **[Hardware Description](../description/electronics.md)**: Detailed PCB design and electronic components
- **[Enclosure Design](../description/enclosure.md)**: 3D model specifications and mechanical integration

---

!!! question "Need Help?"
    If you encounter issues during assembly or configuration, check the
    [firmware architecture documentation](../firmware/index.md) for troubleshooting guidance.
