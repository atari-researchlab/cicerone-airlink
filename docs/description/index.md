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

# Device description


## 📝 Specifications

- Electronics
  - Microcontroller
    - Arduino Nano 33 BLE Sense Rev2
  - Sensors
    - PM/VOC
    - CO2
    - Temperature
    - Ambient relative humidity
  - I/O
    - Power switch
  - Comunication
    - NB-IoT module (SIM7020G)
  - Others
    - 2-layer custom PCB
    - RTC
    - 900mAh Lithium-ion battery
    - 5V@1A AC-DC adapter
- Mechanics
  - 3D-printed case
  - Developed in SOLIDWORKS® 2020
- Firmware
  - Sends the data to a server containing 10 minutes average measurements of all sensors via the NB-IoT module.
  - Developed in Arduino IDE