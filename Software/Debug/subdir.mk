################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application.c \
../Keypad.c \
../Keypad_config.c \
../LCD.c \
../LCD_config.c 

OBJS += \
./Application.o \
./Keypad.o \
./Keypad_config.o \
./LCD.o \
./LCD_config.o 

C_DEPS += \
./Application.d \
./Keypad.d \
./Keypad_config.d \
./LCD.d \
./LCD_config.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


