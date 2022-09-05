.PHONY: build upload all clean compilecommands

PROJECT = crystalball

# ARDUINO_CORE := ~/.arduino15/packages/arduino/hardware/avr/1.8.5/cores/arduino
ARDUINO_CORE := ./external

C_FLAGS := -Os -Wall -Werror
CXX_FLAGS := -std=c++17
INCLUDES := -I../common/include/
# INCLUDES += -I$(ARDUINO_CORE)
INCLUDES += -I./includes/

SRCS := $(wildcard ../common/src/*.cpp)
SRCS += $(wildcard ./src/*.cpp)
# SRCS += $(wildcard $(ARDUINO_CORE)/*.cpp)

CPU_FREQ := 16000000UL
CPU_TYPE := atmega328p
PROG_TYPE := arduino

C_FLAGS += -DF_CPU=$(CPU_FREQ)
C_FLAGS += -mmcu=$(CPU_TYPE)

build:
	avr-c++ $(C_FLAGS) $(CXX_FLAGS) $(SRCS) $(INCLUDES) -o $(PROJECT).elf
	avr-strip $(PROJECT).elf
	avr-objcopy -O ihex -R .eeprom $(PROJECT).elf $(PROJECT).hex
	mkdir -p build
	mv $(PROJECT).* ./build

upload:
	sudo avrdude -FV -c $(PROG_TYPE) -p $(CPU_TYPE) -P /dev/ttyACM0 -b 115200 -U flash:w:./build/$(PROJECT).hex

all: build upload

compilecommands:
	compiledb -n make

clean:
	rm -r ./build
