# iotFinalArduino

In this project we connected an arduino to Microsoft Azure.

This project was inspired by Thomas Conté's Blog : [Link](http://hypernephelist.com/2014/07/11/arduino-uno-azure-mobile-services.html "blog")

![Arduino](http://s24.postimg.org/gc5nrzjnp/image_3.jpg)

## The Code

Change the following lines in the .ino file :

```
byte mac[] = { 0xDC, 0xAB, 0xBA, 0xE9, 0xF8, 0x7D };
const char *server = "arduino-uno-test.azure-mobile.net";
const char *ams_key = "FTlCxxxxxxWaEtRxxxxxiMDmxxxx4";
```

* "mac" is your mac address, you could have to change it
* "server" is the address of your Microsoft Azure Mobile Service
* "ams_key" is the key to read and write on your Azure Mobile Service

## Hardware

In the following lines I describe how to assemble your Arduino's boards and sensors in order to work propaly with the .ino file.


You will need the following elements :
* Arduino Uno
* Arduino Ethernet Shield
* Grove - Starter Kit for Arduino

### Assemble
Put the Grove Base Shield above the Arduino Uno.
Connect the following sensors to the Base Shiled:
* Connect the "Temperture Sensor" to the port "A0"
* Connect the "Sound Sensor" to the port "A1"
* Connect the "Light Sensor" to the port "A2"
* Connect a "Led" to the port "D3"

![Arduino](http://s30.postimg.org/asbu9e09t/image_1.jpg)
![Arduino](http://s2.postimg.org/ga3tabiqh/image.jpg)


Finally, put the Arduino Ethernet Shield above the Grove Base Shield.
You should now have the three boards stack together and three sensors connected to the base shield in the middle.

## Usage

Once every steps done your mobile service will fill a database every second with the datas recieve from the sensors.




*Antoine Deloume, Victor Solevic, Alexandre Ghiazza.*