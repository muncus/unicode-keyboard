/* Emoji Keyboard - Linux only.

   Functions as a simple usb keyboard device, outputting a variety of unicode symbols of interest.
   relies on the unix input method: ctrl-shift-u <codepoint> <space>
   You must select Keyboard from the "Tools > USB Type" menu
   This example code is in the public domain.
*/

#include "keycodes.h"

// Keymap contains the symbol to be emitted when the corresponding pin is found to be high.
const int KEYMAP_SIZE = 4;
String KEYMAP[KEYMAP_SIZE] = {
  SKULL_CROSSBONES,
  PILE_OF_POO,
  SAILBOAT,
  TEACUP,
};

int buttonState = HIGH;

/* The process for entering unicode key codes varies by OS.
 * This implementation is linux-specific, and relies on the code being ctrl+shift+u <keycode> <space>
 * the delay calls are present to prevent overwhelming the host with input.
 */
void sendSequenceLinux(String seq){
  Serial.println(seq);
  Keyboard.press(MODIFIERKEY_CTRL);
  Keyboard.press(MODIFIERKEY_SHIFT);
  Keyboard.press('u');
  delay(100);
  Keyboard.releaseAll();
  delay(50);
  Keyboard.print(seq);
  Keyboard.print(" ");
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

// A Mac equivalent requires the "Unicode Hex Input" to be enabled,
// then hold Option, enter the keycode, release Option.


void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  for(int i=0;i<KEYMAP_SIZE;i++){
    pinMode(i, INPUT_PULLUP);
  }
  //delay(3000);
}

void loop() {
  
  for(int i=0;i<KEYMAP_SIZE;i++){
    buttonState = digitalRead(i);
    if(buttonState == LOW){
      sendSequenceLinux(KEYMAP[i]);
    }
    //delay(100);
  }
}
