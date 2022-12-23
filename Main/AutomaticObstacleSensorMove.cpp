#include <Arduino.h> 
#include "AutomaticObstacleSensorMove.h"

void AutomaticObstacleSensorMove::setup() {
    #ifdef LOG_IRLineSensor
    Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__func__); Serial.write("\n");   
    #endif

}    

AutomaticObstacleSensorMove::AutomaticObstacleSensorMove() {
    #ifdef LOG_IRLineSensor
    Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__func__); Serial.write("\n");   
    #endif
}
void AutomaticObstacleSensorMove::loop() {
    #ifdef LOG_IRLineSensor
    Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__func__); Serial.write("\n");   
    #endif

}    
void AutomaticObstacleSensorMove::automatic() {
 /* if (!isAutomatic) return;
  int distance = ultrasonicOperations.UltrasonicRead();
  
  if (LOG) {
    Serial.print("automatic distance\n");
  }
  int distanceR = 0;
  int distanceL = 0;
  delay(1000);

  if (distance <= REVERCE_DISTANCE) {
    motorMovement.Stop();
    delay(100);
    motorMovement.moveBackward();
    delay(200);
    motorMovement.Stop();
    delay(200);
    distanceR = ultrasonicOperations.lookRight();
    delay(200);
    distanceL = ultrasonicOperations.lookLeft();
    delay(200);

    if (distanceR >= distanceL) {
      motorMovement.turnRight();
      motorMovement.Stop();
    } else {
      motorMovement.turnLeft();
      motorMovement.Stop();
    }
  } else {
    motorMovement.moveForward();
  }*/
}