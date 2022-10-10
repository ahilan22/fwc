#include <Arduino.h>

int n = 13;
void setup() {
pinMode(n, OUTPUT);
}

void loop() {
digitalWrite(n, HIGH);
delay(500);
digitalWrite(n, LOW);
delay(500);
}
