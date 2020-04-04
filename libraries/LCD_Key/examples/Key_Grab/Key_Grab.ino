/*
Cytron's LCD Keypad Shield for Arduino
Key Grab v1.0
Original Written by Glendon Klassen
gjklassen@gmail.com
Modified by Ober Choo, Cytron to suit Cytron's LCD keypad shield

Displays the currently pressed key on the LCD screen.

Key Codes (in left-to-right order):

None   - 0
Select - 1
Left   - 2
Up     - 3
Down   - 4
Right  - 5

*/

#include <LiquidCrystal.h>
#include <LCD_Key.h>

//Pin assignments for DFRobot LCD Keypad Shield
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 
//---------------------------------------------

LCD_Key keypad;

int localKey = 0;
String keyString = "";
                 
void setup() 
{ 
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Key Grab v1.0");
  delay(2000);
  
  /*
  OPTIONAL
  keypad.setRate(x);
  Sets the sample rate at once every x milliseconds.
  Default: 10ms
  */
  keypad.setRate(10);

}

void loop() 
{ 
  /*
  keypad.getKey();
  Grabs the current key.
  Returns a non-zero integer corresponding to the pressed key,
  OR
  Returns 0 for no keys pressed,
  OR
  Returns -1 (sample wait) when no key is available to be sampled.
  Will also display the analog value at site
  */
  localKey = keypad.getKey();
  lcd.setCursor(4, 1);
  lcd.print(analogRead(0));
  if (localKey != SAMPLE_WAIT)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Current Key:");
    lcd.setCursor(0, 1);
    lcd.print(localKey);   
  }  
}
