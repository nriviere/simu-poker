################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Player/CommandLinePlayer.cpp \
../Player/FoldState.cpp \
../Player/InGameState.cpp \
../Player/OutGameState.cpp \
../Player/Player.cpp \
../Player/PlayerList.cpp \
../Player/PlayerState.cpp \
../Player/PlayerStateList.cpp 

OBJS += \
./Player/CommandLinePlayer.o \
./Player/FoldState.o \
./Player/InGameState.o \
./Player/OutGameState.o \
./Player/Player.o \
./Player/PlayerList.o \
./Player/PlayerState.o \
./Player/PlayerStateList.o 

CPP_DEPS += \
./Player/CommandLinePlayer.d \
./Player/FoldState.d \
./Player/InGameState.d \
./Player/OutGameState.d \
./Player/Player.d \
./Player/PlayerList.d \
./Player/PlayerState.d \
./Player/PlayerStateList.d 


# Each subdirectory must supply rules for building sources it contributes
Player/%.o: ../Player/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


