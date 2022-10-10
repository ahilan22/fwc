#include <Arduino.h>

int W,X,Y,Z;
int D,C,B,A;

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
pinMode(13, OUTPUT);

}

void loop() {

digitalWrite(13, HIGH);
delay(1000);

disp_7447(D,C,B,A);

W = digitalRead(6);
X = digitalRead(7);
Y = digitalRead(8);
Z = digitalRead(9);
   
A = (!W);
B = (!W&&!X&&Y) || (W&&X) || (!W&&Z);
C = (!W&&Z) || (X&&Y) || (W&&Y);
D = (!W&&!X&&!Y&&!Z)||(W&&Z);
delay(500);

W = A;
X = B; 
Y = C;
Z = D;

digitalWrite(13, LOW);
delay(1000);
}
