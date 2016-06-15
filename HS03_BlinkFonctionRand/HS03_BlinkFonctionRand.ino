void clignote(int nombre) {
  while(nombre>0) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    nombre=nombre-1;
  }
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  randomSeed(analogRead(0));
}

void loop() {
  int cligne = random(10);
  clignote(cligne);
  delay(1000);
}
