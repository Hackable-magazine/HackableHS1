#define MALED 5

void setup() {
  pinMode(MALED, OUTPUT);
}

void loop() {
  for(int i=0; i<256; i++) {
    analogWrite(MALED,i);
    delay(5);
  }
  for(int i=255; i>=0; i--) {
    analogWrite(MALED,i);
    delay(5);
  }
}
