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
