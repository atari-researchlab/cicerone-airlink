---
title: Firmware configuration
subtitle:
description:
status:
icon: material/tune
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

## Overview

The `Configuracion.h` file centralizes all configurable parameters for the CICERONE AirLink
firmware. This allows you to customize the device behavior without modifying the core source code.
All configuration options are defined using preprocessor directives (`#define`).

!!! info "File Location"
    The configuration file is located at: `firmware/Configuracion.h`

## Configuration Parameters

### Device Identification

#### `ID_USUARIO`

Defines a unique identifier for this device. This ID is included in all data transmissions to
identify the source device on the server.

**Default value:**

```cpp
#define ID_USUARIO "AIRLINK_01"
```

**Usage:**

- Change this value to assign a unique name to each device in your deployment
- Use alphanumeric characters and underscores
- Keep it short but descriptive (e.g., "AIRLINK_ROOM_301", "AIRLINK_LAB_A")

**Example:**

```cpp
#define ID_USUARIO "AIRLINK_BEDROOM_02"
```

### NB-IoT Module Control

#### `HABILITAR_NBIOT`

Enables or disables the NB-IoT communication module. When disabled, the device will still collect
sensor data but will not transmit it to the server.

**Default value:**

```cpp
#define HABILITAR_NBIOT 1
```

**Options:**

- `1` - Enable NB-IoT transmission (default)
- `0` - Disable NB-IoT transmission

**Usage:**

- Set to `1` when you want to enable remote telemonitoring
- Set to `0` for testing, development, or standalone data logging without connectivity
- Disabling NB-IoT saves power and reduces operational costs

**Example (disabled):**

```cpp
#define HABILITAR_NBIOT 0
```

!!! tip "Power Saving"
    Disabling NB-IoT can significantly extend battery life if you only need local data logging via
    the serial monitor.

### Server Configuration

These parameters define where the device sends its data via HTTP POST requests.

#### `SERVIDOR_IP`

The server's IP address or domain name where data will be transmitted.

**Default value:**

```cpp
#define SERVIDOR_IP "http://direccion.servidor.com"
```

**Usage:**

- Replace with your actual server URL or IP address
- Include the protocol prefix (`http://` or `https://`)
- Do not include trailing slashes

**Examples:**

```cpp
#define SERVIDOR_IP "http://192.168.1.100"
#define SERVIDOR_IP "http://iot.mycompany.com"
#define SERVIDOR_IP "https://api.airquality.example.org"
```

#### `SERVIDOR_PUERTO`

The server port number for the HTTP connection.

**Default value:**

```cpp
#define SERVIDOR_PUERTO "64340"
```

**Usage:**

- Must be provided as a string (enclosed in quotes)
- Common values: `"80"` (HTTP), `"443"` (HTTPS), or custom ports
- Coordinate with your server administrator

**Examples:**

```cpp
#define SERVIDOR_PUERTO "80"      // Standard HTTP port
#define SERVIDOR_PUERTO "443"     // Standard HTTPS port
#define SERVIDOR_PUERTO "8080"    // Alternative HTTP port
```

#### `SERVIDOR_API`

The API endpoint path on the server that receives the data.

**Default value:**

```cpp
#define SERVIDOR_API "/aqindoor"
```

**Usage:**

- Define the relative path to your API endpoint
- Always start with a forward slash (`/`)
- Must match the endpoint configured on your server

**Examples:**

```cpp
#define SERVIDOR_API "/api/v1/airquality"
#define SERVIDOR_API "/data/sensors"
#define SERVIDOR_API "/receive"
```

!!! example "Complete Server URL"
    The device constructs the full URL by combining these parameters:
    <!-- markdownlint-disable MD046 -->
    ``` SERVIDOR_IP:SERVIDOR_PUERTO/SERVIDOR_API ```

    For example: `http://iot.mycompany.com:64340/aqindoor`

### Network Provider Configuration

#### `APN_NBIOT`

