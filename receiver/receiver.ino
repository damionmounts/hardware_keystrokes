// Program Space:  Maximum is 28672 bytes.
// Dynamic Memory: Maximum is 2560 bytes.

#include "Keyboard.h"
#include "Mouse.h"

enum command {

  // Keyboard Commands
  KEYBOARD_BEGIN,
  KEYBOARD_END,
  KEYBOARD_PRESS,
  KEYBOARD_PRINT,
  KEYBOARD_PRINTLN,
  KEYBOARD_RELEASE,
  KEYBOARD_RELEASEALL,
  KEYBOARD_WRITE,

  // Mouse Commands
  MOUSE_BEGIN,
  MOUSE_CLICK,
  MOUSE_END,
  MOUSE_MOVE,
  MOUSE_PRESS,
  MOUSE_RELEASE,
  MOUSE_ISPRESSED
};

void setup() {
//  Mouse.begin();
//  Keyboard.begin();
//  delay(2000);
//  Keyboard.write('a');
  Serial.begin(9600);
}

void loop() {
//  Serial.print(millis());
//  Serial.print("\n");
//  delay(2000);
  if (Serial.available() > 0) {

    // Map lowercase alphabet to commands for test
    byte a = Serial.read();
    a -= 97;
    
    switch (a) {
      case KEYBOARD_BEGIN: {
        Serial.println("K.begin");
        break;
      }
      case KEYBOARD_END: {
        Serial.println("K.end");
        break;
      }
      case KEYBOARD_PRESS: {
        Serial.println("K.press");
        break;
      }
      case KEYBOARD_PRINT: {
        Serial.println("K.print");
        break;
      }
      case KEYBOARD_PRINTLN: {
        Serial.println("K.printLn");
        break;
      }
      case KEYBOARD_RELEASE: {
        Serial.println("K.release");
        break;
      }
      case KEYBOARD_RELEASEALL: {
        Serial.println("K.releaseAll");
        break;
      }
      case KEYBOARD_WRITE: {
        Serial.println("K.write");
        break;
      }
      case MOUSE_BEGIN: {
        Serial.println("M.begin");
        break;
      }
      case MOUSE_CLICK: {
        Serial.println("M.click");
        break;
      }
      case MOUSE_END: {
        Serial.println("M.end");
        break;
      }
      case MOUSE_MOVE: {
        Serial.println("M.move");
        break;
      }
      case MOUSE_PRESS: {
        Serial.println("M.press");
        break;
      }
      case MOUSE_RELEASE: {
        Serial.println("M.release");
        break;
      }
      case MOUSE_ISPRESSED: {
        Serial.println("M.isPressed");
        break;
      }
      default: {
        Serial.println("UNKNOWN COMMAND\n");
        break;
      }
    }
  }
}

// ---------------------------------------

// Keyboard.begin()
//  i: none
//  o: none

// Keyboard.end()
//  i: none
//  o: none

// Keyboard.press()
//  i: char - key to press
//  o: size_t - number of key presses sent

// Keyboard.print()
//  i: Union[char, int, string] - char/int sends a single keystroke, string sends a set of keystrokes
//  o: size_t - number of bytes sent

// Keyboard.println()
//  i: Union[char, int, string] - char/int sends a single keystroke, string sends a set of keystrokes (+newline & CR)
//  o: size_t - number of bytes sent

// Keyboard.release()
//  i: char - key to release
//  o: size_t - number of keys released

// Keyboard.releaseAll()
//  i: none
//  o: none

// Keyboard.write()
//  i: Union[char, int] - key to send
//  o: size_t - number of bytes sent

// ---------------------------------------

// Mouse.begin()
//  i: none
//  o: none

// Mouse.click()
//  i: Union[None, MOUSE_LEFT, MOUSE_RIGHT, MOUSE_MIDDLE] - char that is the button to click, left is default
//  o: none

// Mouse.end()
//  i: none
//  o: none

// Mouse.move()
//  i: signed char - x-movement, signed char - y-movement, signed char - amount to scroll wheel
//  o: none

// Mouse.press()
//  i: Union[None, MOUSE_LEFT, MOUSE_RIGHT, MOUSE_MIDDLE] - char that is the button to press, left is default
//  o: none

// Mouse.release()
//  i: Union[None, MOUSE_LEFT, MOUSE_RIGHT, MOUSE_MIDDLE] - char that is the button to release, left is default
//  o: none

// Mouse.isPressed()
//  i: Union[None, MOUSE_LEFT, MOUSE_RIGHT, MOUSE_MIDDLE] - button to check status of, left is default
//  o: bool - whether button is pressed or not
