#include <Arduino.h>
#include "AutomaticObstacleSensorMove.h"

AutomaticObstacleSensorMove::AutomaticObstacleSensorMove()
{
  LOG_AutomaticObstacleSensorMove("AutomaticObstacleSensorMove::AutomaticObstacleSensorMove()");
}

void AutomaticObstacleSensorMove::setup()
{
  LOG_AutomaticObstacleSensorMove("AutomaticObstacleSensorMove::setup()");
}

void AutomaticObstacleSensorMove::loop()
{
  LOG_AutomaticObstacleSensorMove_LOOP("AutomaticObstacleSensorMove::loop()");
}

void AutomaticObstacleSensorMove::automatic()
{
  LOG_AutomaticObstacleSensorMove("AutomaticObstacleSensorMove::automatic()");
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