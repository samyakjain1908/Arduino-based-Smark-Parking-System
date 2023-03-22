#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
SoftwareSerial nodemcu(2, 3);  //Pin 2 of Arduino is TX and Pin 3 is RX

Servo myservo;

#define ir_enter 5
#define ir_back 6

int slot1_ir = 4;  // parking slot1 infrared sensor connected with pin number 4 of arduino
int slot2_ir = 7;  // parking slot2 infrared sensor connected with pin number 7 of arduino

String sensor1;
String sensor2;

int S1 = 0, S2 = 0;
int flag1 = 0, flag2 = 0;
int slot = 2;

String cdata = "";  // complete data, consisting of sensors values

void setup() {
  Serial.begin(9600);
  nodemcu.begin(9600);

  pinMode(slot1_ir, INPUT);
  pinMode(slot2_ir, INPUT);
  pinMode(ir_enter, INPUT);
  pinMode(ir_back, INPUT);

  myservo.attach(8);
  myservo.write(90);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("    INCOGNITO    ");
  lcd.setCursor(0, 1);
  lcd.print(" PARKING SYSTEM ");
  delay(2000);
  lcd.clear();

  Read_Sensor();

  int total = S1 + S2;
  slot = slot - total;
}

void loop() 
{

  slot1();
  slot2();
  Read_Sensor();


  lcd.setCursor(0, 0);
  lcd.print("   Have Slot: ");
  lcd.print(slot);
  lcd.print("    ");

  lcd.setCursor(0, 1);
  if (S1 == 1) {
    lcd.print("S1:Full");
  } else {
    lcd.print("S1:Emp");
  }

  lcd.setCursor(9, 1);
  if (S2 == 1) {
    lcd.print("S2:Full");
  } else {
    lcd.print("S2:Emp");
  }

  if (digitalRead(ir_enter) == 0 && flag1 == 0) { //servo motor code
  if (slot > 0) {
    flag1 = 1;
    if (flag2 == 0) {
      myservo.write(180);
      slot = slot - 1;
    }
  } else {
    lcd.setCursor(0, 1);
    lcd.print(" Parking Full ");
    delay(1500);
  }


if (digitalRead(ir_back) == 0 && flag2 == 0) {
  flag2 = 1;
  if (flag1 == 0) {
    myservo.write(180);
    slot = slot + 1;
  }
}

if (flag1 == 1 && flag2 == 1) {
  delay(1000);
  myservo.write(90);
  flag1 = 0, flag2 = 0;
}

delay(1);
  }





  cdata = cdata + sensor1 + "", "" + sensor2 + "", "";  //comma will be used as a delimeter
  Serial.println(cdata);
  nodemcu.println(cdata);
  delay(6000);  // 100 milli seconds
  cdata = "";
  digitalWrite(slot1_ir, HIGH);
  digitalWrite(slot2_ir, HIGH);

if (digitalRead(ir_enter) == 0 && flag1 == 0) {
  if (slot > 0) {
    flag1 = 1;
    if (flag2 == 0) {
      myservo.write(180);
      slot = slot - 1;
    }
  } else {
    lcd.setCursor(0, 1);
    lcd.print(" Parking Full ");
    delay(1500);
  }
}

if (digitalRead(ir_back) == 0 && flag2 == 0) {
  flag2 = 1;
  if (flag1 == 0) {
    myservo.write(180);
    slot = slot + 1;
  }
}

if (flag1 == 1 && flag2 == 1) {
  delay(1000);
  myservo.write(90);
  flag1 = 0, flag2 = 0;
}

delay(1);
}

void slot1()  //  slot1
{
  if (digitalRead(slot1_ir) == LOW)  // If a car is present in front of sensor
  {
    sensor1 = "255";
    delay(200);
  }
  if (digitalRead(slot1_ir) == HIGH)  // // If no car is present in front of sensor
  {
    sensor1 = "0";
    delay(200);
  }
}
void slot2()  // parking 1 slot2
{
  if (digitalRead(slot2_ir) == LOW) {
    sensor2 = "255";
    delay(200);
  }
  if (digitalRead(slot2_ir) == HIGH) {
    sensor2 = "0";
    delay(200);
  }
}
void Read_Sensor()
 {
  S1 = 0, S2 = 0;

  if (digitalRead(slot1_ir) == 0) { S1 = 1; }
  if (digitalRead(slot2_ir) == 0) { S2 = 1; }
}




