################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Game.cpp \
../HandPower.cpp \
../MySqlApi.cpp \
../test.cpp 

OBJS += \
./Game.o \
./HandPower.o \
./MySqlApi.o \
./test.o 

CPP_DEPS += \
./Game.d \
./HandPower.d \
./MySqlApi.d \
./test.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/viande/workspace/Poker/Actions" -I"/home/viande/workspace/Poker/Cards" -I"/home/viande/workspace/Poker/GameState" -I"/home/viande/workspace/Poker/Player" -I"/home/viande/workspace/Poker" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

