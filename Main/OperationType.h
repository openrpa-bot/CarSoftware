#ifndef OperationType_h
#define OperationType_h

enum OperationType
{
  None,
  Undefined,

  MoveForward,
  MoveBackword,
  LeftTurn,
  RightTurn,
  StopMoveing,

  Speed,

  CruseControlMode,
  LineFollowerMode,

  HendLightOn,   
  HendLightOff,
  BackLightOn,
  BackLightOff,

  DeeperOn,
  DeeperOff
};

union OperationRequestData
{
  int Speed;
};

struct OperationRequest
{
  OperationType operationType;
  OperationRequestData operationRequestData;
};

#endif