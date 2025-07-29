################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Driver/Src/sys_tick.c \
../Driver/Src/uart.c 

OBJS += \
./Driver/Src/sys_tick.o \
./Driver/Src/uart.o 

C_DEPS += \
./Driver/Src/sys_tick.d \
./Driver/Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Driver/Src/%.o Driver/Src/%.su Driver/Src/%.cyclo: ../Driver/Src/%.c Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"E:/Embedded_Engineer_Projects/Smart_Plant_Monitoring/Smart_Plant_Monitoring_App/Driver/Inc" -I"E:/Embedded_Engineer_Projects/Smart_Plant_Monitoring/Smart_Plant_Monitoring_App/Application/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Driver-2f-Src

clean-Driver-2f-Src:
	-$(RM) ./Driver/Src/sys_tick.cyclo ./Driver/Src/sys_tick.d ./Driver/Src/sys_tick.o ./Driver/Src/sys_tick.su ./Driver/Src/uart.cyclo ./Driver/Src/uart.d ./Driver/Src/uart.o ./Driver/Src/uart.su

.PHONY: clean-Driver-2f-Src

