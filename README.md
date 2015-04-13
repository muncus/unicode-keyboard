Emoji Keyboard
==============

## Overview

Sometimes, emoji symbols come in handy, but I can never remember the relevant
Unicode keycodes. I solved this by creating a mini-keyboard with buttons for my
favorite unicode characters.

The keyboard sequences to input Unicode characters varies by Operating System,
and the current implementation works only for Linux, but support may be added
later for Windows or Mac. (There are some comments in the code about making
this work on other platforms).

It was built with a Teensy (2.0), and the Arduino code is based off of the
[KeyboardMessage](http://arduino.cc/en/Tutorial/KeyboardMessage) tutorial.

## Configuration

Unicode characters available are defined in `keycodes.h`. If a symbol you want
is not present, feel free to add it.

The `config.h` file contains an array called `KEYMAP` which can be
modified to output symbols of your choice.  When a pin goes `LOW`, the
character at that index of `KEYMAP` is output.

## Circuit

The circuit relies on the built-in pullup resistors in the Teensy (most arduino
models also support this).
Simply connect ground to one side of your pushbutton, and an input pin to the
other. Repeat for each entry in the KEYMAP array.

### Future Work / To Do

* multi-platform support
* autogen Unicode code point header
