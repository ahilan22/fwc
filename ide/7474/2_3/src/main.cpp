#include <Arduino.h>

int W,X,Y,Z;
int D=0,C=0,B=0,A=0;

void disp_7447(int D,int C,int B, int A)
{
  digitalWrite(2, A); //LSB
  digitalWrite(3, B); 
  digitalWrite(4, C); 
  digitalWrite(5, D); //MSB
}

void setup() 
{	
pinMode(2, OUTPUT);  
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(10, INPUT);
pinMode(11, INPUT);
pinMode(12, INPUT);
pinMode(13, INPUT);
pinMode(8, OUTPUT);
}

void loop() 
{
digitalWrite(8, HIGH);

W = digitalRead(10);
X = digitalRead(11);
Y = digitalRead(12);
Z = digitalRead(13);

A = (!W);
B = (W&&!X&&!Z) || (!W&&X);
C = (W&&X&&!Y) || (!X&&Y) || (!W&&Y);
D = (W&&X&&Y)||(!W&&Z);

disp_7447(D,C,B,A);

digitalWrite(8, LOW);
delay(1000);
}
//&& is the AND operation
// || is the OR operation
// ! is the NiOT operation
