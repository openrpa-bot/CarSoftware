#include <Arduino.h> 

#include <IRremote.h>

#include "CommonInclude.h"
#include "MotorMovement.h"
#include "UltrasonicOperations.h"
#include "ServoOperations.h"
#include "BluetoothOperations.h"
#include "LedOperations.h"
#include "IRRemoteReceiver.h"
#include "LeftIRLineSensor.h"
#include "RightIRLineSensor.h"
#include "LineFollower.h"
#include "AutomaticObstacleSensorMove.h"


MotorMovement motorMovement = MotorMovement();
UltrasonicOperations ultrasonicOperations = UltrasonicOperations();
ServoOperations servoOperations = ServoOperations();
BluetoothOperations bluetoothOperations = BluetoothOperations();
LedOperations ledOperations = LedOperations();
IRRemoteReceiver iRRemoteReceiver = IRRemoteReceiver();
LeftIRLineSensor leftIRLineSensor= LeftIRLineSensor();
RightIRLineSensor rightIRLineSensor= RightIRLineSensor();
LineFollower lineFollower = LineFollower();
AutomaticObstacleSensorMove automaticObstacleSensorMove = AutomaticObstacleSensorMove();

OperationRequest *operationRequest = new OperationRequest();

int state = 0;
int flag = 0;

int rightIRSensorValue;
int leftIRSensorValue;
bool isAutomatic = false;

void setup() {
 Serial.begin(SERIAL_PORT);
 
 motorMovement.setup();
 ultrasonicOperations.setup();
 servoOperations.setup();
 bluetoothOperations.setup();
 ledOperations.setup();
 iRRemoteReceiver.setup();
 leftIRLineSensor.setup();
 leftIRLineSensor.setup();
 rightIRLineSensor.setup();
 automaticObstacleSensorMove.setup();
}

void loop() {
  
 motorMovement.loop();
 ultrasonicOperations.loop();
 servoOperations.loop();
 bluetoothOperations.loop();
 ledOperations.loop();
 iRRemoteReceiver.loop();
 leftIRLineSensor.loop();
 leftIRLineSensor.loop();
 rightIRLineSensor.loop();
 automaticObstacleSensorMove.loop();
 
}



