#include <Arduino.h> 

#include <SoftwareSerial.h>
#include <IRremote.h>

#include <Servo.h>

#include "CommonInclude.h"
#include "MotorMovement.h"
#include "UltrasonicOperations.h"


SoftwareSerial Bluetooth(BLUETOOTH_RX, BLUETOOTH_TX);  // RX, TX

MotorMovement motorMovement = MotorMovement();
UltrasonicOperations ultrasonicOperations = UltrasonicOperations();

Servo myservo;


int state = 0;
int flag = 0;

char command;
int rightIRSensorValue;
int leftIRSensorValue;



bool isAutomatic = false;


void setup() {
  Serial.begin(SERIAL_PORT);
  Bluetooth.begin(BLUETOOTH_PORT);
  myservo.attach(SERVO_PIN_IN_USE);
  myservo.write(90);
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
  if (Bluetooth.available() > 0) {
    command = Bluetooth.read();

    if (LOG) { Serial.write(command); }
    //moveStop();
    Serial.write(command);
    switch (command) {
      case 'F':
        isAutomatic = false;
        motorMovement.moveForward();
        break;
      case 'B':
        isAutomatic = false;
        motorMovement.moveBackward();
        break;
      case 'L':
        isAutomatic = false;
        motorMovement.turnLeft();
        break;
      case 'R':
        isAutomatic = false;
        motorMovement.turnRight();
        break;
      case 'X':
        isAutomatic = true;
        break;
      case 'x':
        isAutomatic = false;
        break;
      case '0':
        motorMovement.setSpeed(0);
        break;
     /* case '1':
        //speedSet = 20;
        Speed();
        break;
      case '2':
        speedSet = 40;
        Speed();
        break;
      case '3':
        speedSet = 60;
        Speed();
        break;
      case '4':
        speedSet = 80;
        Speed();
        break;
      case '5':
        speedSet = 100;
        Speed();
        break;
      case '6':
        speedSet = 120;
        Speed();
        break;
      case '7':
        speedSet = 140;
        Speed();
        break;
      case '8':
        speedSet = 160;
        Speed();
        break;
      case '9':
        speedSet = 180;
        Speed();
        break;
      case 'q':
        speedSet = 200;
        Speed();
        break;
      case 'D':
        moveStop();
        break;*/
    }
  } else if (rightIRSensorValue == LOW && leftIRSensorValue == LOW) {
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


