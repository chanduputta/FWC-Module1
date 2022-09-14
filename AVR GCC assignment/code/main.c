//Reliaze the 4 to 2 encoder 
//on the display
#include <avr/io.h>
#include <stdbool.h>
 
int main (void)
{
	
	
 //set PD4 as output pin 0b00010000 (binary)
  DDRD   |= 0b00010000; // portD  pin 4 - ON
  //set PB5 as output pin
  DDRB    |= ((1 << DDB5)); // portB pin 13 due to port difference we take separate declaration
 PORTB = 0b01111100;
  while (1) {
//turn PB0 off
int Q0,Q1; //outputs
bool D0,D1,D2,D3; //inputs D0 is not impactable in this encoder setup
 D0 = 1; 
 D1 = 1;
 D2 = 0;
 D3 = 0;
Q0 = D3|D1;
    PORTB = ((Q0 <<  PB5)); //pin13
Q1 = D3|D2;			
    PORTD = ((Q1 <<  PD4));   //pin4
  }

  /* . */
  return 0;

}
