/*
 * @author : deepakky2810
 * this sketch works for ATmega328P, correctly only if the button is connected to pin 3 of arduino uno or PD3 of ATmega328P,
 *  and the led is connected to pin 2(PD2 of ATmega328P)
 */

#include<avr/io.h>

byte buttonState = 0;
void setup() {

  DDRD |= (1 << DDD2) & ~(1 << DDD3);
  PORTD &= ~(1 << DDD2) & ~(1 << DDD3); //sets the led pin to low, and enables the pull-up resistor of PD3

}

void loop() {
  buttonState |= (1 << PIND3);  //reading the state of button
  delay(50);  //for button debouncing

  //check if button is pressed(when pressed the input to I/O pin PD3 is 0)
  if(!buttonState)
  {
    PORTD |= (1 << DDD2);
  }
  else
  {
    PORTD &= ~(1 << DDD2);
  }
}
