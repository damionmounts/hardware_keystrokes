#include "Keyboard.h"
#include "Mouse.h"

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
    int got = Serial.read();
    Serial.print("{");
    Serial.print((char)got);
    Serial.print("}\n");
  }
}
