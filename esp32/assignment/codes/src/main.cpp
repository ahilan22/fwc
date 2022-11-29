#include <Arduino.h>

#define pinA 4
#define pinB 6
#define pinY 8

bool Y, A, B;

void setup() {
pinMode(pinY, OUTPUT);
pinMode(pinA, INPUT);
pinMode(pinB, INPUT);
}

void loop() {
A = digitalRead(pinA);
B = digitalRead(pinB);
Y = ((!A) || B) && (A || (!B)); // POS form
// Y = (!A&&!B) || (A&&B); // SOP form
digitalWrite(pinY, Y);	
}
