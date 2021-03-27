# Wireless Notice Board
This will enable us in passing any message almost immediately without any delay just by sending a command from our smart phone.

# Components Required
1. Arduino Uno R3
2. 16x2 LCD Display
3. HC-05 Bluetooth Module
4. Resistor of 1k Ohm
5. Jumper Wires
6. Bread board

# How does this project work?
HC 05/06 works on serial communication. The Android app is designed to send serial data to the Arduino Bluetooth module when a text is sent from the app. The Arduino Bluetooth module at the other end receives the data and sends it to the Arduino through the TX pin of the Bluetooth module (connected to RX pin of Arduino). The code uploaded to the Arduino checks the received data and compares it. Then it displays the message after encoding in an LCD displayable format.

# Circuit Diagram

![image](https://user-images.githubusercontent.com/39031660/112717792-d32d2080-8f14-11eb-947f-fc2793e6b632.png)


# Code
```cpp
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

LiquidCrystal lcd (4, 5, 6, 7, 8, 9);
SoftwareSerial mySerial (0, 1);   //(RX, TX);

String value = "No Data Avaliable !!";
String oldvalue;
String newvalue = "No Data Avaliable !!";
int i = 0;

void setup() 
{
  lcd.begin(16,2);
  mySerial.begin(9600);
  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print("Wireless Notice");
  lcd.setCursor(0, 1);
  lcd.print("     Board     ");
  delay(3000);
  lcd.clear();
  lcd.print("  (: Welcome :)  ");
}

void loop() 
{
  value = mySerial.readString();
  value.trim();
  Serial.println(value);
  if(value != oldvalue)
  {
    newvalue = value;
  }
  lcd.clear();
  lcd.setCursor(i, 0);
  lcd.print(newvalue);
  i++;
  if(i >= 15)
  {
    i = 0;
  }
  value = oldvalue;
}
```

# Android App Link
We have found this great app which works best on this project.

[Click here to download](https://bit.ly/39jTsa0)

Thanks to the developer for making this great app which is very easy for beginner.

---

Made with 🖤 by [Sanket Sanjeeb Pattanaik](https://github.com/sanketsanjeebpattanaik)
