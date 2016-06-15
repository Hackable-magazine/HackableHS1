#define MALED 5

void setup() {
  pinMode(MALED, OUTPUT);
}

void loop() {
  for (float i=0; i<PI*2; i=i+PI*2/300) {
    analogWrite(MALED,sin(i)*127.5+127.5);
    delay(5);
  }
}
