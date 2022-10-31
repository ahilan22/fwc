#include <avr/io.h>
#include <stdbool.h>

int main(void) 
{
		bool A, B, Y;
		DDRB = 0x20;	// setting D13 as output, D8,9 as input
		PORTB = 0x00; 		// internal pull up
		while(1)
		{
				A = (PINB & (1 << PINB0)) == (1 << PINB0);	// reading input from D8 into A
				B = (PINB & (1 << PINB1)) == (1 << PINB1);	// reading input from D9 into B
				Y = ((A&B)|((!A)&(!B)));		// xnor logic
				PORTB = (Y << PB5); // output Y to D13 
		}
		return 0;
}
