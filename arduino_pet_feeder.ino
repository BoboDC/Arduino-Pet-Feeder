// Include the Servo library 
#include <Servo.h> 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
RTC_DS3231 rtc;
// Declare the Servo pin 
int servoPin = 13; 
// Create a servo object 
Servo Servo1;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
LiquidCrystal_I2C lcd(0x27, 16, 2);
boolean feed = true;
char key;
int r[6];

void setup() { 
   // We need to attach the servo to the used pin number
    lcd.begin();

  // Turn on the blacklight and print a message.
   lcd.backlight(); 
   lcd.setCursor(2,0); 
   lcd.print("Dokfider");
   Servo1.attach(servoPin);
   Servo1.write(0);
   delay(1000);
   Serial.begin(9600);
   delay(3000); // wait for console opening

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  }
} 
void loop(){ 
   // Make servo go to 0 degrees
   // Send Day-of-Week
   DateTime now = rtc.now();
   char customKey = customKeypad.getKey();
   printtime();
   lcd.setCursor(2,1);

    lcd.print(now.hour());
    lcd.print(".");
    lcd.print(now.minute());
    lcd.print(".");
    lcd.print(now.second());
    delay(1000);
   
   int aux;
   if (customKey=='#') {
    feed = true;
   int i=0;
   aux = 1;
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Set feeding Time");
  lcd.clear();
  lcd.print("HH:MM");
  lcd.setCursor(2,1);

  
  while(1){
    key = customKeypad.getKey();

    char j;
    
  if(key!=NO_KEY){
    
    lcd.setCursor(j,1);
    
    lcd.print(key);
    
    r[i] = key-48;
    i++;
    j++;

    if (j==2)
    {
      lcd.print(":"); j++;
    }
    delay(500);
  }
  if (key == 'D')
  {
  key=0; break;
  lcd.clear();
  }
  }
  lcd.setCursor(2,0);
  lcd.clear();
  lcd.setCursor(2,1);
  lcd.clear();
   }
    if(now.hour()/10==r[0] && now.hour()%10==r[1]) {
        if(now.minute()/10==r[2] && now.minute()%10==r[3] )
          if(now.second()==40 && aux==1){ 
          //  delay(55000);
            aux=2;
            Servo1.write(0); 
            delay(1500);
            Servo1.write(180); 
            delay(1500);
            Servo1.write(0); 
            delay(1500);
          }
}
}

  void printtime() {
   lcd.setCursor(2,0); 
   lcd.print("Time Now:");
  }
