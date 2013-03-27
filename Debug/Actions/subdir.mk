################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Actions/Action.cpp \
../Actions/AllIn.cpp \
../Actions/Call.cpp \
../Actions/Check.cpp \
../Actions/Fold.cpp \
../Actions/Raise.cpp 

OBJS += \
./Actions/Action.o \
./Actions/AllIn.o \
./Actions/Call.o \
./Actions/Check.o \
./Actions/Fold.o \
./Actions/Raise.o 

CPP_DEPS += \
./Actions/Action.d \
./Actions/AllIn.d \
./Actions/Call.d \
./Actions/Check.d \
./Actions/Fold.d \
./Actions/Raise.d 


# Each subdirectory must supply rules for building sources it contributes
Actions/%.o: ../Actions/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/viande/workspace/Poker/Actions" -I"/home/viande/workspace/Poker/Cards" -I"/home/viande/workspace/Poker/GameState" -I"/home/viande/workspace/Poker/Player" -I"/home/viande/workspace/Poker" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


