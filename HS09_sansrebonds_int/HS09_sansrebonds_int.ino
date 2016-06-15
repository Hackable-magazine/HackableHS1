#define MALED  2
#define BOUTON 3

volatile boolean clic = false;

void interruption() {
  clic = true;
}

void setup() {
  pinMode(MALED,OUTPUT);
  pinMode(BOUTON,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BOUTON), interruption,FALLING);
}

unsigned long previousMillis = 0;

void loop() {
  unsigned long currentMillis = millis();
  if(clic) {
    if(currentMillis-previousMillis > 50) {
      digitalWrite(MALED, !digitalRead(MALED));
      previousMillis = currentMillis;
    }
    clic = false;
  }
}



