int distance = 100;

void BT(){ 
  if (Bluetooth.available() > 0) {
    command = Bluetooth.read();

    if (LOG) { Serial.write(command); }
    moveStop();
    Serial.write(command);
    switch (command) {
      case 'F':
        isAutomatic = false;
        moveForward();
        break;
      case 'B':
        isAutomatic = false;
        moveBackward();
        break;
      case 'L':
        isAutomatic = false;
        turnLeft();
        break;
      case 'R':
        isAutomatic = false;
        turnRight();
        break;
      case 'X':
        isAutomatic = true;
        break;
      case 'x':
        isAutomatic = false;
        break;
      case '0':
        speedSet = 0;
        break;
      case '1':
        speedSet = 20;
        Speed();
        break;
      case '2':
        speedSet = 40;
        Speed();
        break;
      case '3':
        speedSet = 60;
        Speed();
        break;
      case '4':
        speedSet = 80;
        Speed();
        break;
      case '5':
        speedSet = 100;
        Speed();
        break;
      case '6':
        speedSet = 120;
        Speed();
        break;
      case '7':
        speedSet = 140;
        Speed();
        break;
      case '8':
        speedSet = 160;
        Speed();
        break;
      case '9':
        speedSet = 180;
        Speed();
        break;
      case 'q':
        speedSet = 200;
        Speed();
        break;
      case 'D':
        moveStop();
        break;
    }

  }
}
