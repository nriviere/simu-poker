################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TinyXml/tinystr.cpp \
../TinyXml/tinyxml.cpp \
../TinyXml/tinyxmlerror.cpp \
../TinyXml/tinyxmlparser.cpp 

OBJS += \
./TinyXml/tinystr.o \
./TinyXml/tinyxml.o \
./TinyXml/tinyxmlerror.o \
./TinyXml/tinyxmlparser.o 

CPP_DEPS += \
./TinyXml/tinystr.d \
./TinyXml/tinyxml.d \
./TinyXml/tinyxmlerror.d \
./TinyXml/tinyxmlparser.d 


# Each subdirectory must supply rules for building sources it contributes
TinyXml/%.o: ../TinyXml/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/viande/workspace/Poker/Actions" -I"/home/viande/workspace/Poker/Cards" -I"/home/viande/workspace/Poker/GameState" -I"/home/viande/workspace/Poker/Player" -I"/home/viande/workspace/Poker" -I"/home/viande/workspace/Poker/TinyXml" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


