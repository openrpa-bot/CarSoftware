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

  if (bluetoothOperations->CheckBluetoothOperationRequest(operationRequest))
  {
    SERIAL_PRINT("Received Undefined BlueTooth Command(Type, Speed):");
    SERIAL_PRINT(operationRequest->operationType);
    SERIAL_PRINT(",");
    SERIAL_PRINTLN(operationRequest->operationRequestData.Speed);
  }
  else if (iRRemoteReceiver->CheckIRRemoteOperationRequest(operationRequest))
  {
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
      motorMovement->moveBackward();
      break;
      case OperationType::RightTurn:
      motorMovement->moveBackward();
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
    default:
      SERIAL_PRINT("Received Undefined BlueTooth Command(Type, Speed):");
      SERIAL_PRINT(operationRequest->operationType);
      SERIAL_PRINT(",");
      SERIAL_PRINTLN(operationRequest->operationRequestData.Speed);
      break;
    }
  }
  delay(100);
}
