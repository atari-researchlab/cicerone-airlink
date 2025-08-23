---
title: Additional information
subtitle: 
description: 
status: 
icon: material/information-variant
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

## Energy Consumption

!!! bug
    Indicate that the current consumption could be measured via de pin header available in the PCB

The device's power consumption is calculated by summing the electrical consumption of all components, including the maximum peak current. The table shows a summary of the energy consumption involved in the device's operation.

| Name | Max Peak Current (Max) | AVG. Supply Current (typ) |
| :---- | :---- | :---- |
| 1. Sensor SEN54 | 110 mA | 63 mA |
| 2. Sensor T6793-5K | 200 mA | 20 mA |
| 3. Arduino Nano 33 BLE Sense Rev2 | - | 20 mA |
| 4. DFR0641 RTC DS3231M | - | 0.13 mA |
| 5. U111 M5Stack | 700 mA | 5.6 mA |
| **Total** |  | **108.73 mA** |

/// table-caption |<
Modules current consumption and global current
///

The consumption calculated in Table 2 must include the losses caused by the LiPo Rider Plus module's 3.7V to 5V DC-DC converter, which has an efficiency of around 83%. This results in a total consumption of 131mA. On the other hand, since the selected battery has a capacity of 900mAh, it's possible to determine the device's autonomy with a simple calculation. The result is approximately 6 hours of operation without a mains connection.

Another aspect to consider is the NB-IoT module, which has a maximum consumption of 700mA during transmission. Since the device sends a packet every 10 minutes, the average consumption (on the order of a few milliamps) is negligible. The rest of the time when it's not transmitting, it has a residual consumption below one milliamp. However, it is important to know the device's peak consumption to determine the minimum power supply rating. In this regard, the maximum consumption will occur during transmission. Therefore, you would add the NB-IoT module's consumption (700mA) to the consumption calculated in the table (108.73mA) and apply the DC-DC converter's efficiency factor (83%), resulting in a total of 974 mA. This consumption value is momentary (lasting for a few seconds during the transmission period) and was calculated by taking limit values at each step. Therefore, the minimum power supply can be considered to be able to supply 1 ampere of current.

## **Estimated Unit Cost**

The following table shows the different components included in the final device, along with the vendor name, reference, and cost from the vendor's website. It's important to note that the unit cost included is for orders of more than 25 units per component.

!!! bug "Deprecated"
    **Update to BOM file or reference it**

| Name | Vendor | Reference | Unit Cost |
| :---- | :---- | :---- | :---- |
| 1. Sensor SEN54 | Mouser Electronics | 403-SEN54-SDN-T | 19.36 € |
| 2. Sensor T6793-5K | Mouser Electronics | 527-T6793-5K | 25.84 € |
| 3. Arduino Nano 33 BLE Sense Rev2 | Arduino Store | ABX00069 | 30.57 € |
| 4. DFRobot RTC DS3231M | Mouser Electronics | 426-DFR0641 | 6.43 € |
| 5. U111 M5Stack | Mouser Electronics | 170-U111 | 21.30 € |
| 6. SeeedStudio LiPo Rider Plus | Mouser Electronics | 713-106990290 | 4.59 € |
| 7. Antenna | Mouser Electronics | 538-146185-0300 | 2.98 € |
| 8. 5V@1A Power Supply | Mouser Electronics | 552-AA10E-050A(M)-R | 6.00 € |
| 9. 3.7V 900mAh Battery | BricoGeek | 603048 | 5.95 € |
| 10. PCB | Eurocircuits |  | 5.00 € |
| 11. Enclosure | Impresoras3D | 1.75mm and 1kg Filament | 1.77 € |
| 12. 3D Printing Energy Cost |  |  | 0.80 € |
| **Subtotal** |  |  | **130.59 €** |

/// table-caption |<
Estimated budget for the final device (unit prices are based on an order of 25 devices as of June 2024).
///

To calculate the cost of the enclosure, the weight of the material used for 3D printing was accounted for. A total of 103.40 grams of rigid 1.75mm diameter PETG filament from the i3D Tested brand was used for each enclosure. The price of this filament is €17.11 for a 1-kilogram roll. Therefore, by using a rule of three, the unit cost shown in the Table is easily obtained. It's worth mentioning that the energy consumption and wear and tear of the 3D printing equipment have not been taken into account for the calculation.

Another standard measure for calculating cost is the electrical energy used by the 3D printer. On average, a 3D printer takes 10 to 15 hours to print 103.40g of material at a standard speed of 55-60mm/s. Considering the price of €0.2136 per kWh in the city of Cádiz, Andalusia, and a typical 3D printer consumption of 0.25 kW, the calculation can be done by simply multiplying these factors. Assuming the case of highest consumption (15 hours), the total cost would be:

$$
0.25kW \times 15h \times 0.2136 \frac{\unicode{0x20AC}}{kW h} = 0.801 \unicode{0x20AC}
$$
