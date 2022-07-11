cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(blink)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)
set(CMAKE_CROSSCOMPILING ON)
set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_CXX_OBJCOPY avr-objcopy)

set(MCU atmega328p)
# The programmer to use, read avrdude manual for list
set(PROG_TYPE arduino)

# Pass defines to compiler
add_definitions(-DF_CPU=16000000U)

# mmcu MUST be passed to both the compiler and linker, this handle the linker
set(CMAKE_EXE_LINKER_FLAGS -mmcu=atmega328p)

add_compile_options(
    -mmcu=${MCU}
    -Os  # optimize for space
)

file(GLOB SRC_FILES "src/*.cpp") # Load all files in src folder

# Create one target
add_executable(${PROJECT_NAME} ${SRC_FILES})

# add_custom_target(bin ALL avr-g++ -o ${PROJECT_NAME}.bin ${PROJECT_NAME} DEPENDS ${PROJECT_NAME})

# Rename the output to .elf as we will create multiple files
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME}.elf)

# Strip binary for upload
add_custom_target(strip ALL avr-strip ${PROJECT_NAME}.elf DEPENDS ${PROJECT_NAME})

# Transform binary into hex file, we ignore the eeprom segments in the step
add_custom_target(hex ALL avr-objcopy -R .eeprom -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex DEPENDS strip)

# Upload the firmware with avrdude
add_custom_target(upload avrdude -FV -c ${PROG_TYPE} -p ${MCU} -P /dev/ttyACM0 -b 115200 -U flash:w:${PROJECT_NAME}.hex DEPENDS hex)

# Clean extra files
set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "${PROJECT_NAME}.hex;${PROJECT_NAME}.elf")

