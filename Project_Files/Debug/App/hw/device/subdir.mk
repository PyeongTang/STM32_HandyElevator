################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/hw/device/button.c \
../App/hw/device/fnd.c \
../App/hw/device/handyElevator.c \
../App/hw/device/led.c \
../App/hw/device/stepMotor.c 

OBJS += \
./App/hw/device/button.o \
./App/hw/device/fnd.o \
./App/hw/device/handyElevator.o \
./App/hw/device/led.o \
./App/hw/device/stepMotor.o 

C_DEPS += \
./App/hw/device/button.d \
./App/hw/device/fnd.d \
./App/hw/device/handyElevator.d \
./App/hw/device/led.d \
./App/hw/device/stepMotor.d 


# Each subdirectory must supply rules for building sources it contributes
App/hw/device/%.o App/hw/device/%.su App/hw/device/%.cyclo: ../App/hw/device/%.c App/hw/device/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/work/Harman_4_LJP/ARM/workSpace/HandyElevator/App" -I"C:/work/Harman_4_LJP/ARM/workSpace/HandyElevator/App/common" -I"C:/work/Harman_4_LJP/ARM/workSpace/HandyElevator/App/hw" -I"C:/work/Harman_4_LJP/ARM/workSpace/HandyElevator/App/hw/device" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App-2f-hw-2f-device

clean-App-2f-hw-2f-device:
	-$(RM) ./App/hw/device/button.cyclo ./App/hw/device/button.d ./App/hw/device/button.o ./App/hw/device/button.su ./App/hw/device/fnd.cyclo ./App/hw/device/fnd.d ./App/hw/device/fnd.o ./App/hw/device/fnd.su ./App/hw/device/handyElevator.cyclo ./App/hw/device/handyElevator.d ./App/hw/device/handyElevator.o ./App/hw/device/handyElevator.su ./App/hw/device/led.cyclo ./App/hw/device/led.d ./App/hw/device/led.o ./App/hw/device/led.su ./App/hw/device/stepMotor.cyclo ./App/hw/device/stepMotor.d ./App/hw/device/stepMotor.o ./App/hw/device/stepMotor.su

.PHONY: clean-App-2f-hw-2f-device

