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
  m_MyServo->write(angle);
}

void ServoOperations::loop() {
    #ifdef LOG_IRLineSensor
    Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__func__); Serial.write("\n");   
    #endif

}    
