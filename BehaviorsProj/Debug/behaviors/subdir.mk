################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../behaviors/Behavior.cpp \
../behaviors/GoBack.cpp \
../behaviors/GoForward.cpp \
../behaviors/TurnLeft.cpp \
../behaviors/TurnRight.cpp 

OBJS += \
./behaviors/Behavior.o \
./behaviors/GoBack.o \
./behaviors/GoForward.o \
./behaviors/TurnLeft.o \
./behaviors/TurnRight.o 

CPP_DEPS += \
./behaviors/Behavior.d \
./behaviors/GoBack.d \
./behaviors/GoForward.d \
./behaviors/TurnLeft.d \
./behaviors/TurnRight.d 


# Each subdirectory must supply rules for building sources it contributes
behaviors/%.o: ../behaviors/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/local/include/player-2.0 -include/usr/local/include/player-2.0/libplayerc++/playerc++.h -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


