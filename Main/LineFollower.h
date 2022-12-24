#ifndef LineFollower_h
#define LineFollower_h
#include <Arduino.h>
#include "CommonInclude.h"
#include "LeftIRLineSensor.h"
#include "RightIRLineSensor.h"
#include "MotorMovement.h"

class LineFollower
{
public:
   LineFollower(LeftIRLineSensor *leftIRLineSensor, RightIRLineSensor * rightIRLineSensor, MotorMovement *motorMovement);
   void setup();
   void loop();
   void LineFollowerModeActivate();
   void LineFollowerModeRelease(){
      m_LineFollowerModeActiveState = false;
   };
private:
   void LineFollowedMove();
   LeftIRLineSensor *m_LeftIRLineSensor =NULL;
   RightIRLineSensor * m_RightIRLineSensor = NULL;
   MotorMovement *m_MotorMovement = NULL;
   bool m_LineFollowerModeActiveState = false;
};
#endif