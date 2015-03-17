################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/agence.cpp \
../src/agent.cpp \
../src/camion.cpp \
../src/client.cpp \
../src/confirmation.cpp \
../src/etat.cpp \
../src/listeSite.cpp \
../src/main.cpp \
../src/message.cpp \
../src/reservation.cpp \
../src/site.cpp \
../src/vehicule.cpp \
../src/voiture.cpp 

OBJS += \
./src/agence.o \
./src/agent.o \
./src/camion.o \
./src/client.o \
./src/confirmation.o \
./src/etat.o \
./src/listeSite.o \
./src/main.o \
./src/message.o \
./src/reservation.o \
./src/site.o \
./src/vehicule.o \
./src/voiture.o 

CPP_DEPS += \
./src/agence.d \
./src/agent.d \
./src/camion.d \
./src/client.d \
./src/confirmation.d \
./src/etat.d \
./src/listeSite.d \
./src/main.d \
./src/message.d \
./src/reservation.d \
./src/site.d \
./src/vehicule.d \
./src/voiture.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


