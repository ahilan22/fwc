//Prints a decimal number 
//on the display
#include <avr/io.h>
 
int main (void)
{
	
	
 //set PD2-PD7 as output pins 0xFC=0b11111100 (binary)
  DDRD   |= 0xFC;
  //set PB0 as output pin
  DDRB    |= ((1 << DDB0));
 
  while (1) {
 
    PORTB = ((1 <<  PB0));
    PORTD = 0xFC;		// 0 
 
 //   PORTB = ((1 <<  PB0));
 //   PORTD = 0x6C; 		// 1
 //
 //   PORTB = ((0 <<  PB0));
 //   PORTD = 0x24; 		// 2
 //
 //   PORTB = ((0 <<  PB0));
 //   PORTD = 0x0C; 		// 3
 //
 //   PORTB = ((0 <<  PB0));
 //   PORTD = 0x98; 		// 4
 //
 //   PORTB = ((0 <<  PB0));
 //   PORTD = 0x48; 		// 5
 //
 //   PORTB = ((0 <<  PB0));
 //   PORTD = 0xC0; 		// 6
 //
 //   PORTB = ((1 <<  PB0));
 //   PORTD = 0x1C; 		// 7
 //
 //   PORTB = ((0 <<  PB0));
 //   PORTD = 0x00; 		// 8
 //
 //   PORTB = ((0 <<  PB0));
 //   PORTD = 0x18; 		// 9
 
  }

  /* . */
  return 0;

}
