#include "BluetoothOperations.h"
enum OperationType {
  None,
  Undefined,

  MoveForward,
  MoveBackword,
  LeftTurn,
  RightTurn,
  StopMoveing,

  Speed,
 
  CruseControl,
  LineFollower,

  HendLightOn,
  HendLightOff,
  BackLightOn,
  BackLightOff,
  DeeperOn,
  DeeperOff
};

BluetoothOperations::BluetoothOperations(){
    m_Bluetooth= new SoftwareSerial(BLUETOOTH_RX, BLUETOOTH_TX);  // RX, TX
};
void BluetoothOperations::setup(){
  m_Bluetooth->begin(BLUETOOTH_PORT);
}
int BluetoothOperations::BluetoothTrueRoFalse( ){
  OperationType operationType = OperationType::None;
  if (m_Bluetooth->available() > 0){
    int command = m_Bluetooth->read();

    //if (LOG) { Serial.write(command); }
     //moveStop();
    //      Serial.write(command);
    switch (command) {
      case 'F':
        operationType = OperationType::MoveForward;
        break;
      case 'B':
        operationType = OperationType::MoveBackword;
        break;
      case 'L':
       operationType = OperationType::LeftTurn;
        break;
      case 'R':
       operationType = OperationType::RightTurn;
        break;
      case 'X':
       operationType = OperationType::crusecontrol;
        break;
      case 'x':
       operationType = OperationType::LineFollower;
        break;
      case 'D':
         operationType = OperationType::StopMoveing;
        break;
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':      
      case 'q':       
        operationType = OperationType::Speed;
        break;
      case 'W':
         operationType = OperationType::HendLightOn;
        break;
      case 'w':
         operationType = OperationType::HendLightOff;
        break;
      case 'U':
         operationType = OperationType::BackLightOn;
        break;
      case 'u':
         operationType = OperationType::BackLightOff;
        break;
      default:
        operationType = OperationType::Undefined;
        break;
    }
}
}
void BluetoothOperations::loop() {
    #ifdef LOG_IRLineSensor
    Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__func__); Serial.write("\n");   
    #endif

}    