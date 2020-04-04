/*
  PWM Motor Test
  pwm_motortest.ino
  Uses LCD Keypad module
  Modified from Cytron example code
  
  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/
// Include libraries for LCD Display
#include <LiquidCrystal.h>
#include "libraries/LCD_Key/LCD_Key.cpp"
 
// Define keycodes
#define None     0
#define Select   1
#define Left     2
#define Up       3
#define Down     4
#define Right    5
 
// Pin for analog keypad
#define diy_pwm  A2
// PWM output pin
#define pwm      10
// Motor direction pin
#define dir      11
 
// Define LCD display connections
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
// Setup LCD Keypad object
LCD_Key keypad;
 
// Variable to represent PWM value
int pwm_value = 0; 

int up = 0;
int down = 1;
 
// Variable to represent Keypad value
int localKey;       
 
void setup(){
  // Setup LCD  
  lcd.begin(16, 2);
  lcd.clear();

  // Set the PWM Frequency  
  setPwmFrequency(pwm, 8);
  
  // Define Pins
  pinMode(pwm,OUTPUT);
  pinMode(dir,OUTPUT); 
}
 
void loop()
{
  while(1)
  {
   // Scan keypad to determine which button was pressed
   localKey = keypad.getKey();    
   
   // Toggle motor direction if LEFT button pressed
   if(localKey==Left){      
     digitalWrite(dir,!digitalRead(dir));
     delay(50);}

   if(localKey == Right){
     pwm_value = 0;
     lcd.clear(); 
     delay(200);
   }
 
   // Increase motor speed if UP button pressed
   if(localKey==Up){      
     pwm_value = pwm_value + 10;
     delay(100);
     lcd.clear();}
   
   // Decrease motor speed if DOWN button pressed
   else if(localKey==Down){   
     pwm_value = pwm_value - 10;
     delay(100);
     lcd.clear();}
   
   // Ensure PWM value ranges from 0 to 255
   if(pwm_value > 255)      
     pwm_value = 255; 
   else if(pwm_value < 0)
     pwm_value = 0;
   
   // Send PWM to output pin
   analogWrite(pwm,pwm_value);
   
   // Display results on LCD
   lcd.setCursor(0,0);      
   lcd.print("Speed:");
   lcd.print(pwm_value);
   lcd.setCursor(0,1);
   lcd.print("Direction:");
   // lcd.print(digitalRead(dir));
   if (digitalRead(dir) == up){
    lcd.print("up  ");
    delay(150);
   } else if ( digitalRead(dir) == down) {
    lcd.print("down");
    delay(150);
   }
  }
}

void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x07; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}
