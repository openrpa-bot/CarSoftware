#include <SoftwareSerial.h>
#include <IRremote.h>
#include <AFMotor.h>
#include <Servo.h>
#include <NewPing.h>


#define ULTRASONIC_ECHO_PIN A0
#define ULTRASONIC_TRIG_PIN A1

#define IR_RECEIVE_PIN A2

#define LEFT_LINE_FOLLOW_IR A3
#define SOUND_PIN A4
#define RIGHT_LINE_FOLLOW_IR A5

#define BLUETOOTH_TX 0
#define BLUETOOTH_RX 1

#define SERVO_PIN_FREE 9
#define SERVO_PIN_IN_USE 10

#define DCMOTER_LEFT_FRONT 1
#define DCMOTER_LEFT_BCAK 2
#define DCMOTER_RIGHT_FRONT 3
#define DCMOTER_RIGHT_BACK 4

#define REVERCE_DISTANCE 30
#define MAX_DISTANCE 200
#define MAX_SPEED 150  // sets speed of DC  motors
#define MAX_SPEED_INCREMENT 20

#define SERIAL_PORT 9600
#define BLUETOOTH_PORT 9600

#define FORWARD_BT_CHAR 'F'
#define FORWARD_IR_REMOTE_CODE
#define FORWARD_CODE

#define LOG false

SoftwareSerial Bluetooth(BLUETOOTH_RX, BLUETOOTH_TX);  // RX, TX
NewPing sonar(ULTRASONIC_TRIG_PIN, ULTRASONIC_ECHO_PIN, MAX_DISTANCE);

/*AF_DCMotor m1(DCMOTER_LEFT_FRONT, MOTOR12_64KHZ);
AF_DCMotor m2(DCMOTER_LEFT_BCAK, MOTOR12_64KHZ);
AF_DCMotor m3(DCMOTER_RIGHT_FRONT, MOTOR34_64KHZ);
AF_DCMotor m4(DCMOTER_RIGHT_BACK, MOTOR34_64KHZ);
*/

Servo myservo;


int state = 0;
int flag = 0;

char command;
int rightIRSensorValue;
int leftIRSensorValue;
boolean goesForward = false;
extern int distance = 100;
int speedSet = 0;
bool isAutomatic = false;

#include "E:\TejArduino\CarSoftware\Main\a_simple_movement_code.ino"
#include "E:\TejArduino\CarSoftware\Main\b_automatic.ino"
#include "E:\TejArduino\CarSoftware\Main\c_Bluetooth.ino"


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
  return;
 
  } else if (rightIRSensorValue == LOW && leftIRSensorValue == LOW) {
    //if(LOG){ Serial.write("Skipped\n"); }
    automatic();
  } else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW) {
    turnRight();
  }

  else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH) {
    turnLeft();
  } else {
    moveForward();
  }

  rightIRSensorValue = digitalRead(RIGHT_LINE_FOLLOW_IR);
  leftIRSensorValue = digitalRead(LEFT_LINE_FOLLOW_IR);
}
