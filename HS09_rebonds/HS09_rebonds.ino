#define MALED  2
#define BOUTON 3

void setup() {
  pinMode(MALED,OUTPUT);
  pinMode(BOUTON,INPUT_PULLUP);
}

void loop() {
  if(!digitalRead(BOUTON)) {
    digitalWrite(MALED, !digitalRead(MALED));
  }
}

