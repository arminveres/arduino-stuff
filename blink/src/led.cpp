#include <avr/io.h>
#include <util/delay.h>

int main(int argc, char *argv[]) {

  // set PORTB5  as an output
  DDRB |= (1 << DDB5);

  while (1) {
    // set PORTB5 and wait
    PORTB |= (1 << PORTB5);
    _delay_ms(500);

    // reset and wait
    PORTB &= ~(1 << PORTB5);
    _delay_ms(500);
  }
  return 0;
}