Access Point Name (APN) for the mobile network operator's data service.

**Default value:**

```cpp
#define APN_NBIOT "iot.1nce.net"
```

**Usage:**

- Contact your IoT SIM card provider for the correct APN
- Some providers work without an APN (use empty string `""`)
- This is crucial for establishing data connectivity

**Common APN Examples:**

| Provider | APN Value |
|----------|-----------|
| 1NCE | `"iot.1nce.net"` |
| ThingMobile | `"TM"` |
| Vodafone IoT | `"nb.iотgprs"` |
| No APN required | `""` |

**Example configurations:**

```cpp
#define APN_NBIOT "iot.1nce.net"  // 1NCE
#define APN_NBIOT "TM"            // ThingMobile
#define APN_NBIOT ""              // No APN required
```

!!! warning "Important"
    Using an incorrect APN will prevent the device from connecting to the internet. Always verify
    with your SIM card provider.

## Configuration Workflow

### Step-by-Step Guide

1. **Open the configuration file**

   Navigate to `firmware/Configuracion.h` in your code editor

2. **Set device identification**

   Assign a unique `ID_USUARIO` for each device

3. **Configure server details**

   Enter your server's IP address, port, and API endpoint

4. **Set network APN**

   Enter the APN provided by your IoT SIM card operator

5. **Enable/disable NB-IoT**

   Set `HABILITAR_NBIOT` based on your requirements

6. **Compile and upload**

   Build and flash the firmware to your device using Arduino CLI

### Example Configuration

Here's a complete example configuration for a typical deployment:

```cpp
#ifndef CONFIGURACION_H
#define CONFIGURACION_H

// Device identification
#define ID_USUARIO "AIRLINK_HOSPITAL_ROOM_305"

// Enable NB-IoT transmission
#define HABILITAR_NBIOT 1

// Server configuration
#define SERVIDOR_IP "http://iot.hospital.org"
#define SERVIDOR_PUERTO "443"
#define SERVIDOR_API "/api/v2/airquality/data"

// Network provider APN
#define APN_NBIOT "iot.1nce.net"

#endif  // CONFIGURACION_H
```

## Compilation Notes

!!! info "Preprocessor Directives"
    All configuration options use `#define` preprocessor directives. Changes take effect at compile
    time, so you must recompile and upload the firmware after modifying `Configuracion.h`.

### Conditional Compilation

The `HABILITAR_NBIOT` flag uses conditional compilation. When set to `0`, all NB-IoT related code
is excluded from the compiled binary, resulting in:

- Smaller program size
- Reduced memory usage
- Lower power consumption
- Faster startup time

This is implemented throughout the codebase using preprocessor conditionals:

```cpp
#if HABILITAR_NBIOT
    // NB-IoT code is included
    nbiot_enviar();
#endif
```

## Troubleshooting

### Connection Issues

If the device cannot connect to the server:

1. **Verify APN**: Ensure `APN_NBIOT` matches your provider's specification
2. **Check server URL**: Confirm `SERVIDOR_IP` is reachable from the internet
3. **Validate port**: Ensure `SERVIDOR_PUERTO` is not blocked by firewalls
4. **Test API endpoint**: Verify `SERVIDOR_API` accepts POST requests

### Debug Mode

For detailed troubleshooting information, enable debug output in `Debug.h`:

```cpp
#define DEBUG_LEVEL 3           // Set to 3 for verbose output
#define DEBUG_NBIOT 3           // Enable NB-IoT debug messages
```

Monitor the serial output (115200 baud) to see connection attempts and error messages.

## Related Documentation

- [Debug Configuration](debug-configuration.md) - Configure debug output levels
- [API Reference](../firmware/api/files.md) - Complete firmware documentation
- [Hardware Assembly](assembly.md) - Physical device setup

## See Also

- **`Debug.h`** - Configure debug output and testing modes
- **`Datetime_helper.h`** - Timezone and time synchronization settings
- **Firmware API Documentation** - Complete code reference with Doxygen
