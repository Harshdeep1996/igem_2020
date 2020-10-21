# iGEM 2020 - EPFL team's Github
This repository has the necessary code, CAD and circuit files in order to build your own ExpressEAU.

### Project Abstract

Water is an essential resource that we regularly use for drinking, cooking and food processing. Hence, it is important to ensure that it is safe for consumption. EspressEAU serves as an analysis of general water quality. We aimed to create a safe, low-cost, and easy-to-use system that can enable on-site testing of water at home or in small communities. We hypothesized that genetically engineered yeast could be used as biosentinels by hijacking the yeast stress response pathway using either deletion strains or fluorescent reporter strains that are sensitive to water contaminants. These biosentinels are grown in a DIY system with temperature control, stirring, and two optical detectors for fluorescence and density, allowing us to monitor growth and fluorescence of the yeast, and thus detect the presence of contaminants in the water sample. We hope our project will facilitate frequent water testing of local water sources.

### Software used

1. Tinkercad: Used to make the CAD designs for 3D print, using `STL` files (https://www.tinkercad.com/)
2. Circuit Diagram: Used to make circuit schematics using an online IDE (https://www.circuit-diagram.org/)
3. PRUSA 3D Slicer: Used to generate the G Code and the sliced version of the 3D element (https://www.prusa3d.com/drivers/)
4. Processing: Used to interface between the Arduino Serial Interface and to collect data on the host machine (https://processing.org/)

### Hardware Components used

#### Microcontroller: Arduino Uno
<img src="https://store-cdn.arduino.cc/usa/catalog/product/cache/1/image/500x375/f8876a31b63532bbba4e781c30024a0a/a/0/a000066_front_8.jpg" alt="Arduino_Uno" width="200"/>

[Source](https://www.arduino.cc/en/Guide/ArduinoUno)


### Cable: USB for data transfer
<img src="https://images-na.ssl-images-amazon.com/images/I/41PIihh3qnL._AC_.jpg" alt="USB cable" width="200"/>

[Datasheet](https://www.arduino.cc/documents/datasheets/USBcable.PDF)\
[Source](https://store.arduino.cc/usb-2-0-cable-type-a-b?queryID=aa479172c324b5d009057f23eaddd86c)


#### Temperature Sensor: TMP36
<img src="https://electropeak.com/pub/media/catalog/product/cache/10f519365b01716ddb90abc57de5a837/t/m/tmp36-temperature-sensor1.jpg" alt="TMP36" width="200"/>

[Datasheet](https://www.analog.com/en/products/tmp36.html)
[Source](https://learn.adafruit.com/tmp36-temperature-sensor)


#### Light to Frequency Sensor: TSL235R (primarily for optical density measurement)
<img src="https://cdn.sparkfun.com//assets/parts/3/7/4/0/09768-01.jpg" alt="light_to_frequency" width="200"/>

[Datasheet](https://www.sparkfun.com/datasheets/Sensors/Imaging/TSL235R-LF.pdf)\
[Source](https://www.sparkfun.com/products/9768)


#### RGB Light Sensor: ISL9125 (primarily for fluorescence measurement)
<img src="https://cdn.sparkfun.com//assets/parts/9/6/7/7/12829-01.jpg" alt="TMP36" width="200"/>

[Datasheet](https://cdn.sparkfun.com/datasheets/Sensors/LightImaging/isl29125.pdf)\
[Source](https://www.sparkfun.com/products/12829)


#### OEM Temperature sensor: DS18B20 (for calibration and check of TMP36 sensor)
<img src="https://static.digitecgalaxus.ch/Files/1/2/8/2/6/0/6/7/dsbicdigi-1388370334-18330.jpg?impolicy=ProductTileImage&resizeWidth=436&resizeHeight=335&quality=high&cropWidth=436&cropHeight=335" alt="DS18B20" width="200"/>

[Datasheet](https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf)\
[Source](https://www.digitec.ch/de/s1/product/oem-ds18b20-sensor-elektronikmodul-8030174)


#### Power Supply 9V, 1.5A (Variable): Goobay 3 V - 12 V universal power supply 1.5A
<img src="https://static.digitecgalaxus.ch/Files/2/6/9/4/5/2/5/6/53997_neu_2018-07_1280x720.jpg?impolicy=ProductTileImage&resizeWidth=436&resizeHeight=335&quality=high&cropWidth=436&cropHeight=335" alt="TMP36" width="200"/>

[Source](https://www.digitec.ch/de/s1/product/goobay-3-v-12-v-universal-netzteil-15a-universalladegeraet-11511239)


#### Thermoelectric Peltier Element: TEC1-12706
<img src="https://protosupplies.com/wp-content/uploads/2018/12/TEC1-12706-Peltier-Cooler.jpg" alt="TEC1-12706" width="200"/>

[Datasheet](https://peltiermodules.com/peltier.datasheet/TEC1-12706.pdf)\
[Source](https://protosupplies.com/product/tec1-12706-thermoelectric-peltier-cooling-device/)


#### IRF520 Mosfet Transistor
<img src="https://images-na.ssl-images-amazon.com/images/I/31xj4GtNP2L._SR600%2C315_PIWhiteStrip%2CBottomLeft%2C0%2C35_SCLZZZZZZZ_.jpg" alt="ESC" width="200"/>

[Datasheet](https://www.vishay.com/docs/91017/91017.pdf)\
[Source](https://www.aliexpress.com/)


#### DC Motor (working with 6V or 9V - 9V is generally more consistent)

<img src="https://cdn.sparkfun.com//assets/parts/7/8/6/0/11696-01.jpg" alt="DCMotor_" width="200"/>

[Datasheet](https://www.arduino.cc/documents/datasheets/DCmotor.PDF)\
[Source](https://aliexpress.com)

#### Pack of LEDs - white LED and Orange LED (with wave length between 530-560 nm for fluorescence measurement) 
#### Battery 9V
#### Jumper wires (types: Male-Female, Female-Female, Male-Male)
#### Soldering iron with tin
#### Glue gun (with glue sticks)


