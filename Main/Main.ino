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


AutomaticObstacleSensorMove automaticObstacleSensorMove = AutomaticObstacleSensorMove();
BluetoothOperations bluetoothOperations = BluetoothOperations();
IRRemoteReceiver iRRemoteReceiver = IRRemoteReceiver();
LedOperations ledOperations = LedOperations();
LeftIRLineSensor leftIRLineSensor = LeftIRLineSensor();
LineFollower lineFollower = LineFollower();
MotorMovement motorMovement = MotorMovement();
RightIRLineSensor rightIRLineSensor = RightIRLineSensor();
ServoOperations servoOperations = ServoOperations();
UltrasonicOperations ultrasonicOperations = UltrasonicOperations();

OperationRequest *operationRequest = new OperationRequest();

void setup()
{

  Serial.begin(SERIAL_PORT);

  LOG_Main("BEGIN");

  automaticObstacleSensorMove.setup();
  bluetoothOperations.setup();
  iRRemoteReceiver.setup();
  ledOperations.setup();
  leftIRLineSensor.setup();
  lineFollower.setup();
  motorMovement.setup();
  rightIRLineSensor.setup();
  servoOperations.setup();
  ultrasonicOperations.setup();
  
  LOG_Main("END");
}

void loop()
{
  LOG_Main_LOOP("Loop Begin");

  automaticObstacleSensorMove.loop();
  bluetoothOperations.loop();
  iRRemoteReceiver.loop();
  ledOperations.loop();
  leftIRLineSensor.loop();
  lineFollower.loop();
  motorMovement.loop();
  rightIRLineSensor.loop();
  servoOperations.loop();
  ultrasonicOperations.loop();

  LOG_Main_LOOP("Loop End");
}
