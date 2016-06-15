#define MALED  2
#define BOUTON 3

void interruption() {
  digitalWrite(MALED, !digitalRead(MALED));
}

void setup() {
  pinMode(MALED,OUTPUT);
  pinMode(BOUTON,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BOUTON), interruption,FALLING);
}

void loop() {
  delay(1000);
}



