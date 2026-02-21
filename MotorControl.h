#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Arduino.h>

// Function Declarations
void initMotors();
void stop();
void moveForward(int speed);
void moveBackwars(int speed);
void strafeLeft(int speed);
void straferight(int speed);
void spinClockwise(int speed);
void spinAnticlockwise(int speed);

#endif