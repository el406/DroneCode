// communication libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
// servo driver
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>

// extra shit
#include "Communications.h"
#include "pid.c"


// pin definitions
#define CE_PIN 9
#define CSN_PIN 10
enum MotorNumbers {
  MOTOR_1,
  MOTOR_2,
  MOTOR_3,
  MOTOR_4,
};

// PWM driver declaration
Adafruit_PWMServoDriver BLDCManager = Adafruit_PWMServoDriver(0x40);

// Radio declaration
RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "00001";


double static const kP,kI,kD;


States static DroneState;



void runMotors(double m1, double m2, double m3, double m4);

double timemarker = 0.0d;

void setup(){ 
  // setup of controllers    
  BLDCManager.begin();
  BLDCManager.setPWMFreq(50.0f);
  
  // create PID Controller
  t_PIDController controller;


  // communications initialization
  radio.begin();
  
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
  // TODO: add second pipeline for communication back

  // set its own state to grounded
  DroneState = GROUNDED;
  

}

void loop(){
// get control packets, read and follow, then correct with PID

}

