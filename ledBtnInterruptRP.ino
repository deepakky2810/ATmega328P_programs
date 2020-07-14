/*
 * @author : deepakky2810
 * this sketch works for ATmega328P, correctly only if the button is connected to pin 3 of arduino uno or PD3 of ATmega328P,
 *  and the led is connected to pin 2(PD2 of ATmega328P)
 */

#include<avr/io.h>

volatile byte buttonState = 0;
volatile bool isInterruptActive;

ISR (PCINT2_vect)
{
  PCMSK2 = 0x00;
  buttonState = PIND & 0x08;
  isInterruptActive = true;
  
}
void setup() {

  DDRD |= (1 << DDD2) & ~(1 << DDD3);
  PORTD &= ~(1 << DDD2) & ~(1 << DDD3); //sets the led pin to low, and enables the pull-up resistor of PD3

  isInterruptActive = false;

  PCICR = 0x04;
  PCMSK2 = 0x08;

  while(1)
  {
    if(isInterruptActive)
    {
      if(!buttonState)
      {
        PORTD |= (1 << DDD2);
      }
      else
      {
        PORTD &= ~(1 << DDD2);
      }
    }
    isInterruptActive = false;
    PCMSK2 = 0x08;
  }
}

void loop() {
  
}
