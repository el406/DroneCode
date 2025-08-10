// communication libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
// servo driver
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>

double static const P = 0;
double static const I = 0;
double static const D = 0;


void setup(){
// setup of controllers and comms    
// set its own state to grounded

}

void loop(){
// get control packets, read and follow, then correct with PID
}

double* PIDCorrection(float setpoint, float gyroReading){
    return NULL;
}
