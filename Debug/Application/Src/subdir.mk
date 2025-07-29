################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/Src/Plant_Sensor_Data_Simulate.c \
../Application/Src/notification.c \
../Application/Src/plant_profile.c \
../Application/Src/sensor_data_classifier.c \
../Application/Src/time_stamped_state_data.c 

OBJS += \
./Application/Src/Plant_Sensor_Data_Simulate.o \
./Application/Src/notification.o \
./Application/Src/plant_profile.o \
./Application/Src/sensor_data_classifier.o \
./Application/Src/time_stamped_state_data.o 

C_DEPS += \
./Application/Src/Plant_Sensor_Data_Simulate.d \
./Application/Src/notification.d \
./Application/Src/plant_profile.d \
./Application/Src/sensor_data_classifier.d \
./Application/Src/time_stamped_state_data.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Src/%.o Application/Src/%.su Application/Src/%.cyclo: ../Application/Src/%.c Application/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"E:/Embedded_Engineer_Projects/Smart_Plant_Monitoring/Smart_Plant_Monitoring_App/Driver/Inc" -I"E:/Embedded_Engineer_Projects/Smart_Plant_Monitoring/Smart_Plant_Monitoring_App/Application/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-Src

clean-Application-2f-Src:
	-$(RM) ./Application/Src/Plant_Sensor_Data_Simulate.cyclo ./Application/Src/Plant_Sensor_Data_Simulate.d ./Application/Src/Plant_Sensor_Data_Simulate.o ./Application/Src/Plant_Sensor_Data_Simulate.su ./Application/Src/notification.cyclo ./Application/Src/notification.d ./Application/Src/notification.o ./Application/Src/notification.su ./Application/Src/plant_profile.cyclo ./Application/Src/plant_profile.d ./Application/Src/plant_profile.o ./Application/Src/plant_profile.su ./Application/Src/sensor_data_classifier.cyclo ./Application/Src/sensor_data_classifier.d ./Application/Src/sensor_data_classifier.o ./Application/Src/sensor_data_classifier.su ./Application/Src/time_stamped_state_data.cyclo ./Application/Src/time_stamped_state_data.d ./Application/Src/time_stamped_state_data.o ./Application/Src/time_stamped_state_data.su

.PHONY: clean-Application-2f-Src

