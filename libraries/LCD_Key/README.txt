README:

Cytron LCD Keypad Shield for Arduino
Key Grab v1.0
Original Written by Glendon Klassen
gjklassen@gmail.com
Modified by Ober Choo, Cytron for Cytron LCD Keypad shield

Extract the zip file under Arduino 1.0/libraries/

Restart Arduino IDE and open "Key_Grab" from example under folder LCD_Key

Displays the currently pressed key, digital and analog on the LCD screen.

Key Codes (in left-to-right order):

None   - 0
Select - 1
Left   - 2
Up     - 3
Down   - 4
Right  - 5

Example Constructor: LCD_Key keypad;

keypad.getKey();
Grabs the current key.
Returns a non-zero integer corresponding to the pressed key,
  OR
Returns 0 for no keys pressed,
  OR
Returns -1 (sample wait) when no key is available to be sampled.

OPTIONAL
keypad.setRate(x);
Sets the sample rate at once every x milliseconds.
Default: 10ms
