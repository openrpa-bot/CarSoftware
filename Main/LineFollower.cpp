#include <Arduino.h> 
#include "LineFollower.h"

void LineFollower::setup() {
    #ifdef LOG_LedOperations
    Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__func__); Serial.write("\n");   
    #endif

}    

LineFollower::LineFollower() {

    #ifdef LOG_LedOperations
    Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__func__); Serial.write("\n");   
    #endif

}    
void LineFollower::loop() {
    #ifdef LOG_IRLineSensor
    Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__func__); Serial.write("\n");   
    #endif
 /*if (IrReceiver.decode())
  {
    //int signalReceived = IrReceiver.decodedIRData;
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.printIRResultShort(&Serial);
    //Serial.print("Code: "); Serial.print(signalReceived, HEX); Serial.println(",\n");
    IrReceiver.resume();
  }
  return;*/
  //if(Serial.available() > 0){
  //command = Serial.read();
  
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
