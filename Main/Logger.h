#ifndef Logger_h
#define Logger_h

//#define LOG_LOOP
/*
#define LOG_Enable 
#define LOG_Main_Enable 
#define LOG_AutomaticObstacleSensorMove_Enable
#define LOG_BluetoothOperations_Enable
#define LOG_IRRemoteReceiver_Enable
#define LOG_LedOperations_Enable
#define LOG_LeftIRLineSensor_Enable
#define LOG_LineFollower_Enable
#define LOG_MotorMovement_Enable
#define LOG_RightIRLineSensor_Enable
#define LOG_ServoOperations_Enable
#define LOG_UltrasonicOperations_Enable
*/

#define LOG_Format(message) Serial.write(__FILE__); Serial.write(":"); Serial.print(__LINE__); Serial.write(":"); Serial.write(__FUNCTION__); Serial.write(":");  Serial.write(message); Serial.write("\n");

#ifdef LOG_LOOP
    #define LOG_Format_LOOP(message) Serial.write(__FILE__); Serial.write(":"); Serial.print(__LINE__); Serial.write(":"); Serial.write(__FUNCTION__); Serial.write(":");  Serial.write(message); Serial.write("\n");
#else
    #define LOG_Format_LOOP(message)
#endif

#ifdef LOG_Enable
    #define LOG(message) LOG_Format(message)
#else
    #define LOG(message)
#endif

#ifdef LOG_Main_Enable
    #define LOG_Main(message) LOG_Format(message)
    #define LOG_Main_LOOP(message) LOG_Format_LOOP(message)
#else
    #define LOG_Main(message)
    #define LOG_Main_LOOP(message)
#endif

#ifdef LOG_AutomaticObstacleSensorMove_Enable
    #define LOG_AutomaticObstacleSensorMove(message) LOG_Format(message)
    #define LOG_AutomaticObstacleSensorMove_LOOP(message) LOG_Format_LOOP(message)
#else
    #define LOG_AutomaticObstacleSensorMove(message)
    #define LOG_AutomaticObstacleSensorMove_LOOP(message)
#endif

#ifdef LOG_BluetoothOperations_Enable
    #define LOG_BluetoothOperations(message) LOG_Format(message)
    #define LOG_BluetoothOperations_LOOP(message) LOG_Format_LOOP(message)
#else
    #define LOG_BluetoothOperations(message)
    #define LOG_BluetoothOperations_LOOP(message)
#endif

#ifdef LOG_IRRemoteReceiver_Enable
    #define LOG_IRRemoteReceiver(message) LOG_Format(message)
    #define LOG_IRRemoteReceiver_LOOP(message) LOG_Format_LOOP(message)
#else
    #define LOG_IRRemoteReceiver(message)
    #define LOG_IRRemoteReceiver_LOOP(message)
#endif

#ifdef LOG_LedOperations_Enable
    #define LOG_LedOperations(message) LOG_Format(message)
    #define LOG_LedOperations_LOOP(message) LOG_Format_LOOP(message)
#else
    #define LOG_LedOperations(message)
    #define LOG_LedOperations_LOOP(message)
#endif

#ifdef LOG_LeftIRLineSensor_Enable
    #define LOG_LeftIRLineSensor(message) LOG_Format(message)
    #define LOG_LeftIRLineSensor_LOOP(message) LOG_Format_LOOP(message)
#else
    #define LOG_LeftIRLineSensor(message)
    #define LOG_LeftIRLineSensor_LOOP(message)
#endif

#ifdef LOG_LineFollower_Enable
    #define LOG_LineFollower(message) LOG_Format(message)
    #define LOG_LineFollower_LOOP(message) LOG_Format_LOOP(message)
#else
    #define LOG_LineFollower(message)
    #define LOG_LineFollower_LOOP(message)
#endif

#ifdef LOG_MotorMovement_Enable
    #define LOG_MotorMovement(message) LOG_Format(message)
    #define LOG_MotorMovement_LOOP(message) LOG_Format_LOOP(message)
#else
    #define LOG_MotorMovement(message)
    #define LOG_MotorMovement_LOOP(message)
#endif

#ifdef LOG_RightIRLineSensor_Enable
    #define LOG_RightIRLineSensor(message) LOG_Format(message)
    #define LOG_RightIRLineSensor_LOOP(message) LOG_Format_LOOP(message)
#else
    #define LOG_RightIRLineSensor(message)
    #define LOG_RightIRLineSensor_LOOP(message)
#endif

#ifdef LOG_ServoOperations_Enable
    #define LOG_ServoOperations(message) LOG_Format(message)
    #define LOG_ServoOperations_LOOP(message) LOG_Format_LOOP(message)
#else
    #define LOG_ServoOperations(message)
    #define LOG_ServoOperations_LOOP(message)
#endif

#ifdef LOG_UltrasonicOperations_Enable
    #define LOG_UltrasonicOperations(message) LOG_Format(message)
    #define LOG_UltrasonicOperations_LOOP(message) LOG_Format_LOOP(message)
#else
    #define LOG_UltrasonicOperations(message)
    #define LOG_UltrasonicOperations_LOOP(message)
#endif

#endif