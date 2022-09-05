/*
 * These are definitions akin to the Arduino Library, for ease of use
 */

#ifndef ArduinoUno
#include <stdint.h>

namespace Arduino {
namespace Uno {

static constexpr uint8_t INPUT = 0;
static constexpr uint8_t OUTPUT = 1;
static constexpr uint8_t INPUT_PULLUP = 2;

static constexpr uint8_t LOW = 0;
static constexpr uint8_t HIGH = 1;

} // namespace Uno
} // namespace Arduino

#endif // !ArduinoUno
