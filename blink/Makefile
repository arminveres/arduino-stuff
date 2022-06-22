default:
	avr-c++ -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o led.o led.cpp
	avr-c++ -o led.bin led.o
	avr-objcopy -O ihex -R .eeprom led.bin led.hex
	sudo avrdude -FV -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:led.hex
	mkdir .build
	mv led.o led.hex led.bin ./.build

clean:
	rm -r ./.build
