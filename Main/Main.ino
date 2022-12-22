#include <Arduino.h> 


#include <IRremote.h>

#include "CommonInclude.h"
#include "MotorMovement.h"
#include "UltrasonicOperations.h"
#include "ServoOperations.h"
#include "BluetoothOperation.h"


MotorMovement motorMovement = MotorMovement();
UltrasonicOperations ultrasonicOperations = UltrasonicOperations();
ServoOperations servoOperations = ServoOperations();
BluetoothOperation bluetoothOperation = BluetoothOperation();

int state = 0;
int flag = 0;


int rightIRSensorValue;
int leftIRSensorValue;



bool isAutomatic = false;


void setup() {
 Serial.begin(SERIAL_PORT);
 
 servoOperations.setup();
 bluetoothOperation.setup();

  //IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

 ultrasonicOperations.setup();

  pinMode(RIGHT_LINE_FOLLOW_IR, INPUT);
  pinMode(LEFT_LINE_FOLLOW_IR, INPUT);
}

void loop() {
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
  
  if (rightIRSensorValue == LOW && leftIRSensorValue == LOW) {
    //if(LOG){ Serial.write("Skipped\n"); }
    automatic();
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
}
void automatic() {
  if (!isAutomatic) return;
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
  }
}


