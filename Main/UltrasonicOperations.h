#ifndef UltrasonicOperations_h
#define UltrasonicOperations_h
#include <Arduino.h> 
#include "CommonInclude.h"
#include <NewPing.h>

class UltrasonicOperations {
public:
   UltrasonicOperations();
   
   void setup();
   int lookRight();
   int lookLeft();
   int UltrasonicRead();
	
private:


NewPing *m_NewPing = NULL;
int m_Distance;
};
#endif