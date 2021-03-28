# Wireless Notice Board
This will enable us in passing any message almost immediately without any delay just by sending a command from our smart phone.

<img src="https://user-images.githubusercontent.com/39031660/112743533-c6acd480-8fb5-11eb-986c-c9da6a5f89cb.jpeg" width=640>


# Components Required
1. Arduino Uno R3
2. 16x2 LCD Display
3. HC-05 Bluetooth Module
4. Resistor of 1k Ohm
5. Jumper Wires
6. Bread board

# How does this project work?
HC 05/06 works on serial communication. The Android app is designed to send serial data to the Arduino Bluetooth module when a text is sent from the app. The Arduino Bluetooth module at the other end receives the data and sends it to the Arduino through the TX pin of the Bluetooth module (connected to RX pin of Arduino). The code uploaded to the Arduino checks the received data and compares it. Then it displays the message after encoding in an LCD displayable format.

# Connections

LCD display with Arduino

|S.No| LCD | ARDUINO |
|-| --- | --- |
|1| VSS (Pin-1) | GND |
|2| VDD (Pin-2) | 5V |
|3| RS  (Pin-4) | D4 |
|4| RW  (Pin-5) | GND |
|5| E   (Pin-6) | D5 |
|6| D4  (Pin-11) | D6 |
|7| D5  (Pin-12) | D7 |
|8| D6  (Pin-13) | D8 |
|9| D7  (Pin-14) | D9 |
|10| A   (Pin-15) | 5V |
|11| K   (Pin-16) | GND |


Connect the 1K Ohm Resistor between the VSS Pin (pin-1) and the V0 Pin (pin-3).


 Bluetoth Module with Arduino

|S.NO| HC-05 Module | ARDUINO |
|-| --- | --- |
|1| RXD | TXD (D1) |
|2| TXD | RXD (D0) |
|3| GND  | GND |
|4| VCC  | 5V |


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

# Download
Download the project files, code and documentation by clicking [here](https://github.com/SOACodeRoom/wirelessnoticeboard/archive/refs/tags/v1.0.zip)

---

Made with 🖤 by [Sanket Sanjeeb Pattanaik](https://github.com/sanketsanjeebpattanaik)
