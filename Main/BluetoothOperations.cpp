#include "BluetoothOperations.h"


BluetoothOperations::BluetoothOperations()
{
  LOG_BluetoothOperations("BluetoothOperations::BluetoothOperations()");
  //Serial1.begin(BLUETOOTH_PORT);
   m_SoftwareSerial = new SoftwareSerial(19, 18);
   m_Bluetooth = new SoftwareSerial(BLUETOOTH_RX, BLUETOOTH_TX);// RX, TX
}

void BluetoothOperations::setup()
{  
  LOG_BluetoothOperations("BluetoothOperations::setup()");  
  m_SoftwareSerial->begin(BLUETOOTH_PORT);
  //m_Bluetooth->begin(BLUETOOTH_PORT);
}

void BluetoothOperations::loop()
{
  LOG_BluetoothOperations_LOOP("BluetoothOperations::loop()");
  //Serial1.println("Testing...");
  //m_SoftwareSerial->println("Testing...");
  delay(500);
}

char BluetoothOperations::bluetoothRead(){
 /*if (Serial1.available() > 0)
  {
   return Serial1.read();
  }
   if (m_Bluetooth->available() > 0)
  {
    char command = m_Bluetooth->read();
    */
  return 0;
}
char BluetoothOperations::serialRead(){
 if (Serial.available() > 0)
  {
   return Serial.read();
  }
  return 0;
}

int BluetoothOperations::CheckBluetoothOperationRequest(OperationRequest* operationRequest, bool isBluetooth)
{
  LOG_BluetoothOperations("BluetoothOperations::CheckBluetoothOperationRequest()");

  operationRequest->operationType = OperationType::None;
  
  char command = 0;
  if(isBluetooth){
      command = bluetoothRead();
  } else {
      command = serialRead();
  }

  if (command > 0)
  {
    SERIAL_BLUETOOTH_PRINT("Received BlueTooth Command:"); SERIAL_BLUETOOTH_PRINTLN(command);
    switch (command)
    {
    case 'F':
      operationRequest->operationType = OperationType::MoveForward;
      break;
    case 'B':
      operationRequest->operationType = OperationType::MoveBackword;
      break;
    case 'L':
      operationRequest->operationType = OperationType::LeftTurn;
      break;
    case 'R':
      operationRequest->operationType = OperationType::RightTurn;
      break;

    case 'D':
      operationRequest->operationType = OperationType::StopMoveing;
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
      operationRequest->operationRequestData.Speed = command - '0';
      operationRequest->operationType = OperationType::Speed;
      break;
    case 'q':
      operationRequest->operationRequestData.Speed = 10;
      operationRequest->operationType = OperationType::Speed;
      break;
    case 'X':
      operationRequest->operationType = OperationType::CruseControlMode;
      break;
    case 'x':
      operationRequest->operationType = OperationType::LineFollowerMode;
      break;
    case 'W':
      operationRequest->operationType = OperationType::HendLightOn;
      break;
    case 'w':
      operationRequest->operationType = OperationType::HendLightOff;
      break;
    case 'U':
      operationRequest->operationType = OperationType::BackLightOn;
      break;
    case 'u':
      operationRequest->operationType = OperationType::BackLightOff;
      break;
    case 'V':
      operationRequest->operationType = OperationType::DeeperOn;
      break;
    case 'v':
      operationRequest->operationType = OperationType::DeeperOff;
      break;
    default:
      operationRequest->operationType = OperationType::Undefined;
      SERIAL_BLUETOOTH_PRINT("Unknown Command Received: "); SERIAL_BLUETOOTH_PRINTLN(command);
      break;
    }  
  }
  return operationRequest->operationType;
}
