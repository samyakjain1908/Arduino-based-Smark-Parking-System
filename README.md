# Arduino-based-Smark-Parking-System
This Project is done for my college project. The project name is Smart Parking System using Arduino UNO, NodeMCU ESP8266, and Blynk IoT Cloud. A 12V-2A power socket powers the model./n
The main functions of the system are /n
i.) The barricading opens after sensing the car through IR sensors.
ii.) The slots get updated on the LCD screen. This process can be done as the slot sensor's data gets captured and transmitted to the i2C LCD module. /n
iii.) The data also gets updated in the Blynk Mobile App and desktop app and even records the duration of online time of NodeMCU. The process is possible because the NodeMCU ESP8266 module is connected to the cloud, and the data is updated quickly. The data is transmitted to NodeMCU using the RX and TX pins connected to Arduino UNO. /n

Present challenges: 
i.) The servo motor is not responding as required. It glitches due to a lack of power input. /n
ii.) Slot 2 data doesn't get updated in the Blynk IoT Cloud. /n
iii.) The LCD screen sometimes shows the wrong data on the screen. /n
