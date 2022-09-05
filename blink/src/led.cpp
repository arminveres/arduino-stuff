#include "arduino.h"
#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <util/delay.h>

int main(int argc, char *argv[]) {

  // set PORTB5  as an output
  // DDRB |= (1 << DDB5);
  DDRB |= _BV(DDB5);

  while (1) {
    // set PORTB5 and wait
    // PORTB |= (1 << PORTB5);
    PORTB |= _BV(PORTB5);
    _delay_ms(100);

    // reset and wait
    // PORTB &= ~(1 << PORTB5);
    PORTB &= ~_BV(PORTB5);
    _delay_ms(100);
  }
  return 0;
}
