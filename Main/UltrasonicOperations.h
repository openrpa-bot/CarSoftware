#ifndef UltrasonicOperations_h
#define UltrasonicOperations_h
#include <Arduino.h>
#include "CommonInclude.h"
#include "ServoOperations.h"
#include <NewPing.h>

class UltrasonicOperations
{
public:
   UltrasonicOperations(ServoOperations *servoOperations);

   void setup();
   int lookRight();
   int lookLeft();
   int UltrasonicRead();
   void loop();

private:
   NewPing *m_NewPing = NULL;
   ServoOperations *m_ServoOperations = NULL;
   int m_Distance;
};
#endif