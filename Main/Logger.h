#ifndef Logger_h
#define Logger_h

#define LOG_Format(message) Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__FUNCTION__); Serial.write(":");  Serial.write(message); Serial.write("\n");

#define LOG_Enable 
#define LOG_Main_Enable 
#define LOG_MotorMovement_Enable


#ifdef LOG_Enable
    #define LOG(message) LOG_Format(message)
#else
    #define LOG(message)
#endif

#ifdef LOG_Main_Enable
    #define LOG_Main(message) LOG_Format(message)
#else
    #define LOG_Main(message)
#endif

#ifdef LOG_MotorMovement_Enable
    #define LOG_MotorMovement(message) LOG_Format(message)
#else
    #define LOG_MotorMovement(message)
#endif

#endif