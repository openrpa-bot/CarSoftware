#include <SoftwareSerial.h>
#include <AFMotor.h>
#include <Servo.h>   
#include <NewPing.h>

#define TRIG_PIN A1
#define ECHO_PIN A0
#define MAX_DISTANCE 200 
#define MAX_SPEED 201 // sets speed of DC  motors
#define MAX_SPEED_OFFSET 20
#define SERIAL_PORT 9600
#define LOG true
#define SERVO_PIN 10

int state = 0;
int flag = 0;
char command; 

SoftwareSerial Bluetooth(1, 0); // RX, TX

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 

AF_DCMotor m1(1, MOTOR12_64KHZ); 
AF_DCMotor m2(2, MOTOR12_64KHZ);
AF_DCMotor m3(3, MOTOR34_64KHZ);
AF_DCMotor m4(4, MOTOR34_64KHZ);
Servo myservo;   

boolean goesForward=false;
int distance = 100;
int speedSet = 0;
bool isAutomatic = false;


void setup() {
 //Serial.begin(SERIAL_PORT);
  Bluetooth.begin(SERIAL_PORT);
  
  myservo.attach(SERVO_PIN);  
  myservo.write(90); 
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop() {
  //if(Serial.available() > 0){
  //command = Serial.read(); 
  
  if(Bluetooth.available() > 0){
  command = Bluetooth.read(); 
  
  if(LOG){ Serial.write(command);}
  //moveStop();
   Serial.write(command);
    switch(command){
    case 'F': 
      isAutomatic = false;
      moveForward();
      break;
    case 'B': 
     isAutomatic = false;
     moveBackward();
     break;
    case 'L': 
      isAutomatic = false;
      turnLeft();
      break;
    case 'R':
      isAutomatic = false;
      turnRight();
      break;
   case 'D':
      isAutomatic = true;
      break;
   case '0':
      speedSet = 0;
      break;
   case '1':
      speedSet = 20;
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
    }
 } else{
  //if(LOG){ Serial.write("Skipped\n"); }
  }
  automatic();
}
void automatic() {  
  if(!isAutomatic) return;
  distance = readPing();
  if(LOG){ Serial.print("automatic distance\n"); }
  int distanceR = 0;
  int distanceL = 0;
  delay(1000);
 
  if(distance<=25)
  {
   moveStop();
   delay(100);
   moveBackward();
   delay(200);
   moveStop();
   delay(200);
   distanceR = lookRight();
   delay(200);
   distanceL = lookLeft();
   delay(200);

   if(distanceR>=distanceL)
   {
    turnRight();
     moveStop();
   } 
  
   else
  
   {
     turnLeft();
     moveStop();
   }
  }
 
  else
  {
   moveForward();
  }
 }

int lookRight()
{
   if(LOG){ Serial.write("lookRight\n"); }
    myservo.write(50); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(90); 
    return distance;
}

int lookLeft()
{
    if(LOG){ Serial.write("lookLeft\n"); }
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
  if(LOG){ Serial.print("readPing Distance"); Serial.print(cm); Serial.print("\n"); }
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}

void moveStop() {
  if(LOG){ Serial.write("moveStop\n"); }
  m1.run(RELEASE); 
  m2.run(RELEASE);
  m3.run(RELEASE);
  m4.run(RELEASE);
  } 

  int Speed(){
    if(LOG){ Serial.write("Speed\n"); }
    m1.setSpeed(speedSet);
    m2.setSpeed(speedSet);
    m3.setSpeed(speedSet);
    m4.setSpeed(speedSet);
    delay(5);
  }
void moveForward() {
if(LOG){ Serial.write("moveForward\n"); }
 if(!goesForward)
  {
    if(LOG){ Serial.write("moveForward 1\n"); }
    goesForward=true;
    m1.run(FORWARD);      
    m2.run(FORWARD);
    m3.run(FORWARD); 
    m4.run(FORWARD);     

  }
}

void moveBackward() {
   if(LOG){ Serial.write("moveBackward\n"); }
    goesForward=false;
    m1.run(BACKWARD);      
    m2.run(BACKWARD);
    m3.run(BACKWARD);
    m4.run(BACKWARD);  
}  

void turnRight() {
  if(LOG){ Serial.write("turnRight\n"); }
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(BACKWARD);
  m4.run(BACKWARD);     
  delay(500);
  m1.run(FORWARD);      
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);      
  
} 
 
void turnLeft() {
  if(LOG){ Serial.write("turnLeft\n");}
  m1.run(BACKWARD);     
  m2.run(BACKWARD);  
  m3.run(FORWARD);
  m4.run(FORWARD);   
  delay(500);
  m1.run(FORWARD);     
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
 
}
