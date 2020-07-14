/*
  @author : deepakky2810

  For the following code to work you should connect the led on digital pin 2 of arduino uno, which maps to the PD2 pin of ATmega328P,
  which is controlled by PORT D of the MCU.
*/
#include<avr/io.h>

void setup()
{
  DDRD |= (1 << DDD2);
  PORTD &= ~(1 << PORTD2);
}

void loop()
{
  PORTD |= (1<< PORTD2);  //Turn the led on
  delay(1000);
  PORTD &= ~(1 << PORTD2);  //Turn the led off
  delay(1000);
}
