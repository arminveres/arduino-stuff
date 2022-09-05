/*
 * Based on AEQ-WEB
 * https://www.aeq-web.com/atmega328-4bit-16x2-lcd-display-amtel-studio-c/?lang=en
 */

#ifndef HD448780_H_

#include <avr/io.h>
#include <stdint.h>

class hd448780 {
public:
  volatile uint8_t &LCD_PORT;
  volatile uint8_t &LCD_PIN;
  uint8_t RS_PIN;
  uint8_t ENABLE_PIN;
hd448780(volatile uint8_t& lcd_port, volatile uint8_t& lcd_pin,
                   uint8_t rs_pin, uint8_t enable_pin);

  /*
    Sr.No.  Hex Code  Command to LCD instruction Register
    1       01        Clear display screen
    2       02        Return home
    3       04        Decrement cursor (shift cursor to the left)
    4       06        Increment cursor (shift cursor to the right)
    5       05        Shift display right
    6       07        Shift display left
    7       08        Display off, cursor off
    8       0A        Display off, cursor on
    9       0C        Display on, cursor off
    10      0E        Display on, cursor blinking
    11      0F        Display on, cursor blinking
    12      10        Shift cursor position to left
    13      14        Shift cursor position to the right
    14      18        Shift the entire display to the left
    15      1C        Shift the entire display to the right
    16      80        Force cursor to the beginning (1st line)
    17      C0        Force cursor to the beginning (2nd line)
    18      38        Two lines and 5×7 matrix (8-bit mode)
    18      30        1 line and 5×7 matrix (8-bit mode)
    18      20        1 line and 5×7 matrix (4-bit mode)
    18      28        Two lines and 5×7 matrix (4-bit mode)
  */
  void command(const uint8_t &cmd);
  void clear();
  void print(const char *str);
  void printPos(const uint8_t &row, const uint8_t &pos, const char *str);
};

#endif // !HD448780_H_
