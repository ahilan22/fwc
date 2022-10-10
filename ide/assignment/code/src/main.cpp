#include <Arduino.h>

bool Y, A, B;

void setup() {
pinMode(13, OUTPUT);
pinMode(8, INPUT);
pinMode(9, INPUT);
}

void loop() {
A = digitalRead(8);
B = digitalRead(9);
Y = ((!A) || B) && (A || (!B)); // POS form
// Y = (!A&&!B) || (A&&B); // SOP form
digitalWrite(13, Y);	
}
