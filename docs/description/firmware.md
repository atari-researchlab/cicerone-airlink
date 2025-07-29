---
title: Firmware
subtitle: 
description: 
status: 
icon: octicons/file-code-16
---

# Firmware

Funcionamiento general

``` mermaid
stateDiagram-v2
    direction LR
    [*] --> Setup
    Setup --> Loop

    state Setup {
        state if_nbiot <<choice>>

        [*] --> rtc_init
        rtc_init --> t6793_init
        t6793_init --> sen5x_init
        sen5x_init --> if_nbiot

        if_nbiot --> nbiot_init: Sí
        nbiot_init --> [*]
        if_nbiot --> [*]: No

        if_nbiot: ¿Habilitar NB-IoT?
        rtc_init: Inicializa el RTC y las alarmas periódicas
        t6793_init: Inicializa el sensor T6793
        sen5x_init: Inicializa el sensor SEN5X
        nbiot_init: Inicializa el módulo NB-IoT
    }

    state Loop {
        state if_alarma_5s <<choice>>
        state if_alarma_10min <<choice>>
        state if_nbiot2 <<choice>>

        [*] --> check_alarma_5s
        check_alarma_5s --> if_alarma_5s
        
        if_alarma_5s --> if_alarma_10min: No
        if_alarma_5s --> acumular_datos: Sí
        acumular_datos --> reset_alarma_5s
        reset_alarma_5s --> check_alarma_10min

        check_alarma_10min --> if_alarma_10min

        if_alarma_10min --> [*]: No
        if_alarma_10min --> promediar_datos: Sí
        promediar_datos --> if_nbiot2
        if_nbiot2 --> reset_alarma_10min: No
        if_nbiot2 --> nbiot_enviar: Sí
        nbiot_enviar --> reset_alarma_10min
        reset_alarma_10min --> [*]

        check_alarma_5s: Comprueba si han pasado 5 segundos
        check_alarma_10min: Comprueba si han pasado 10 minutos
        if_alarma_5s: ¿Bandera de 5 segundos está activa?
        acumular_datos: Acumula los datos leídos por los sensores
        reset_alarma_5s: Reinicia la bandera de 5 segundos
        if_alarma_10min: ¿Bandera de 10 minutos activa?
        promediar_datos: Calcula el promedio de las lecturas acumuladas
        if_nbiot2: ¿Habilitar NB-IoT?
        nbiot_enviar: Transmite los datos promediados
        reset_alarma_10min: Reinicia la bandera de 10 minutos
    }
```