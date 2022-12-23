#include <Arduino.h>
#include "LineFollower.h"

LineFollower::LineFollower()
{
  LOG_LineFollower("LineFollower::LineFollower()");
}

void LineFollower::setup()
{
  LOG_LineFollower("LineFollower::setup()");
}

void LineFollower::loop()
{
  LOG_LineFollower_LOOP("LineFollower::loop()");
  /*
  int state = 0;
 int flag = 0;

 int rightIRSensorValue;
 int leftIRSensorValue;
 bool isAutomatic = false;

  if (IrReceiver.decode())
   {
     //int signalReceived = IrReceiver.decodedIRData;
     Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
     IrReceiver.printIRResultShort(&Serial);
     //Serial.print("Code: "); Serial.print(signalReceived, HEX); Serial.println(",\n");
     IrReceiver.resume();
   }
   return;*/
  // if(Serial.available() > 0){
  // command = Serial.read();

  /*if (rightIRSensorValue == LOW && leftIRSensorValue == LOW) {
    //if(LOG){ Serial.write("Skipped\n"); }
    //automatic();
  } else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW) {
    motorMovement.turnRight();
  }

  else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH) {
    motorMovement.turnLeft();
  } else {
    motorMovement.moveForward();
  }

  rightIRSensorValue = digitalRead(RIGHT_LINE_FOLLOW_IR);
  leftIRSensorValue = digitalRead(IR_SENSOR_LEFT);
  }*/
}
