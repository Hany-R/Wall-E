#include "MotorControl.h"

// Global settings
const int MOVE_SPEED = 180; 
const int TEST_DELAY = 1500; 

void setup() {
  Serial.begin(115200);
  Serial.println("System Booting... Initializing Motors.");
  
  initMotors();
  
  Serial.println("Test starting in 3 seconds...");
  delay(3000);
}

void loop() {
  Serial.println("1. Forward");
  moveForward(MOVE_SPEED);
  delay(TEST_DELAY);

  Serial.println("2. Backward");
  moveBackward(MOVE_SPEED);
  delay(TEST_DELAY);

  Serial.println("3. Strafe Right");
  strafeRight(MOVE_SPEED);
  delay(TEST_DELAY);

  Serial.println("4. Strafe Left");
  strafeLeft(MOVE_SPEED);
  delay(TEST_DELAY);

  Serial.println("5. Spin Clockwise");
  spinClockwise(MOVE_SPEED);
  delay(TEST_DELAY);

  Serial.println("Stopping...");
  stop();
  
  // Wait 10 seconds before restarting the test
  delay(10000);
}