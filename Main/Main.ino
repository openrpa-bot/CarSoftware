#include <Arduino.h>

#include "CommonInclude.h"

#include "AutomaticObstacleSensorMove.h"
#include "BluetoothOperations.h"
#include "IRRemoteReceiver.h"
#include "LedOperations.h"
#include "LeftIRLineSensor.h"
#include "LineFollower.h"
#include "MotorMovement.h"
#include "RightIRLineSensor.h"
#include "ServoOperations.h"
#include "UltrasonicOperations.h"

AutomaticObstacleSensorMove *automaticObstacleSensorMove = new AutomaticObstacleSensorMove();
BluetoothOperations *bluetoothOperations = new BluetoothOperations();
IRRemoteReceiver *iRRemoteReceiver = new IRRemoteReceiver();
LedOperations *ledOperations = new LedOperations();
LeftIRLineSensor *leftIRLineSensor = new LeftIRLineSensor();
LineFollower *lineFollower = new LineFollower();
MotorMovement *motorMovement = new MotorMovement();
RightIRLineSensor *rightIRLineSensor = new RightIRLineSensor();
ServoOperations *servoOperations = new ServoOperations();
UltrasonicOperations *ultrasonicOperations = new UltrasonicOperations();
OperationRequest *operationRequest = new OperationRequest();

void setup()
{
  Serial.begin(SERIAL_PORT);

  LOG_Main("BEGIN");

  automaticObstacleSensorMove->setup();
  bluetoothOperations->setup();
  iRRemoteReceiver->setup();
  ledOperations->setup();
  leftIRLineSensor->setup();
  lineFollower->setup();
  motorMovement->setup();
  rightIRLineSensor->setup();
  servoOperations->setup();
  ultrasonicOperations->setup();

  LOG_Main("END");
}

void loop()
{
  LOG_Main_LOOP("Loop Begin");

  /*
  automaticObstacleSensorMove->loop();
  bluetoothOperations->loop();
  iRRemoteReceiver->loop();
  ledOperations->loop();
  leftIRLineSensor->loop();
  lineFollower->loop();
  motorMovement->loop();
  rightIRLineSensor->loop();
  servoOperations->loop();
  ultrasonicOperations->loop();
*/
  LOG_Main_LOOP("Loop End");

    if (!bluetoothOperations->CheckBluetoothOperationRequest(operationRequest))
    {
      // LOG("Not received any messages");
      //Serial.print(operationRequest->operationType);
      //Serial.print(":");
      //Serial.println(operationRequest->operationRequestData.Speed);
    }
    else
    {
      //LOG(operationRequest->operationType);

      Serial.print(operationRequest->operationType);
      Serial.print(":");
      Serial.println(operationRequest->operationRequestData.Speed);
      
    }
  delay(100);
}
