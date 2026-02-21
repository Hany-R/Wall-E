#include "MotorControl.h"

const int FL_FWD = 12; const int FL_BWD = 13;
const int FR_FWD = 14; const int FR_BWD = 27;
const int BL_FWD = 26; const int BL_BWD = 25;
const int BR_FWD = 33; const int BR_BWD = 32;

void initMotors() {
    pinMode(FL_FWD, OUTPUT); pinMode(FL_BWD, OUTPUT);
    pinMode(FR_FWD, OUTPUT); pinMode(FR_BWD, OUTPUT);
    pinMode(BL_FWD, OUTPUT); pinMode(BL_BWD, OUTPUT);
    pinMode(BR_FWD, OUTPUT); pinMode(BR_BWD, OUTPUT);
    stop(); 
}

void stop() {
    analogWrite(FL_FWD, 0); analogWrite(FL_BWD, 0);
    analogWrite(FR_FWD, 0); analogWrite(FR_BWD, 0);
    analogWrite(BL_FWD, 0); analogWrite(BL_BWD, 0);
    analogWrite(BR_FWD, 0); analogWrite(BR_BWD, 0);
}

void moveForward(int speed) {
    analogWrite(FL_FWD, speed); analogWrite(FL_BWD, 0);
    analogWrite(FR_FWD, speed); analogWrite(FR_BWD, 0);
    analogWrite(BL_FWD, speed); analogWrite(BL_BWD, 0);
    analogWrite(BR_FWD, speed); analogWrite(BR_BWD, 0);
}

void moveBackward(int speed) {
    analogWrite(FL_FWD, 0); analogWrite(FL_BWD, speed);
    analogWrite(FR_FWD, 0); analogWrite(FR_BWD, speed);
    analogWrite(BL_FWD, 0); analogWrite(BL_BWD, speed);
    analogWrite(BR_FWD, 0); analogWrite(BR_BWD, speed);
}

void strafeLeft(int speed) {
    analogWrite(FL_FWD, 0);     analogWrite(FL_BWD, speed);
    analogWrite(FR_FWD, speed); analogWrite(FR_BWD, 0);
    analogWrite(BL_FWD, speed); analogWrite(BL_BWD, 0);
    analogWrite(BR_FWD, 0);     analogWrite(BR_BWD, speed);
}

void strafeRight(int speed) {
    analogWrite(FL_FWD, speed); analogWrite(FL_BWD, 0);
    analogWrite(FR_FWD, 0);     analogWrite(FR_BWD, speed);
    analogWrite(BL_FWD, 0);     analogWrite(BL_BWD, speed);
    analogWrite(BR_FWD, speed); analogWrite(BR_BWD, 0);
}

void spinClockwise(int speed) {
    analogWrite(FL_FWD, speed); analogWrite(FL_BWD, 0);
    analogWrite(BL_FWD, speed); analogWrite(BL_BWD, 0);
    analogWrite(FR_FWD, 0);     analogWrite(FR_BWD, speed);
    analogWrite(BR_FWD, 0);     analogWrite(BR_BWD, speed);
}

void spinAnticlockwise(int speed) {
    analogWrite(FL_FWD, 0);     analogWrite(FL_BWD, speed);
    analogWrite(BL_FWD, 0);     analogWrite(BL_BWD, speed);
    analogWrite(FR_FWD, speed); analogWrite(FR_BWD, 0);
    analogWrite(BR_FWD, speed); analogWrite(BR_BWD, 0);
}

