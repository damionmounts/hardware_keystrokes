// Program Space:  Maximum is 28672 bytes.
// Dynamic Memory: Maximum is 2560 bytes. eee

#include "Keyboard.h"
#include "Mouse.h"

// Wait for and then return serial byte
byte blockingRead() {
    while (!Serial.available()) {}
    return Serial.read();
}

// Serial writes size_t big endian as bytes
void serialWriteSizeT(size_t val) {
    Serial.write((val >> 8) & 0xFF); // High byte first
    Serial.write(val & 0xFF); // Low byte last
}

enum commands {

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
    while (!Serial) {}
    Serial.println(MOUSE_LEFT); // 1
    Serial.println(MOUSE_RIGHT); // 2
    Serial.println(MOUSE_MIDDLE); // 4
    Serial.println(false); // 0
    Serial.println(true); // 1
    Serial.println(sizeof(size_t)); // 2
    Keyboard.begin();
    Keyboard.print(127);
    delay(10000);
    delay(10000);
    delay(10000);
}

// Loop Functionality:
//  Wait for serial data
//  Take first byte as command byte and switch to command
//  Consume bytes as needed for command inside command case

void loop() {

    // Map lowercase alphabet to commands for test
    byte cmd = blockingRead();

    switch (cmd) {

        // Keyboard.begin()
        //  i: none
        //  o: none
        case KEYBOARD_BEGIN: {
            Keyboard.begin();
            break;
        }

        // Keyboard.end()
        //  i: none
        //  o: none
        case KEYBOARD_END: {
            Keyboard.end();
            break;
        }

        // Keyboard.press()
        //  i: char - key to press
        //  o: size_t - number of key presses sent
        case KEYBOARD_PRESS: {
            char key = blockingRead();
            size_t ret = Keyboard.press(key);
            serialWriteSizeT(ret);
            break;
        }

        // Keyboard.print()
        //  i: char - sends a single keystroke
        //  o: size_t - number of bytes sent
        case KEYBOARD_PRINT: {
            char key = blockingRead();
            size_t ret = Keyboard.print(key);
            serialWriteSizeT(ret);
            break;
        }

        // Keyboard.println()
        //  i: char - sends a single keystroke then newline
        //  o: size_t - number of bytes sent
        case KEYBOARD_PRINTLN: {
            char key = blockingRead();
            size_t ret = Keyboard.println(key);
            serialWriteSizeT(ret);
            break;
        }

        // Keyboard.release()
        //  i: char - key to release
        //  o: size_t - number of keys released
        case KEYBOARD_RELEASE: {
            Serial.println("K.release");
            break;
        }

        // Keyboard.releaseAll()
        //  i: none
        //  o: none
        case KEYBOARD_RELEASEALL: {
            Keyboard.releaseAll();
            break;
        }

        // Keyboard.write()
        //  i: char - key to send
        //  o: size_t - number of bytes sent
        case KEYBOARD_WRITE: {
            char key = blockingRead();
            size_t ret = Keyboard.write(key);
            serialWriteSizeT(ret);
            break;
        }

        // Mouse.begin()
        //  i: none
        //  o: none
        case MOUSE_BEGIN: {
            Mouse.begin();
            break;
        }

        // Mouse.click()
        //  i: Union[None, MOUSE_LEFT, MOUSE_RIGHT, MOUSE_MIDDLE] - char that is the button to click, left is default
        //  o: none
        case MOUSE_CLICK: {
            //[btn] -> 0: None, 1: MOUSE_LEFT, 2: MOUSE_RIGHT, 4: MOUSE_MIDDLE
            byte btn = blockingRead();
            if (btn == 0) {
                Mouse.click();
            }
            else {
                Mouse.click(btn);
            }
            break;
            break;
        }

        // Mouse.end()
        //  i: none
        //  o: none
        case MOUSE_END: {
            Mouse.end();
            break;
        }

        // Mouse.move()
        //  i: signed char - x-movement, signed char - y-movement, signed char - amount to scroll wheel
        //  o: none
        case MOUSE_MOVE: {
            char xMov = blockingRead();
            char yMov = blockingRead();
            char scroll = blockingRead();
            Mouse.move(xMov, yMov, scroll);
            break;
        }

        // Mouse.press()
        //  i: Union[None, MOUSE_LEFT, MOUSE_RIGHT, MOUSE_MIDDLE] - char that is the button to press, left is default
        //  o: none
        case MOUSE_PRESS: {
            //[btn] -> 0: None, 1: MOUSE_LEFT, 2: MOUSE_RIGHT, 4: MOUSE_MIDDLE
            byte btn = blockingRead();
            if (btn == 0) {
                Mouse.press();
            }
            else {
                Mouse.press(btn);
            }
            break;
        }

        // Mouse.release()
        //  i: Union[None, MOUSE_LEFT, MOUSE_RIGHT, MOUSE_MIDDLE] - char that is the button to release, left is default
        //  o: none
        case MOUSE_RELEASE: {
            //[btn] -> 0: None, 1: MOUSE_LEFT, 2: MOUSE_RIGHT, 4: MOUSE_MIDDLE
            byte btn = blockingRead();
            if (btn == 0) {
                Mouse.release();
            }
            else {
                Mouse.release(btn);
            }
            break;
        }

        // Mouse.isPressed()
        //  i: Union[None, MOUSE_LEFT, MOUSE_RIGHT, MOUSE_MIDDLE] - char that is button to check status of, left is default
        //  o: bool - whether button is pressed or not
        case MOUSE_ISPRESSED: {
            //[btn] -> 0: None, 1: MOUSE_LEFT, 2: MOUSE_RIGHT, 4: MOUSE_MIDDLE
            byte btn = blockingRead();
            bool ret;
            if (btn == 0) {
                ret = Mouse.isPressed();
            }
            else {
                ret = Mouse.isPressed(btn);
            }
            Serial.write(ret);
            break;
        }

        // Unrecognized command byte
        default: {
            Serial.println("UNKNOWN COMMAND\n");
            break;
        }
    }
}
