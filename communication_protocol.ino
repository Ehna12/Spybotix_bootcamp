int ir= 6;
void setup(){
  Serial.begin(9600);
  pinMode(ir, INPUT);
}
void loop(){
  Serial.println(digitalRead(ir));
}