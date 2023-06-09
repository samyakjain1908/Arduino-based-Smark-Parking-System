# Arduino-based-Smark-Parking-System
This Project is done for my college project. The project name is Smart Parking System using Arduino UNO R3, NodeMCU ESP8266, and Blynk IoT Cloud. A 12V-2A power socket powers the model.
The main functions of the system are 
i.) The barricading opens after sensing the car through IR sensors.
ii.) The slots get updated on the LCD screen. This process can be done as the slot sensor's data gets captured and transmitted to the i2C LCD module. 
iii.) The data also gets updated in the Blynk Mobile App and desktop app and even records the duration of online time of NodeMCU. The process is possible because the NodeMCU ESP8266 module is connected to the cloud, and the data is updated quickly. The data is transmitted to NodeMCU using the RX and TX pins connected to Arduino UNO.


![Demo model](https://user-images.githubusercontent.com/89599623/227024346-dc884335-fea9-4b91-9307-73f8755b989e.jpeg)

![image](https://user-images.githubusercontent.com/89599623/227026545-5e61f12c-4e23-4b35-83e5-d7a0e8deab15.png)

![phone blynk info](https://user-images.githubusercontent.com/89599623/227026651-71dda712-ab3f-4389-bcca-6b55432b7448.jpeg)
