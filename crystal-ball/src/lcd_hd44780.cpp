#include "lcd_hd44780.h"
#include <avr/io.h>
#include <util/delay.h>

hd448780::hd448780(volatile uint8_t& lcd_port, volatile uint8_t& lcd_pin,
                   uint8_t rs_pin, uint8_t enable_pin)
    : LCD_PORT(lcd_port), LCD_PIN(lcd_pin), RS_PIN(rs_pin),
      ENABLE_PIN(enable_pin) {
  LCD_PIN = 0xFF;
  _delay_ms(15); // Wait before LCD activation
  command(0x02); // 4-Bit Control
  command(0x28); // Control Matrix @ 4-Bit
  command(0x0c); // Disable Cursor
  command(0x06); // Move Cursor
  command(0x01); // Clean LCD
  _delay_ms(2);
}

void hd448780::command(const uint8_t &cmd) {
  LCD_PORT = (LCD_PORT & 0x0F) | (cmd & 0xF0);
  LCD_PORT &= ~(1 << RS_PIN);
  LCD_PORT |= (1 << ENABLE_PIN);
  _delay_us(1);
  LCD_PORT &= ~(1 << ENABLE_PIN);
  _delay_us(200);
  LCD_PORT = (LCD_PORT & 0x0F) | (cmd << 4);
  LCD_PORT |= (1 << ENABLE_PIN);
  _delay_us(1);
  LCD_PORT &= ~(1 << ENABLE_PIN);
  _delay_ms(2);
}

void hd448780::clear() {
  command(0x01); // Clear LCD
  _delay_ms(2);  // Wait to clean LCD
  command(0x80); // Move to Position Line 1, Position 1
}

void hd448780::print(const char *str) {
  for (int i = 0; str[i] != 0; i++) {
    LCD_PORT = (LCD_PORT & 0x0F) | (str[i] & 0xF0);
    LCD_PORT |= (1 << RS_PIN);
    LCD_PORT |= (1 << ENABLE_PIN);
    _delay_us(1);
    LCD_PORT &= ~(1 << ENABLE_PIN);
    _delay_us(200);
    LCD_PORT = (LCD_PORT & 0x0F) | (str[i] << 4);
    LCD_PORT |= (1 << ENABLE_PIN);
    _delay_us(1);
    LCD_PORT &= ~(1 << ENABLE_PIN);
    _delay_ms(2);
  }
}

void hd448780::printPos(const uint8_t &row, const uint8_t &pos,
                        const char *str) {
  if (row == 0 && pos < 16) {
    command((pos & 0x0F) | 0x80);
  } else if (row == 1 && pos < 16) {
    command((pos & 0x0F) | 0xC0);
  }
  print(str);
}
