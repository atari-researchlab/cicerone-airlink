# Release v2.0.0 - First Public Release

## 🎉 Description

First stable release of **CICERONE AirLink**, an indoor air quality telemonitoring device with
NB-IoT for respiratory disease research.

## ✨ Main Features

### Hardware

- **Custom 2-layer PCB** (v57) with schematics and Gerber files
- **Integrated sensors**: SEN54 (PM/VOC), T6793-5K (CO₂), DS3231M (RTC)
- **Communication**: SIM7020G NB-IoT module for data transmission
- **Power**: 900mAh LiPo battery with 5-hour autonomy
- **Enclosure**: 3D model for printing (SOLIDWORKS/Fusion360)

### Firmware

- **Modular architecture** with non-blocking timers (5s and 10min)
- **Automatic transmission** of averages every 10 minutes via HTTP POST
- **Multi-level debug system** configurable per module
- **Conditional compilation** for memory optimization
- **Compatible** with Arduino Nano 33 BLE Sense Rev2

### Documentation

- **Complete website** with MkDocs Material + Doxygen
- **User guides**: assembly, firmware configuration, debugging
- **Technical documentation**: architecture, program flow, sensor interfaces
- **Auto-generated API** from source code comments
- **Dual language**: English (primary) and Spanish (firmware)

## 🔧 Contents

```text
├── firmware/          # Arduino code (English)
├── firmware_es/       # Arduino code (Spanish)
├── hardware/          # PCB, schematics and manufacturing files
│   ├── PCB/          # KiCad/Eagle, Gerber, assembly
│   └── Case/         # 3D models (STEP, Fusion360)
├── docs/             # MkDocs documentation
└── .github/          # CI/CD workflows
```

## 📦 Dependencies

**Firmware:**

- Arduino Core: `arduino:mbed_nano@4.4.1`
- ArduinoJson: `7.4.2`
- Sensirion I2C SEN5X: `0.3.0`
- Sensirion Core: `0.7.1`

**Documentation:**

- Python 3.8+
- mkdocs-material
- mkdoxy
- mkdocs-awesome-nav

## 🚀 Quick Start

### Compile Firmware

```bash
cd firmware
arduino-cli compile --profile nano33ble
arduino-cli upload --profile nano33ble -p COM3
```

### View Documentation

```bash
pip install mkdocs-material mkdoxy mkdocs-awesome-nav
mkdocs serve
```

Visit: <https://atari-researchlab.github.io/cicerone-airlink/>

## 🐛 Fixes in this Release

- ✅ Git LFS support in deployment workflow (assembly images)
- ✅ Fixed image paths in documentation
- ✅ Configuration of markdownlint and VSCode
- ✅ Correct exclusion of auto-generated files in mkdocs

## 📄 Licenses

- **Firmware**: GPL-3.0-or-later
- **Hardware**: CERN-OHL-S-2.0 (Open Hardware)
- **Documentation**: GFDL-1.3-or-later

## 🙏 Funding

Grant **PID2021-126810OB-I00** funded by MCIN/AEI and EU FEDER Funds.

<!-- markdownlint-disable MD041 MD013 -->

<p align="center">
  Grant <strong><em>PID2021-126810OB-I00</em></strong> funded by:<br />
  <img height="100" alt="Funded by Ministerio de Ciencia, Innovación y Universidades, European Union and Agencia Estatal de Investigacion" src="docs/img/micin-uefeder-aei.png" /><br />
</p>

---

**Project status**: Active | **Documentation**: <https://atari-researchlab.github.io/cicerone-airlink/>
