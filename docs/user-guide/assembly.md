---
title: Assembly instructions
subtitle:
description:
status:
icon: material/soldering-iron
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

![CICERONE Airlink explosionated 3D model with the case showing the distribution of the modules inside the enclosure][airlink-exploded]

Steps 1, 2, 3 and 4: Mount the components on the top face of the PCB, as shown.

![Assembly Diagram 1 - Components connected to the PCB][assembly1]

Step 5: Place the pins of the SEN54 sensor into the set of 4 female pins located next to the sensor
from step 2.

Step 6: Place the cable gland in the hole, as shown. To do this, you will have to open the inner
nut beforehand.

!!! bug
    Fix numeration to 6, 7 y 8.

![Assembly Diagram 2 - Placing the cable gland, securing the battery and communications module][assembly2]

Steps 7 and 8: Secure the LiPo battery and the M5Stack communications module to the base of the
casing. To secure the battery, you can use double-sided adhesive tape again.

Step 9: Place the PCB onto the casing's mounting surface that has 3 holes, as observed in the next
figure. During this process, you will need to take the following steps into account:

* First, connect the communications module's cable to the surface connector located on the underside
  of the PCB.
* Check that the battery cable passes through the rectangular cutout on the left side of the PCB.
* Check that the antenna cable passes through the space where the RTC is placed.

!!! bug
    Fix numeration to 9.

![Assembly Diagram 3 - Placing the PCB in the enclosure][assembly3]

Step 10: Assemble the two cables from the AC-DC Converter (charger) and the two cables from the
switch into a 4-pin female header connector, as shown.

!!! bug
    Missing image with the connector under the lipo-rider

Step 11: Place the standoff screw (bottom-left image) and 3 screws into the remaining holes to fix
the PCB to the casing.

!!! bug
    Fix numeration to 11, 12 y 13.

![Assembly Diagram 4 - Fixing the PCB to the enclosure][assembly4]

Step 12: Place the 4-pin connector from step 9 onto the set of 4 available male pins.

Step 13: Place the "LiPo Rider Plus" charge management module onto the set of 8 female pins. You
must take into account that the charge management module has a switch on the bottom that should be
left in the OFF state.

Step 14: Adhere the antenna to the inner face of the top part of the casing.

!!! bug
    Missing image with the antenna position.

Step 15: Slide the top part of the casing along the guides provided for this purpose. Be careful
not to pinch the antenna cable when closing the casing.

!!! bug
    Missing image with the device closed

[airlink-exploded]: ../img/airlink-exploded.png
[assembly1]: ../img/assembly/assembly-1.png
[assembly2]: ../img/assembly/assembly-2.png
[assembly3]: ../img/assembly/assembly-3.png
[assembly4]: ../img/assembly/assembly-4.png
