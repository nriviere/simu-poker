################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Player/CommandLinePlayer.cpp \
../Player/IAPlayer.cpp \
../Player/Player.cpp \
../Player/PlayerList.cpp \
../Player/PlayerParser.cpp \
../Player/PlayerState.cpp \
../Player/PlayerStatistics.cpp \
../Player/RandomPlayer.cpp 

OBJS += \
./Player/CommandLinePlayer.o \
./Player/IAPlayer.o \
./Player/Player.o \
./Player/PlayerList.o \
./Player/PlayerParser.o \
./Player/PlayerState.o \
./Player/PlayerStatistics.o \
./Player/RandomPlayer.o 

CPP_DEPS += \
./Player/CommandLinePlayer.d \
./Player/IAPlayer.d \
./Player/Player.d \
./Player/PlayerList.d \
./Player/PlayerParser.d \
./Player/PlayerState.d \
./Player/PlayerStatistics.d \
./Player/RandomPlayer.d 


# Each subdirectory must supply rules for building sources it contributes
Player/%.o: ../Player/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/viande/workspace2/Poker/Actions" -I"/home/viande/workspace2/Poker/Cards" -I"/home/viande/workspace2/Poker/GameState" -I"/home/viande/workspace2/Poker/Player" -I"/home/viande/workspace2/Poker/TinyXml" -I"/home/viande/workspace2/Poker" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


