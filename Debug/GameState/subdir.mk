################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GameState/Flop.cpp \
../GameState/GameState.cpp \
../GameState/GameStateList.cpp \
../GameState/Pot.cpp \
../GameState/Preflop.cpp \
../GameState/River.cpp \
../GameState/Turn.cpp 

OBJS += \
./GameState/Flop.o \
./GameState/GameState.o \
./GameState/GameStateList.o \
./GameState/Pot.o \
./GameState/Preflop.o \
./GameState/River.o \
./GameState/Turn.o 

CPP_DEPS += \
./GameState/Flop.d \
./GameState/GameState.d \
./GameState/GameStateList.d \
./GameState/Pot.d \
./GameState/Preflop.d \
./GameState/River.d \
./GameState/Turn.d 


# Each subdirectory must supply rules for building sources it contributes
GameState/%.o: ../GameState/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/viande/workspace2/Poker/Actions" -I"/home/viande/workspace2/Poker/Cards" -I"/home/viande/workspace2/Poker/GameState" -I"/home/viande/workspace2/Poker/Player" -I"/home/viande/workspace2/Poker/TinyXml" -I"/home/viande/workspace2/Poker" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


