unsigned long previousMillis[8]= {0};

const int interval[8] = {
  1000, 250, 130, 50,
  320, 750, 70, 500
};

void setup() {
  for(int i=5; i<=12; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  unsigned long currentMillis = millis();
  for(int i=5; i<=12; i++) {
    if (currentMillis - previousMillis[i-5] >= interval[i-5]) {
      digitalWrite(i, !digitalRead(i));
      previousMillis[i-5] = currentMillis;
    }
  }
}
