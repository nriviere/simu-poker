################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Cards/Card.cpp \
../Cards/Deck.cpp \
../Cards/HandPower2.cpp 

OBJS += \
./Cards/Card.o \
./Cards/Deck.o \
./Cards/HandPower2.o 

CPP_DEPS += \
./Cards/Card.d \
./Cards/Deck.d \
./Cards/HandPower2.d 


# Each subdirectory must supply rules for building sources it contributes
Cards/%.o: ../Cards/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/viande/workspace/Poker/Actions" -I"/home/viande/workspace/Poker/Cards" -I"/home/viande/workspace/Poker/GameState" -I"/home/viande/workspace/Poker/Player" -I"/home/viande/workspace/Poker" -I"/home/viande/workspace/Poker/TinyXml" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


