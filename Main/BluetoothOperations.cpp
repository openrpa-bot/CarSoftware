#include "BluetoothOperations.h"
enum OperationType {
  None,
  MoveForward,
  MoveBackword
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
        break;
      case 'R':
        break;
      case 'X':
        break;
      case 'x':
        break;
      case '0':
        break;
      case '1':
        break;
      case '2':
        break;
      case '3':
        break;
      case '4':
        
        break;
      case '5':
        
        break;
      case '6':
        
        break;
      case '7':
        
        
        break;
      case '8':
        
        
        break;
      case '9':
        
        
        break;
      case 'q':
        
        
        break;
      case 'D':
        
        break;
    }
}
}
void BluetoothOperations::loop() {
    #ifdef LOG_IRLineSensor
    Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__func__); Serial.write("\n");   
    #endif

}    