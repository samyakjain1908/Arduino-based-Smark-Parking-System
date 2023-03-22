# Arduino-based-Smark-Parking-System
This Project is made for my college project.The project name is Smart Parking System using Arduino UNO ,NodeMCU ESP8266 and Blynk IoT Cloud. 
The model is powered by 12V-2A power socket. 

The main functions of the system is:
i.) The barricading opens after sensing the car through IR sensors.

ii.) The slots get updated in the LCD screen.This process can be done as the slot sensor's data get captured and it transmits the
information to i2C LCD module. 

iii.) The data also gets updated in the Blynk Mobile App and desktop app and even records the duration of online time of NodeMCU.
This can be possible due to NodeMCU ESP8266 module which is connected to the cloud and the data get updated quickly. The data is 
transmiited to NodeMCU using the RX and TX pins which is connected to Arduino UNO. 


Present challenges:
i.) The servo motor is not responding as required. It glitches due to lack of power input. 
ii.) Slot 2 data doesn't get updated in the Blynk IoT Cloud.
iii.) The LCD screen sometimes show wrong data on the screen. 
