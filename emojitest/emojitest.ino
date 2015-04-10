/* Emoji Printing test - Linux only.
   Loop prints the unicode pile of poo, using ctrl-shift-u <codepoint> <space>
   
   Teensy becomes a USB keyboard and types characters

   You must select Keyboard from the "Tools > USB Type" menu

   This example code is in the public domain.
*/

// Unicode Key Codes of Interest
char PILE_OF_POO[ ] = "1f4a9";
char CIRCLEY_ETERNITY[ ] = "058D"; //right-facing armenian eternity symbol.
char INTERROBANG[ ] = "203D";
char BULLET[ ] = "2022";
char R_DOUBLE_ARROW[ ] = "21D2";
char L_DOUBLE_ARROW[ ] = "21D0";
char R_TRIPLE_ARROW[ ] = "21DB";
char INFINITY_SYMBOL[ ] = "221E";
char POINT_OF_INTEREST[ ] = "2318";
char HOURGLASS[ ] = "231B";
char ACK[ ] = "2406";
char NACK[ ] = "2415";
char SNOWMAN[ ] = "2603";
char SKULL_CROSSBONES[ ] = "2620";
char RADIOACTIVE[ ] = "2622";
char BIOHAZARD[ ] = "2623";
char HAMMER_SICKLE[ ] = "262D";
char ANCHOR[ ] = "2693";
char ATOM[ ] = "269B";
char SAILBOAT[ ] = "26F5";
char CHECK[ ] = "2713";
char CHECK_BOLD[ ] = "2714";
char MULT_X_BOLD[ ] = "2716";
char NAUTICAL_STAR[ ] = "272F";
char ASTERIX_8[ ] = "274B";
char TD_ARROW[ ] = "27BB";
char R_ARROW_4[ ] = "2B46";
char TEACUP[ ] = "1F375";
char BEER[ ] = "1F37A";
char GOAT[ ] = "1F410";
char OCTOPUS[ ] = "1F419";
char ALIEN_MONSTER[ ] = "1F47E";




int buttonPin = 2;
int buttonState = LOW;

int ctrlKey = MODIFIERKEY_CTRL;
int shiftKey = MODIFIERKEY_SHIFT;

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  pinMode(buttonPin, INPUT);
  delay(3000);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  delay(30);
  if(buttonState == HIGH){
    Keyboard.press(ctrlKey);
    Keyboard.press(shiftKey);
    Keyboard.press('u');
    delay(100);
    Keyboard.releaseAll();
    delay(100);
    Keyboard.print(ANCHOR);
    Keyboard.print(' ');
  }
  
  // typing too rapidly can overwhelm a PC
  delay(100);
}
