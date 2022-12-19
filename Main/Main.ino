#include <Arduino.h> 

#include <SoftwareSerial.h>
#include <IRremote.h>

#include <Servo.h>
#include <NewPing.h>

#include "CommonInclude.h"
#include "MotorMovement.h"



SoftwareSerial Bluetooth(BLUETOOTH_RX, BLUETOOTH_TX);  // RX, TX
NewPing sonar(ULTRASONIC_TRIG_PIN, ULTRASONIC_ECHO_PIN, MAX_DISTANCE);

MotorMovement motorMovement = MotorMovement();

Servo myservo;


int state = 0;
int flag = 0;

char command;
int rightIRSensorValue;
int leftIRSensorValue;

int distance = 100;

bool isAutomatic = false;


void setup() {
  Serial.begin(SERIAL_PORT);
  Bluetooth.begin(BLUETOOTH_PORT);
  myservo.attach(SERVO_PIN_IN_USE);
  myservo.write(90);
  //IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);

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
  distance = readPing();
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
    distanceR = lookRight();
    delay(200);
    distanceL = lookLeft();
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

int lookRight() {
  if (LOG) {
    Serial.write("lookRight\n");
  }
  myservo.write(50);
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(90);
  return distance;
}

int lookLeft() {
  if (LOG) {
    Serial.write("lookLeft\n");
  }
  myservo.write(130);
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(90);
  return distance;
  delay(100);
}

int readPing() {
  delay(100);
  int cm = sonar.ping_cm();
  if (LOG) {
    Serial.print("readPing Distance");
    Serial.print(cm);
    Serial.print("\n");
  }
  if (cm == 0) {
    cm = 250;
  }
  return cm;
}
