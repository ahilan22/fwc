#include <Arduino.h>

int V_out_q = 0;
float V_in = 5, V_out;
float R1 = 150, R2;

void setup() {
Serial.begin(9600);
}

void loop() {
V_out_q = analogRead(0);
V_out = V_in*V_out_q/1024;
R2 = (R1*V_out)/(V_in - V_out);
delay(3000);
Serial.println(R2);
}
