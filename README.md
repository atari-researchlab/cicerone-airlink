<!-- LICENSE INFORMATION
Copyright (C) 2025 ATARI Research Lab
Permission is granted to copy, distribute and/or modify this document
under the terms of the GNU Free Documentation License, Version 1.3
or any later version published by the Free Software Foundation;
with no Invariant Sections, no Front-Cover Texts, and no Back-Cover Texts.
A copy of the license is included in the section entitled "GNU
Free Documentation License". 
-->

<p align="center">
  Grant <strong><em>PID2021-126810OB-I00</em></strong> funded by:<br />
  <img height="100" title="Funded by Ministerio de Ciencia, Innovación y Universidades, European Union and Agencia Estatal de Investigacion" src="docs/img/micin-uefeder-aei.png" /><br />
</p>

<p align="center">
  <a href="https://www.youtube.com/channel/UC44JD74j4QEr4diN6-1qpBg" target="_blank"><img src="https://img.shields.io/static/v1?message=Youtube&logo=youtube&label=&color=FF0000&logoColor=white&labelColor=&style=for-the-badge" height="40" alt="youtube logo" /></a>
  <a href="https://www.instagram.com/grupoatari/" target="_blank"><img src="https://img.shields.io/static/v1?message=Instagram&logo=instagram&label=&color=E4405F&logoColor=white&labelColor=&style=for-the-badge" height="40" alt="instagram logo"  /></a>
  <a href="https://tic212.uca.es/" target="_blank"><img src="https://img.shields.io/static/v1?message=ATARI%20Group%20Website&label=&color=blue&labelColor=&style=for-the-badge" height="40" alt="WWW" /></a>
  <a href="https://atari-researchlab.github.io/cicerone-airlink/" target="_blank"><img src="https://img.shields.io/badge/Documentation-018EF5?logo=readme&logoColor=fff&style=for-the-badge" height="40" alt="Documentation" /></a>
</p>

* * *
<a name="top"></a>
<p align="center"><img height="150" title="CICERONE Logo" src="docs/img/cicerone-logo.png" /></p>
 
<div align="center"><img height="200" title="CICERONE AirLink" src="docs/img/airlink-final-device.png" /> </div>

<h1 align="center">CICERONE AirLink</h1>

CICERONE AirLink© is an indoor air quality telemonitoring device designed for the project CICERONE (*PID2021-126810OB-I00*).

The air quality device operates by transmitting data every ten minutes for all the parameters collected by the various sensors, thanks to the communication module created in conjunction with the RTC. This way, if there are no data transmission failures, a total of 144 daily data points are obtained for each of the parameters collected by the CO2 and PM/VOCs sensors.

## Table of Contents

- [Features](#-features)
- [Specifications](#-specifications)
- [Documentation](#-documentation)
- [Citations](#-citations)
- [Licences](#-licences)

## 🎓 Features

- Sensors for measuring particulate matter (PM1, PM2.5, PM4, and PM10), volatile organic compounds (VOCs), carbon dioxide (CO2), temperature, and relative humidity.
- Clock for synchronizing sensor data readings and configuring the data packets to be transmitted.
- Autonomous data transmission independent of the user via an NB-IoT communication module. The device includes its own SIM card for sending average sensor values every ten minutes.
- Energy autonomy of up to 5 hours of operation on a fully charged battery.
- Optional cough detection feature using a machine learning algorithm. The device can count the number of cough events within a desired time frame.

[Back to top](#top)

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

[Back to top](#top)

## 📚 Documentation

- [Documentation](https://atari-researchlab.github.io/cicerone-airlink/)
- [Description](https://atari-researchlab.github.io/cicerone-airlink/description/)
  - [Electronics](https://atari-researchlab.github.io/cicerone-airlink/description/electronics/)
  - [Firmware](https://atari-researchlab.github.io/cicerone-airlink/description/firmware/)
- [User guide](https://atari-researchlab.github.io/cicerone-airlink/user-guide/)
  - [Assembly](https://atari-researchlab.github.io/cicerone-airlink/user-guide/assembly/)
  - [Firmware customization](https://atari-researchlab.github.io/cicerone-airlink/user-guide/firmware-configuration/)

[Back to top](#top)

## 📑 Citations
Please consider citing our papers in your publications if the project helps your research.

#### IEEE
````
[1]D. Sanchez-Morillo, A. Lara-Doña, B. Priego-Torres, M. Morales-Gonzalez, F. Montoro-Ballesteros, and A. Leon-Jimenez, “Portable Oxygen Therapy: Is the 6-Minute Walking Test Overestimating the Actual Oxygen Needs?,” Journal of Clinical Medicine, vol. 9, no. 12, p. 4007, Dec. 2020, doi: 10.3390/jcm9124007.
````

#### BibTeX
````
@article{Sanchez-Morillo2020,
   author = {Daniel Sanchez-Morillo and Alejandro Lara-Doña and Blanca Priego-Torres and Maria Morales-Gonzalez and Francisca Montoro-Ballesteros and Antonio Leon-Jimenez},
   doi = {10.3390/jcm9124007},
   issn = {2077-0383},
   issue = {12},
   journal = {Journal of Clinical Medicine},
   keywords = {6-minute walk test,COPD,CT90,oximetry,oxygen therapy},
   month = {12},
   pages = {4007},
   title = {Portable Oxygen Therapy: Is the 6-Minute Walking Test Overestimating the Actual Oxygen Needs?},
   volume = {9},
   url = {https://www.mdpi.com/2077-0383/9/12/4007},
   year = {2020}
}
````

[Back to top](#top)

## 📃 Licences

All hardware materials and designs, firmware and documentation provided here are licenced under the following licenses:
- Hardware: <a href="/hardware/LICENSE.md" target="_blank"><img src="docs/img/_lic/oshw-logo-filled-color.svg" height="25" alt="Open Source Hardware Logo" /> CERN Open Hardware Licence Version 2 - Strongly Reciprocal</a>
- Firmware source code: <a href="firmware/LICENSE.md" target="_blank"><img src="docs/img/_lic/gplv3-or-later.svg" height="25" alt="GNU General Public License version 3 or later Logo" /> GNU General Public License version 3 or later</a>
- Documentation: <a href="/docs/LICENSE.md" target="_blank"><img src="docs/img/_lic/gfdl-logo.svg" height="25" alt="GNU Free Documentation License, Version 1.3 or later Logo" /> GNU Free Documentation License, Version 1.3 or later</a>

[Back to top](#top)
