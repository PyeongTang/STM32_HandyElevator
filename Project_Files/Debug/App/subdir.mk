################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/ap.c 

OBJS += \
./App/ap.o 

C_DEPS += \
./App/ap.d 


# Each subdirectory must supply rules for building sources it contributes
App/%.o App/%.su App/%.cyclo: ../App/%.c App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/work/Harman_4_LJP/ARM/workSpace/HandyElevator/App" -I"C:/work/Harman_4_LJP/ARM/workSpace/HandyElevator/App/common" -I"C:/work/Harman_4_LJP/ARM/workSpace/HandyElevator/App/hw" -I"C:/work/Harman_4_LJP/ARM/workSpace/HandyElevator/App/hw/device" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App

clean-App:
	-$(RM) ./App/ap.cyclo ./App/ap.d ./App/ap.o ./App/ap.su

.PHONY: clean-App

