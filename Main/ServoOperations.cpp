#include <Arduino.h> 
#include "ServoOperations.h"

ServoOperations::ServoOperations(){
    m_MyServo = new Servo();
}

void ServoOperations::setup(){
  m_MyServo->attach(SERVO_PIN_IN_USE);
  m_MyServo->write(90);
}

void ServoOperations::rotate(int angle) {

  if (LOG) {
    //Serial.write("lookRight\n");
  }
  m_MyServo->write(angle);
}

