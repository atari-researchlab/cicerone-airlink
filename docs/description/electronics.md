---
title: Electronic design
subtitle:
description:
status:
icon: fontawesome/solid/microchip
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

The air quality device consists of a series of components, explained in following table, which shows
the main features of each one.

| Component | Model | Features |
| :---- | :---- | :---- |
| ![Arduino Nano 33 BLE Sense Rev 2 board][microcontroller] **Microcontroller Board** | Arduino Nano 33 BLE Sense Rev 2 | This board was chosen for its integrated microphone, low weight, and multiple sensors (color, proximity, motion, temperature, and humidity, among others). It allows for the connection of communication modules (via UART or I2C) to send real-time data to a server. |
| ![Seeed Studio Boost LiPo Rider Plus board][battery-charger] **Battery and power management** | Seeed Studio Boost LiPo Rider Plus | Power and autonomy management for the device from the Seeed Studio brand. It features a 1-cell (3.7V) LiPo battery input and a USB-C connector for 5V power supply. It allows simultaneous battery charging and device powering. It includes a DC-DC boost converter to step up the voltage to 5V, which is needed by other devices like the PM/VOCs sensor and the communication module. |
| ![Power Supply and LiPo Battery][ac-charger-lipo] **AC-DC Converter and battery** | 5V@1A Power Supply 900 mAh LiPo Battery | Extra components to provide power via a power supply and/or a battery. |
| ![DS3231 RTC module][rtc-module] **RTC Module** | DFR0641 DS3231M | It ensures reliable synchronization for data collection and for averaging every 10 minutes without accumulating delays. Obtained from the DFRobot brand, it was included because the microcontroller's internal RTC could not be implemented. |
| ![M5Stack U111 module][nb-iot-module] **NB-IoT Module** | M5Stack U111 | This component from M5Stack was selected for communication because NB-IoT technology offers the best nationwide coverage and can operate without an external access point, using the mobile provider's antennas instead. This type of technology is characterized as LPWA (Low-Power Wide-Area), consuming less power compared to others. This component includes the SIM7020G (SIMCOM) communication module. |
| ![Amphenol Telaire T6793-5K][co2-sensor] **CO2 Sensor** | Amphenol Telaire T6793-5K | This NDIR (Non-Dispersive Infrared) optical sensor from Amphenol Advanced Sensor was chosen for CO2 measurement. It has a precision of 400-5000 ppm ± 45 ppm, with a 5-second sampling interval. |
| ![Sensirio SEN54 sensor][pm-vocs-sensor] **PM and VOCs Sensor** | Sensirion SEN54 | This multisensor from the Sensirion brand is capable of measuring particulate matter (PM), volatile organic compounds (VOCs), temperature, and humidity. For PM measurement, it uses laser wavelength technology (DIN EN 60825-1 Class 1) with a concentration range of 0-1000 µg/m³ and can measure different sizes: PM1.0, PM2.5, PM4, and PM10. Regarding VOCs, it's based on metal oxide sensor technology, with a measurement range of 0-1000 ppm. |

The air quality device ultimately functions by sending all the parameters collected by the
different sensors every ten minutes, thanks to the communication module created in conjunction with
the RTC. This way, if there are no data transmission failures, a total of 144 daily data points are
obtained for each of the parameters collected by the CO2 and SEN54 sensors.

## Schematics

The figure shows the schematic design for connecting the device's various components, serving as
the basis for the necessary PCB design.

![CICERONE AirLink PCB Schematic][airlink-schematic]

Communication between the micro and the NB-IoT module is done via the UART protocol, using the Tx
and Rx pins. For the rest of the components (sensors and RTC), communication is performed via I2C.
Additionally, all components are powered with 5 volts. A pair of pins were also added to open the
power circuit to allow for physical control and to easily measure power consumption. Thus, the board
design includes traces on both the top and bottom for connecting the different components.

The connectors chosen for connecting the components to the PCB were male and female headers for all
components, except for the NB-IoT module, which used a female connector compatible with the one the
module already had. For this, the Grove Female Header HY2.0-4P, an SMD slide type, was selected to
connect the IoT module from the bottom of the board without taking up excessive space.

## PCB

The figure shows both sides of the PCB. On it, you can see a couple of cutouts that were made on the
board: one for the battery cable to pass through to the charging module (LiPo Rider Plus), and
another to place the RTC vertically (in an "L" shape) and meet the rest of the size limitations.

![CICERONE Airlink PCB final design][airlink-pcb]

In addition, several pads were added to the PCB, under the position of the charging module, to serve
as test points to check the board's functionality once assembled. A pin jumper was also added to
interrupt the power trace, allowing for a multimeter to be inserted to measure the device's
consumption.

The last set of pins to highlight is a group of 4, also placed under the charging module, whose
purpose is to enable the charging module. A two-position switch was added to this aspect to be able
to cut the power, in case it is not desired to function in any way. The power and GROUND input from
the AC/DC converter are added to two of these 4 pins, and the two wires from the switch are added to
the other two pins to interrupt the voltage path to enable the charging module.

Thus, the assembly of the PCB with the components is shown in the figure, observing that it has been
made with the minimum necessary dimensions to cover the parameters of the different components for
their correct functioning.

![CICERONE Airlink 3D model assembly of the PCB with all additional modules][airlink-3dmodel]

Finally, the set of components with the PCB is inserted inside a protective casing made with 3D
printing according to the necessary requirements, with special interest in the transit of air flow
and its ergonomics for the intended audience, in addition to those indicated by the different
components themselves.

[microcontroller]: ../img/arduino-nano-33-ble.png
[battery-charger]: ../img/boost-lipo-rider-plus.png
[ac-charger-lipo]: ../img/adaptador-ac-lipo.jpg
[rtc-module]: ../img/dfrobot-ds3231m.jpg
[nb-iot-module]: ../img/m5stack-nbiot-sim7020g.png
[co2-sensor]: ../img/amphenol-t6793-5k.png
[pm-vocs-sensor]: ../img/sensirion-sen54.png
[airlink-schematic]: ../img/airlink-schematic.png
[airlink-pcb]: ../img/airlink-pcb.jpg
[airlink-3dmodel]: ../img/airlink-3dmodel.png
