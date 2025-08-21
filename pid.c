#include <stdio.h>

typedef struct PIDController {
  double kP, kI, kD, proportional, integral, derivative, previousError, dt,
      minimumSetpoint, maximumSetpoint;
  void *setPointLink;

} t_PIDController;

void initializePIDController(t_PIDController *controller, double kP, double kI,
                             double kD, double minimumSetpoint,
                             double maximumSetpoint) {
  // define constants
  controller->kP = kP;
  controller->kI = kI;
  controller->kD = kD;
  controller->maximumSetpoint = maximumSetpoint;
  controller->minimumSetpoint = minimumSetpoint;

  controller->setPointLink = NULL;
}

void updatePID(t_PIDController *controller, double setpoint, double sensorReading,
               double *realoutput) {
  // find error
  double error = setpoint - sensorReading;

  // proportional correction
  controller->proportional = controller->kP * error;

  // Integral correction (cumulative correction)
  controller->integral += controller->kI * error;

  // clamping
  if (controller->integral > controller->maximumSetpoint) {
    controller->integral = controller->maximumSetpoint;
  } else if (controller->integral < controller->minimumSetpoint) {
    controller->integral = controller->minimumSetpoint;
  }

  // derivative correction
  if (controller->dt > 0) {
    controller->derivative =
        controller->kD * (error - controller->previousError) / controller->dt;
  }

  *realoutput =
      controller->proportional + controller->integral + controller->derivative;

  controller->previousError = error;
}

