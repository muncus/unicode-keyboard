/* Emoji Keyboard - Linux only.

   Functions as a simple usb keyboard device, outputting a variety of unicode symbols of interest.
   relies on the unix input method: ctrl-shift-u <codepoint> <space>
   You must select Keyboard from the "Tools > USB Type" menu
   This example code is in the public domain.
*/

#include "keycodes.h"

const int ctrlKey = MODIFIERKEY_CTRL;
const int shiftKey = MODIFIERKEY_SHIFT;


// Keymap contains the symbol to be emitted when the corresponding pin is found to be high.
const int KEYMAP_SIZE = 4;
char* KEYMAP[KEYMAP_SIZE] = {
  CIRCLEY_ETERNITY,
  BEER,
  GOAT,
  ALIEN_MONSTER,
};

int buttonState = LOW;

/* The process for entering unicode key codes varies by OS.
 * This implementation is linux-specific, and relies on the code being ctrl+shift+u <keycode> <space>
 */
void sendSequenceLinux(char* seq){
  Keyboard.press(ctrlKey);
  Keyboard.press(shiftKey);
  Keyboard.press('u');
  delay(40);
  Keyboard.releaseAll();
  delay(20);
  Keyboard.print(seq);
  Keyboard.print(' ');
  delay(50);
}

// entirely untested.
// based on advice from: fileformat.info/tip/microsoft/enter_unicode.htm
void sendSequenceWindows(char* seq){
  Keyboard.press(MODIFIERKEY_ALT);
  Keyboard.print('+');
  Keyboard.print(seq);
  delay(20);
  Keyboard.releaseAll();
  delay(20);
}


void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  for(int i=0;i<KEYMAP_SIZE;i++){
    pinMode(i, INPUT);
  }
  delay(3000);
}

void loop() {
  
  for(int i=0;i<KEYMAP_SIZE;i++){
    buttonState = digitalRead(i);
    delay(30);
    if(buttonState == HIGH){
      sendSequenceLinux(KEYMAP[i]);
    }
  }
}
