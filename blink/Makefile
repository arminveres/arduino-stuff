.PHONY: build upload all clean compilecommands

PROJECT = blink

C_FLAGS := -Os
CXX_FLAGS := -std=c++20
INCLUDES := -I../common/include/
SRCS := $(wildcard ../common/src/*.cpp)

CPU_FREQ := 16000000UL
CPU_TYPE := atmega328p
PROG_TYPE := arduino

C_FLAGS += -DF_CPU=$(CPU_FREQ)
C_FLAGS += -mmcu=$(CPU_TYPE)

SRCS += $(wildcard ./src/*.cpp)

build:
	avr-c++ $(C_FLAGS) $(CXX_FLAGS) $(SRCS) $(INCLUDES) -o $(PROJECT).elf
	avr-strip $(PROJECT).elf
	# remove eeprom, output ihex
	avr-objcopy -R .eeprom -O ihex $(PROJECT).elf $(PROJECT).hex
	mkdir -p build
	mv $(PROJECT).* ./build

upload:
	# -b serial baud reate
	sudo avrdude -FV -c $(PROG_TYPE) -p $(CPU_TYPE) -P /dev/ttyACM0 -b 115200 -U flash:w:./build/$(PROJECT).hex

all: build upload

compilecommands:
	compiledb -n make

clean:
	rm -r ./build
