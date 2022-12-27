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

BluetoothOperations *bluetoothOperations = new BluetoothOperations();
IRRemoteReceiver *iRRemoteReceiver = new IRRemoteReceiver();
LedOperations *ledOperations = new LedOperations();
LeftIRLineSensor *leftIRLineSensor = new LeftIRLineSensor();
MotorMovement *motorMovement = new MotorMovement();
RightIRLineSensor *rightIRLineSensor = new RightIRLineSensor();
ServoOperations *servoOperations = new ServoOperations();
UltrasonicOperations *ultrasonicOperations = new UltrasonicOperations(servoOperations);
OperationRequest *operationRequest = new OperationRequest();
AutomaticObstacleSensorMove *automaticObstacleSensorMove = new AutomaticObstacleSensorMove(motorMovement, ultrasonicOperations);
LineFollower *lineFollower = new LineFollower(leftIRLineSensor, rightIRLineSensor, motorMovement);

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

  Serial.println("Setup finished.");

  LOG_Main("END");
}

void loop()
{
  LOG_Main_LOOP("Loop Begin");

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

  LOG_Main_LOOP("Loop End");

  if (bluetoothOperations->CheckBluetoothOperationRequest(operationRequest, true))
  {
    SERIAL_PRINT("Received BlueTooth Command(Type, Speed):");
    SERIAL_PRINT(operationRequest->operationType);
    SERIAL_PRINT(",");
    SERIAL_PRINTLN(operationRequest->operationRequestData.Speed);
  } else if (bluetoothOperations->CheckBluetoothOperationRequest(operationRequest, false))
  {
    SERIAL_PRINT("Received Serial Command(Type, Speed):");
    SERIAL_PRINT(operationRequest->operationType);
    SERIAL_PRINT(",");
    SERIAL_PRINTLN(operationRequest->operationRequestData.Speed);
  } else if (iRRemoteReceiver->CheckIRRemoteOperationRequest(operationRequest))
  {
    SERIAL_PRINT("Received IR Command(Type, Speed):");
    SERIAL_PRINT(operationRequest->operationType);
    SERIAL_PRINT(",");
    SERIAL_PRINTLN(operationRequest->operationRequestData.Speed);
  }

  if (!(operationRequest->operationType == OperationType::None))
  {
    switch (operationRequest->operationType)
    {
    case OperationType::MoveForward:
      motorMovement->moveForward();
      break;
    case OperationType::Speed:
      motorMovement->Speed(operationRequest);
      break;
    case OperationType::MoveBackword:
      motorMovement->moveBackward();
      break;
    case OperationType::LeftTurn:
      motorMovement->turnLeft();
      break;
    case OperationType::RightTurn:
      motorMovement->turnRight();
      break;
    case OperationType::DeeperOff:
      ledOperations->DeeparOff();
      break;
    case OperationType::DeeperOn:
      ledOperations->DeeparOn();
      break;
    case OperationType::StopMoveing:
      motorMovement->Stop();
      break;
    case OperationType::BackLightOff:
      ledOperations->BackLightOff();
      break;
    case OperationType::BackLightOn:
      ledOperations->BackLightOn();
      break;
    case OperationType::HendLightOn:
      ledOperations->HendLightOn();
      break;
    case OperationType::HendLightOff:
      ledOperations->HendLightOff();
      break;
    case OperationType::CruseControlMode:
      lineFollower->LineFollowerModeRelease();
      automaticObstacleSensorMove->CruseControlModeStart();
      break;
    case OperationType::LineFollowerMode:
      automaticObstacleSensorMove->CruseControlModeRelease();
      lineFollower->LineFollowerModeActivate();
      break;
    default:
      SERIAL_PRINT("Received Undefined Command(Type, Speed):");
      SERIAL_PRINT(operationRequest->operationType);
      SERIAL_PRINT(",");
      SERIAL_PRINTLN(operationRequest->operationRequestData.Speed);
      break;
    }
  }
  delay(100);
}
