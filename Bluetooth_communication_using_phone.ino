#include <SoftwareSerial.h>
SoftwareSerial bt(10, 9); //Rx, Tx
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
  Serial.begin(9600);
  bt.begin(9600);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);

  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);

  pinMode(irsensor1, INPUT);
  pinMode(irsensor2, INPUT);

  stopRobot();
}

void loop()
{
  if (bt.available()){
    char ch = bt.read(); //data coming from bluetooth is being read and getting saved into bt
    if (ch=='F'){
      forward();
      Serial.println("FWD");
    }
    if (ch== 'B'){
      reverse();
      Serial.println("REV");
    }
    if (ch== 'R'){
      right();
      Serial.println("RIGHT");
  }
  }
}