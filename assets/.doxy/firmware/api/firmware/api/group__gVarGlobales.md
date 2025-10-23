

# Group gVarGlobales



[**Modules**](modules.md) **>** [**gVarGlobales**](group__gVarGlobales.md)



[More...](#detailed-description)






















## Public Attributes

| Type | Name |
| ---: | :--- |
|  bool | [**alarma\_10min**](#variable-alarma_10min)   = `false`<br>_Set to 'true' when the 10-minute cycle is completed._  |
|  bool | [**alarma\_5s**](#variable-alarma_5s)   = `false`<br>_Set to 'true' when the 5-second cycle is completed._  |
|  float | [**avg\_hum**](#variable-avg_hum)   = `0.0f`<br>_Average of ambient humidity._  |
|  float | [**avg\_sen5x\_mc\_10p0**](#variable-avg_sen5x_mc_10p0)   = `0.0f`<br>_Average of SEN5X PM10.0._  |
|  float | [**avg\_sen5x\_mc\_1p0**](#variable-avg_sen5x_mc_1p0)   = `0.0f`<br>_Average of SEN5X PM1.0._  |
|  float | [**avg\_sen5x\_mc\_2p5**](#variable-avg_sen5x_mc_2p5)   = `0.0f`<br>_Average of SEN5X PM2.5._  |
|  float | [**avg\_sen5x\_mc\_4p0**](#variable-avg_sen5x_mc_4p0)   = `0.0f`<br>_Average of SEN5X PM4.0._  |
|  float | [**avg\_sen5x\_nox**](#variable-avg_sen5x_nox)   = `0.0f`<br>_Average of SEN55 NOx index._  |
|  float | [**avg\_sen5x\_voc**](#variable-avg_sen5x_voc)   = `0.0f`<br>_Average of SEN5X VOC index._  |
|  float | [**avg\_t6793\_co2**](#variable-avg_t6793_co2)   = `0.0f`<br>_Average of T6793 CO2._  |
|  float | [**avg\_temp**](#variable-avg_temp)   = `0.0f`<br>_Average of ambient temperature._  |
|  uint16\_t | [**cont1**](#variable-cont1)   = `0`<br>_Counter for averaging the first sensor groups._  |
|  uint16\_t | [**cont2**](#variable-cont2)   = `0`<br>_Counter for averaging the second sensor groups._  |
|  String | [**fecha**](#variable-fecha)  <br>_String to store current date (e.g., "YYYY-MM-DD")._  |
|  String | [**hora**](#variable-hora)  <br>_String to store current time (e.g., "HH:MM:SS")._  |
|  uint8\_t | [**minuto\_actual**](#variable-minuto_actual)  <br>_Stores the current minute read from RTC._  |
|  uint8\_t | [**minuto\_siguiente**](#variable-minuto_siguiente)  <br>_Calculates and stores the next minute when the alarm will trigger (e.g., 10, 20, 30...)._  |
|  [**DateTime**](classDateTime.md) | [**now**](#variable-now)  <br>_Structure to store current date and time._  |
|  unsigned long | [**prev\_millis**](#variable-prev_millis)  <br>_Stores the time of the last 5s alarm activation._  |
|  [**DS3231M**](classDS3231M.md) | [**rtc**](#variable-rtc)  <br>_RTC object instance._  |
|  float | [**sum\_hum**](#variable-sum_hum)   = `0.0f`<br>_Accumulator for ambient humidity._  |
|  float | [**sum\_sen5x\_mc\_10p0**](#variable-sum_sen5x_mc_10p0)   = `0.0f`<br>_Accumulator for SEN5X PM10.0._  |
|  float | [**sum\_sen5x\_mc\_1p0**](#variable-sum_sen5x_mc_1p0)   = `0.0f`<br>_Accumulator for SEN5X PM1.0._  |
|  float | [**sum\_sen5x\_mc\_2p5**](#variable-sum_sen5x_mc_2p5)   = `0.0f`<br>_Accumulator for SEN5X PM2.5._  |
|  float | [**sum\_sen5x\_mc\_4p0**](#variable-sum_sen5x_mc_4p0)   = `0.0f`<br>_Accumulator for SEN5X PM4.0._  |
|  float | [**sum\_sen5x\_nox**](#variable-sum_sen5x_nox)   = `0.0f`<br>_Accumulator for SEN55 NOx index._  |
|  float | [**sum\_sen5x\_voc**](#variable-sum_sen5x_voc)   = `0.0f`<br>_Accumulator for SEN5X VOC index._  |
|  float | [**sum\_t6793\_co2**](#variable-sum_t6793_co2)   = `0.0f`<br>_Accumulator for T6793 CO2._  |
|  float | [**sum\_temp**](#variable-sum_temp)   = `0.0f`<br>_Accumulator for ambient temperature._  |












































## Detailed Description


Definition and memory allocation of global variables used by other modules. 


    
## Public Attributes Documentation




### variable alarma\_10min 

_Set to 'true' when the 10-minute cycle is completed._ 
```
bool alarma_10min;
```




<hr>



### variable alarma\_5s 

_Set to 'true' when the 5-second cycle is completed._ 
```
bool alarma_5s;
```




<hr>



### variable avg\_hum 

_Average of ambient humidity._ 
```
float avg_hum;
```




<hr>



### variable avg\_sen5x\_mc\_10p0 

_Average of SEN5X PM10.0._ 
```
float avg_sen5x_mc_10p0;
```




<hr>



### variable avg\_sen5x\_mc\_1p0 

_Average of SEN5X PM1.0._ 
```
float avg_sen5x_mc_1p0;
```




<hr>



### variable avg\_sen5x\_mc\_2p5 

_Average of SEN5X PM2.5._ 
```
float avg_sen5x_mc_2p5;
```




<hr>



### variable avg\_sen5x\_mc\_4p0 

_Average of SEN5X PM4.0._ 
```
float avg_sen5x_mc_4p0;
```




<hr>



### variable avg\_sen5x\_nox 

_Average of SEN55 NOx index._ 
```
float avg_sen5x_nox;
```




<hr>



### variable avg\_sen5x\_voc 

_Average of SEN5X VOC index._ 
```
float avg_sen5x_voc;
```




<hr>



### variable avg\_t6793\_co2 

_Average of T6793 CO2._ 
```
float avg_t6793_co2;
```




<hr>



### variable avg\_temp 

_Average of ambient temperature._ 
```
float avg_temp;
```




<hr>



### variable cont1 

_Counter for averaging the first sensor groups._ 
```
uint16_t cont1;
```




<hr>



### variable cont2 

_Counter for averaging the second sensor groups._ 
```
uint16_t cont2;
```




<hr>



### variable fecha 

_String to store current date (e.g., "YYYY-MM-DD")._ 
```
String fecha;
```




<hr>



### variable hora 

_String to store current time (e.g., "HH:MM:SS")._ 
```
String hora;
```




<hr>



### variable minuto\_actual 

_Stores the current minute read from RTC._ 
```
uint8_t minuto_actual;
```




<hr>



### variable minuto\_siguiente 

_Calculates and stores the next minute when the alarm will trigger (e.g., 10, 20, 30...)._ 
```
uint8_t minuto_siguiente;
```




<hr>



### variable now 

_Structure to store current date and time._ 
```
DateTime now;
```




<hr>



### variable prev\_millis 

_Stores the time of the last 5s alarm activation._ 
```
unsigned long prev_millis;
```




<hr>



### variable rtc 

_RTC object instance._ 
```
DS3231M rtc;
```




<hr>



### variable sum\_hum 

_Accumulator for ambient humidity._ 
```
float sum_hum;
```




<hr>



### variable sum\_sen5x\_mc\_10p0 

_Accumulator for SEN5X PM10.0._ 
```
float sum_sen5x_mc_10p0;
```




<hr>



### variable sum\_sen5x\_mc\_1p0 

_Accumulator for SEN5X PM1.0._ 
```
float sum_sen5x_mc_1p0;
```




<hr>



### variable sum\_sen5x\_mc\_2p5 

_Accumulator for SEN5X PM2.5._ 
```
float sum_sen5x_mc_2p5;
```




<hr>



### variable sum\_sen5x\_mc\_4p0 

_Accumulator for SEN5X PM4.0._ 
```
float sum_sen5x_mc_4p0;
```




<hr>



### variable sum\_sen5x\_nox 

_Accumulator for SEN55 NOx index._ 
```
float sum_sen5x_nox;
```




<hr>



### variable sum\_sen5x\_voc 

_Accumulator for SEN5X VOC index._ 
```
float sum_sen5x_voc;
```




<hr>



### variable sum\_t6793\_co2 

_Accumulator for T6793 CO2._ 
```
float sum_t6793_co2;
```




<hr>



### variable sum\_temp 

_Accumulator for ambient temperature._ 
```
float sum_temp;
```




<hr>

------------------------------


