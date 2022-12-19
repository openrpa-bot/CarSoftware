extern int distance;
int lookRight();
int readPing();

void automatic() {
  if (!isAutomatic) return;
  distance = readPing();
  if (LOG) {
    Serial.print("automatic distance\n");
  }
  int distanceR = 0;
  int distanceL = 0;
  delay(1000);

  if (distance <= REVERCE_DISTANCE) {
    moveStop();
    delay(100);
    moveBackward();
    delay(200);
    moveStop();
    delay(200);
    distanceR = lookRight();
    delay(200);
    distanceL = lookLeft();
    delay(200);

    if (distanceR >= distanceL) {
      turnRight();
      moveStop();
    } else {
      turnLeft();
      moveStop();
    }
  } else {
    moveForward();
  }
}

int readPing() {
  delay(100);
  int cm = sonar.ping_cm();
  if (LOG) {
    Serial.print("readPing Distance");
    Serial.print(cm);
    Serial.print("\n");
  }
  if (cm == 0) {
    cm = 250;
  }
  return cm;
}
