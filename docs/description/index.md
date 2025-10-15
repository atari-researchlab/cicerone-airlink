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

The device is inside a 3d printed enclosure. It is designed as simple as possible to cover the needs requested by the different components and with the absence of sharp edges to avoid discomfort in the use and placement of the device.

## Main features

* **Air quality sensors** for measuring particulate matter (PM1, PM2.5, PM4, and PM10), volatile organic compounds (VOCs), carbon dioxide (CO2), temperature, and relative humidity.
* **Real Time Clock** for synchronizing sensor data readings and configuring the data packets to be transmitted.
* **Autonomous data transmission** independent of the user via a communication module with NB-IoT technology. The device contains its own SIM card for sending average sensor values every ten minutes.
* **Battery backup** of up to 5 hours of operation on a fully charged battery.

## Specifications

* Electronics
    * Microcontroller
        * Arduino Nano 33 BLE Sense Rev2
    * Sensors
        * PM/VOC
        * CO2
        * Temperature
        * Ambient relative humidity
    * I/O
        * Power switch
    * Comunication
        * NB-IoT module (SIM7020G)
    * Others
        * 2-layer custom PCB
        * RTC
        * 900mAh Lithium-ion battery
        * 5V@1A AC-DC adapter
* Enclosure
    * Designed for manufacturing in a 3D printer
    * Designed in SOLIDWORKS® 2020
* Firmware
    * Sends the data to a server containing 10 minutes average measurements of all sensors via the NB-IoT module
    * Developed in Arduino IDE. Compatible with Visual Studio Code

[airlink-final]: ../img/airlink-final-device.png
