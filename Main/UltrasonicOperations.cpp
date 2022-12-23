#include <Arduino.h> 
#include "UltrasonicOperations.h"

UltrasonicOperations::UltrasonicOperations()
{
  m_Distance = 100;
  m_NewPing = new NewPing(ULTRASONIC_TRIG_PIN, ULTRASONIC_ECHO_PIN, MAX_DISTANCE);
}

void UltrasonicOperations::setup(){
   delay(2000);
  m_Distance = UltrasonicRead();
  delay(100);
  m_Distance = UltrasonicRead();
  delay(100);
  m_Distance = UltrasonicRead();
  delay(100);
  m_Distance = UltrasonicRead();
  delay(100);
}
int UltrasonicOperations::UltrasonicRead()
{
    delay(100);
    int cm = m_NewPing->ping_cm();
   // if (LOG)
    {
        Serial.print("readPing Distance cm");
        Serial.print("\n");
    }
    if (cm == 0)
    {
        cm = 250;
    }
    return cm;
}
int UltrasonicOperations::lookRight() {
  //if (LOG) {
    Serial.write("lookRight\n");
 // }
  //myservo.write(50);
  delay(500);
  int m_Distance = UltrasonicRead();
  delay(100);
  //myservo.write(90);
  return m_Distance;
}

int UltrasonicOperations::lookLeft() {
  //if (LOG) {
    Serial.write("lookLeft\n");
  //}
  //myservo.write(130);
  delay(500);
  int m_Distance = UltrasonicRead();
  delay(100);
  //myservo.write(90);
  return m_Distance;
  delay(100);
}
void UltrasonicOperations::loop() {
    #ifdef LOG_IRLineSensor
    Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__func__); Serial.write("\n");   
    #endif

}    
