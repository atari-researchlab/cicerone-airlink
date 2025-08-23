---
title: Enclosure design
subtitle: 
description: 
status: 
icon: material/developer-board
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

For the enclosure design, SOLIDWORKS 2020 was used for modeling and Creality Print for preparing the print file, with the printing being carried out on a Sigmax R19 3D printer. To arrange the elements inside the enclosure, the specifications of the components were reviewed, with the SEN54 sensor presenting the most restrictions. Among others, it is necessary to place both heat sources (battery) and data transmission sources (antenna) as far as possible from the sensors. In addition, the different necessary gap requirements for the sensor to function correctly in relation to air intake and output, as well as the side vents, were taken into account. This enclosure is formed by a perforated pattern to allow air to pass through the device.

To make a more compact enclosure, an internal two-level structure was arranged, whose separation is given by the manufactured PCB for the prototype, which is screwed to the base of the enclosure. As shown in the figure, in the area below the PCB, separated by 2 mm, the device's battery is placed along with the NB-IoT transmission module, both being held to prevent movement and possible failure. Above the PCB are both sensors, in addition to the microcontroller board, charge manager, and RTC, all connected to the PCB that acts as a base. The placement of all of them has been following the specific indications mentioned above, to avoid failures during the operation of the sensors, as well as data transmission or the functioning of the entire device.

![CICERONE Airlink explosionated 3D model with the case showing the distribution of the modules][airlink-exploded2]

In this way, the organization of the different components allows it to be in a more reduced space and, therefore, be a manageable device for the user for its use and placement on a surface. It should be noted that on the back of the device, there is the outlet for the power supply, in addition to a switch for turning on the device.

[airlink-exploded2]: ../img/airlink-exploded2.png
