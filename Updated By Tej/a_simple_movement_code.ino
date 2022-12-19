void readPing();

AF_DCMotor m1(DCMOTER_LEFT_FRONT, MOTOR12_64KHZ);
AF_DCMotor m2(DCMOTER_LEFT_BCAK, MOTOR12_64KHZ);
AF_DCMotor m3(DCMOTER_RIGHT_FRONT, MOTOR34_64KHZ);
AF_DCMotor m4(DCMOTER_RIGHT_BACK, MOTOR34_64KHZ);


void moveStop() {
  if (LOG) {
    Serial.write("moveStop\n");
  }
  m1.run(RELEASE);
  m2.run(RELEASE);
  m3.run(RELEASE);
  m4.run(RELEASE);
}

int Speed() {
  if (LOG) {
    Serial.write("Speed\n");
  }
  m1.setSpeed(speedSet);
  m2.setSpeed(speedSet);
  m3.setSpeed(speedSet);
  m4.setSpeed(speedSet);
  delay(5);
}
void moveForward() {
  if (LOG) {
    Serial.write("moveForward\n");
  }
  if (!goesForward) {
    if (LOG) {
      Serial.write("moveForward 1\n");
    }
    goesForward = true;
    m1.run(FORWARD);
    m2.run(FORWARD);
    m3.run(FORWARD);
    m4.run(FORWARD);
  }
}

void moveBackward() {
  if (LOG) {
    Serial.write("moveBackward\n");
  }
  goesForward = false;
  m1.run(BACKWARD);
  m2.run(BACKWARD);
  m3.run(BACKWARD);
  m4.run(BACKWARD);
}

void turnRight() {
  if (LOG) {
    Serial.write("turnRight\n");
  }
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(BACKWARD);
  m4.run(BACKWARD);
  delay(500);
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
}

void turnLeft() {
  if (LOG) {
    Serial.write("turnLeft\n");
  }
  m1.run(BACKWARD);
  m2.run(BACKWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
  delay(500);
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
}

int lookRight() {
  if (LOG) {
    Serial.write("lookRight\n");
  }
  myservo.write(50);
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(90);
  return distance;
}

int lookLeft() {
  if (LOG) {
    Serial.write("lookLeft\n");
  }
  myservo.write(130);
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(90);
  return distance;
  delay(100);
}
