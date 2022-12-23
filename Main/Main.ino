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

void setup() {
 
 Serial.begin(SERIAL_PORT);
 
 LOG_Main("Begin");

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

 LOG_Main("Begin");
}

void loop() {  
 LOG_Main("Loop Begin");
 
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

 LOG_Main("Loop End"); 
}



