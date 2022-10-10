#include <Arduino.h>

int D,C,B,A;
int a,b,c,d,e,g,f;

void setup() {

pinMode(2, OUTPUT);  
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);            

pinMode(9, INPUT);
pinMode(10, INPUT);
pinMode(11, INPUT);
pinMode(12, INPUT);

}

void sevenseg(int a,int b,int c,int d,int e,int f,int g) {

digitalWrite(2, a); 
digitalWrite(3, b); 
digitalWrite(4, c); 
digitalWrite(5, d); 
digitalWrite(6, e); 
digitalWrite(7, f);     
digitalWrite(8, g); 

}

void loop() {

D = digitalRead(12);
C = digitalRead(11);
B = digitalRead(10);
A = digitalRead(9);

a = (A&&!B&&!C&&!D) || (!A&&C);
b = (A&&!B&&C) || (!A&&B&&C);
c = (!A&&B&&!C&&!D);
d = (A&&B&&C) || (A&&!B&&!C) || (!A&&!B&&C);
e = A || (!B&&C);
f = (A&&B) || (A&&!C&&!D) || (B&&!C&&!D);
g = (A&&B&&C) || (!B&&!C&&!D);

sevenseg(a,b,c,d,e,f,g);
}
