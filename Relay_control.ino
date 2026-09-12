int relayPin = 13;

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);

  Serial.begin(9600);
  Serial.println("Enter A = ON, S = OFF");
}

void loop() {
  if (Serial.available()) {
    char input = Serial.read();

    if (input == 'A') {
      digitalWrite(relayPin, HIGH);
      Serial.println("Relay ON");
    }

    if (input == 'S') {
      digitalWrite(relayPin, LOW);
      Serial.println("Relay OFF");
    }
  }
}