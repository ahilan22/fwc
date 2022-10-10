// we take the decade counter as bit stream 

#include <Arduino.h>

int W,X,Y,Z;
int D=0,C=0,B=0,A=0;
int E;


void disp_7447(int D,int C,int B, int A)
{
  digitalWrite(2, A); //LSB
  digitalWrite(3, B); 
  digitalWrite(4, C); 
  digitalWrite(5, D); //MSB
}

void setup() {
	
pinMode(2, OUTPUT);  
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, INPUT);
pinMode(7, INPUT);
pinMode(8, INPUT);
pinMode(9, INPUT);
pinMode(10, OUTPUT); // connected to clocks of 7474 D-FF
pinMode(13, OUTPUT);
}

void loop() {

digitalWrite(10, HIGH);

W = digitalRead(6);
X = digitalRead(7);
Y = digitalRead(8);
Z = digitalRead(9);
   
A = (!W);
B = (!W&&!X&&Y) || (W&&X) || (!W&&Z);
C = (!W&&Z) || (X&&Y) || (W&&Y);
D = (!W&&!X&&!Y&&!Z)||(W&&Z);

disp_7447(D,C,B,A);
E = (A&&B&&C);
digitalWrite(13, E);

W = A;
X = B; 
Y = C;
Z = D;

digitalWrite(10, LOW);
delay(1000);
}
