#ifndef ServoOperations_h
#define ServoOperations_h
#include <Arduino.h> 
#include "CommonInclude.h"
#include <Servo.h>

class ServoOperations {
public:
   ServoOperations();
   void setup();
   void loop();
void rotate(int angle);

private:
Servo *m_MyServo = NULL;

};
#endif