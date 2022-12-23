#include "BluetoothOperations.h"

BluetoothOperations::BluetoothOperations()
{
  LOG_BluetoothOperations("BluetoothOperations::BluetoothOperations()");
  m_Bluetooth = new SoftwareSerial(BLUETOOTH_RX, BLUETOOTH_TX);// RX, TX
}

void BluetoothOperations::setup()
{  
  LOG_BluetoothOperations("BluetoothOperations::setup()");  
  m_Bluetooth->begin(BLUETOOTH_PORT);
}

void BluetoothOperations::loop()
{
  LOG_BluetoothOperations_LOOP("BluetoothOperations::loop()");
}

int BluetoothOperations::CheckBluetoothOperationRequest(OperationRequest* operationRequest)
{
  LOG_BluetoothOperations("BluetoothOperations::CheckBluetoothOperationRequest()");

  operationRequest->operationType = OperationType::None;

  if (m_Bluetooth->available() > 0)
  {
    int command = m_Bluetooth->read();
    
    Serial.print(command); Serial.print(": Received the BlueTooth Command\n");

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
      break;
    }  
  }
  return operationRequest->operationType;
}
