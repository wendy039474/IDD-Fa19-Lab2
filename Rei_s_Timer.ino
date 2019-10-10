// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Setting up button pin
int buttonPin = 9;

//Encoder
#define ENC_A 6 //these need to be digital input pins
#define ENC_B 7

//Variables for timer
bool countstate = false;
int counting;
unsigned long int previousMillis;
unsigned long int currentMillis;

//Melody
#include "pitches.h"
int melody[] = {NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4, 0};
int noteDurations[] = {4, 4, 4, 5, 16, 4, 5, 16, 2, 4, 4, 4, 5, 16, 4, 5, 16, 2};

//Variable for pressure sensor
int pressPin = 10;
int presscount = 0;
int last_state = 0;
int now_state = 0;

void setup() {
  Serial.begin(9600);
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.display();

  //setting buttonpin mode as input
  pinMode(buttonPin, INPUT);
  pinMode(pressPin, INPUT);

  /* Setup encoder pins as inputs */
  pinMode(ENC_A, INPUT_PULLUP);
  pinMode(ENC_B, INPUT_PULLUP);

  lcd.setCursor(0, 0); //Setting the first line of the LCD
  lcd.print("Timer Setting"); //Words to display
  lcd.setCursor(0, 1); //Setting the first line of the LCD
  lcd.print("0");
  lcd.print("s");
}

void loop() {


  if(countstate == false){
    static unsigned int counter4x = 0;      //the SparkFun encoders jump by 4 states from detent to detent
    static unsigned int counter = 0;
    static unsigned int prevCounter = 0;
    int tmpdata;
    tmpdata = read_encoder();
    if(tmpdata) {
      counter4x += tmpdata;
      counter = counter4x/4;
      if (prevCounter != counter){
        lcd.clear(); //clean the screen for next round of reading
        lcd.setCursor(0, 0); //Setting the first line of the LCD
        lcd.print("Timer Setting"); //Words to display
        lcd.setCursor(0, 1); //Setting the first line of the LCD
        lcd.print(counter);
        lcd.print("s");
        }
      prevCounter = counter;
    }
    
    int i = digitalRead(buttonPin);
    if(i == HIGH){
      countstate = true;
      previousMillis = millis();
      counting = counter;
      lcd.clear(); //clean the screen for next round of reading
      lcd.setCursor(0, 0); //Setting the first line of the LCD
      lcd.print("Counting Down"); //Words to display
      lcd.setCursor(0, 1); //Setting the first line of the LCD
      lcd.print(counting); //Words to display
      lcd.print("s");
      }
  }

  else{
    now_state = digitalRead(pressPin);
    if (now_state != last_state){
      presscount++;
      last_state = now_state;
      }
    
    currentMillis = millis();
    if(counting >= 1){
      if(currentMillis - previousMillis >= 1000){
        counting --;
        lcd.clear(); //clean the screen for next round of reading
        lcd.setCursor(0, 0); //Setting the first line of the LCD
        lcd.print("Counting Down"); //Words to display
        lcd.setCursor(0, 1); //Setting the first line of the LCD
        lcd.print(counting); //Words to display
        lcd.print("s");
        previousMillis = currentMillis;
        }
      }
    else{
      lcd.clear(); //clean the screen for next round of reading
      lcd.setCursor(0, 0); //Setting the first line of the LCD
      lcd.print("TIME'S UP!!!"); //Words to display
      lcd.setCursor(0, 1); //Setting the first line of the LCD
      lcd.print(presscount/2); //Words to display
      lcd.print(" times!"); //Words to display
      presscount = 0;
      for (int thisNote = 0; thisNote < 18; thisNote++) {
        int noteDuration = 1000 / noteDurations[thisNote];
        tone(8, melody[thisNote], noteDuration);
    
        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(8);
      }
      countstate = false;
      lcd.clear(); //clean the screen for next round of reading
      lcd.setCursor(0, 0); //Setting the first line of the LCD
      lcd.print("Timer Reset"); //Words to display
      }
    delay(50);
    }
}

/* returns change in encoder state (-1,0,1) */
int read_encoder()
{
  static int enc_states[] = {
    0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0  };
  static byte ABab = 0;
  ABab *= 4;                   //shift the old values over 2 bits
  ABab = ABab%16;      //keeps only bits 0-3
  ABab += 2*digitalRead(ENC_A)+digitalRead(ENC_B); //adds enc_a and enc_b values to bits 1 and 0
  return ( enc_states[ABab]);
}

void pressing(){
  presscount++;
  }
