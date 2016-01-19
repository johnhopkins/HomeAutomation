# HomeAutomation
A home automation project allowing control of lighting, heating and other appliances around the home with various sensors and actuators.

## Temperature Sensor
This code was taken from http://bildr.org/2011/07/ds18b20-arduino/ and adapted to suit. It is an arduino sketch that with some very basic wiring and a DS18B20 temperature chip will measure the temperature in that location and feed the data serially via the usb cable to be read by the serial reader.

## TRV
There are several wireless thermostatic radiator valves on the market. Some research is required as to which ones are open or the easiest to hack. Current favourite is the Energeneie range due to the fact they offer raspberry pi connectivity.

## Light Switch

Control for lighting in and around the home with a simple on off protocol, will be added here.

## Socket Switch

Control of sockets with a simple on off protocol, will be added here.

## Other appliances and Sensors

PIR's, proximity and geo location capabilities will go under this heading.

# Gateway

The gateway will act as a server for the web interface, and will drive all the wireless modules so needs to act as both reciever and transmitter. All data recieved will be passed to the server for processing. All commands to controllable sensors and actuators will be sent form the gateway.

## Serial Reader
This is a simple python module that reads the serial data from the usb port (or any port specified). It then parses the serial data and stores the information in the mongo database.

## Boiler Control
This very simply turns on and off the boiler via RF. The file is an arduino sketch which requires a 433MHz transmitter set up. I aim to add the schematics for this soon. N.B. This sketch works on my home boiler a Worcester Bosch Greenstar 30CDi combi boiler. I sniffed the codes from my thermostat to find the on off codes, and this file haas been constructed to suit my boiler. I believe that all the thermostat and boiler pairings have unique codes, so this will probably not work with your boiler. Likewise if your boiler operates on a different radio frequency. Adaptations to the code will be required to make it work for you. I will eventually put a write up on here as to how I hacked this to work. Get in touch in the meantime if you would like to know how I did it. I don't see any reason this code cannot be adapted to suit any make of boiler on any frequency as long as you have the hardware to do it.

## Flaskapp
'Mighty oaks from small acorns grow'. This is the beginnings of the 'front end' of this homeautomation system. So far it displays the temperature from a temperature sensor, and plots a graph of historic temperature data upto the current time. Plenty to do here.
