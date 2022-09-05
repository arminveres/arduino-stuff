#include "lcd_hd44780.h"
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>

int runtime; // Timer for LCD

int main() {
  hd448780 lcd(PORTD, DDRD, PD0, PD1); // Activate LCD

  lcd.print("WHY NOT WORKING"); // Begin writing at Line 1, Position 1

  while (1) {
    char showruntime[16];
    itoa(runtime, showruntime, 10);
    lcd.command(0xC0); // Go to Line 2, Position 1
    lcd.print("RUNTIME (s): ");
    lcd.print(showruntime);
    _delay_ms(1000);
    runtime++;
  }
}
