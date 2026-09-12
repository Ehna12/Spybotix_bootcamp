// ---------- MOTOR PINS ----------

int m11 = 2;
int m12 = 3;

int m21 = 4;
int m22 = 5;

// ---------- IR SENSOR PINS ----------

int irsensor1 = 6;   // Left IR sensor
int irsensor2 = 7;   // Right IR sensor


// ---------- MOTOR FUNCTIONS ----------

void forward() {
  digitalWrite(m11, LOW);
  digitalWrite(m12, HIGH);

  digitalWrite(m21, LOW);
  digitalWrite(m22, HIGH);
}

void reverse() {
  digitalWrite(m11, HIGH);
  digitalWrite(m12, LOW);

  digitalWrite(m21, HIGH);
  digitalWrite(m22, LOW);
}

void left() {
  // Left motor reverse
  digitalWrite(m11, HIGH);
  digitalWrite(m12, LOW);

  // Right motor forward
  digitalWrite(m21, LOW);
  digitalWrite(m22, HIGH);
}

void right() {
  // Left motor forward
  digitalWrite(m11, LOW);
  digitalWrite(m12, HIGH);

  // Right motor reverse
  digitalWrite(m21, HIGH);
  digitalWrite(m22, LOW);
}

void stopRobot() {
  digitalWrite(m11, LOW);
  digitalWrite(m12, LOW);

  digitalWrite(m21, LOW);
  digitalWrite(m22, LOW);
}


// ---------- SETUP ----------
// for green IR Sensor

void setup() {

  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);

  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);

  pinMode(irsensor1, INPUT);
  pinMode(irsensor2, INPUT);

  stopRobot();
}


// ---------- MAIN LOOP ----------

void loop() {

  int leftSensor = digitalRead(irsensor1);
  int rightSensor = digitalRead(irsensor2);


  // Both sensors see no obstacle
  if (leftSensor == HIGH && rightSensor == HIGH) {

    forward();
  }


  // Left sensor detects obstacle
  else if (leftSensor == LOW && rightSensor == HIGH) {

    stopRobot();
    delay(200);

    right();
    delay(500);

    stopRobot();
  }


  // Right sensor detects obstacle
  else if (leftSensor == HIGH && rightSensor == LOW) {

    stopRobot();
    delay(200);

    left();
    delay(500);

    stopRobot();
  }


  // Both sensors detect obstacle
  else if (leftSensor == LOW && rightSensor == LOW) {

    stopRobot();
    delay(200);

    reverse();
    delay(500);

    stopRobot();
  }
}