// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Setting up sensor pin
int sensorPin = A0;    // select the input pin for the potentiometer or other sensor
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.display();
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  lcd.setCursor(0, 0);
  lcd.print("Rei's Multimeter!");
  lcd.setCursor(0, 1); //setting the second line of the LCD
  lcd.print(sensorValue); // print sensor value from A0 pin
  delay(50);
  lcd.clear();
}
