################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/confirmation.cpp \
../src/main.cpp \
../src/message.cpp \
../src/reservation.cpp 

OBJS += \
./src/confirmation.o \
./src/main.o \
./src/message.o \
./src/reservation.o 

CPP_DEPS += \
./src/confirmation.d \
./src/main.d \
./src/message.d \
./src/reservation.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


