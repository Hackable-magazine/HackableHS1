#define MALED 5

void setup() {
  pinMode(MALED, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  for (float i=0; i<PI*2; i=i+PI*2/300) {
    analogWrite(MALED,sin(i)*127.5+127.5);
    Serial.println(sin(i));
    delay(5);
  }
}
