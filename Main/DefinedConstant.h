#ifndef DefinedConstant_h
#define DefinedConstant_h

#define REVERCE_DISTANCE 30
#define MAX_DISTANCE 200
#define MAX_SPEED 150  // sets speed of DC  motors
#define MAX_SPEED_INCREMENT 20
#define INITIAL_SPEED 20

#define SERIAL_PORT 9600
#define BLUETOOTH_PORT 9600

#define FORWARD_BT_CHAR 'F'
#define FORWARD_IR_REMOTE_CODE
#define FORWARD_CODE

#define LOG true




#define LOG_MotorMovementEnable


#ifdef LOG_MotorMovementEnable
#define LOG_MotorMovement(message) Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__FUNCTION__); Serial.write(":");  Serial.write(message); Serial.write("\n");
#else
#define LOG_MotorMovement(message)
#endif

#endif