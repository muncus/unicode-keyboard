/* This file contains all the user-servicable parts for the emoji keyboard.
 * KEYMAP_SIZE specifies the number of buttons in the keyboard
 * KEYMAP is an array of the unicode symbols to be output when the corresponding pin goes low.
 */
const int KEYMAP_SIZE = 5;
const String KEYMAP[KEYMAP_SIZE] = {
  SKULL_CROSSBONES,
  NAUTICAL_STAR,
  SAILBOAT,
  TEACUP,
  BEER,
};

