#define MALED    5
#define POTARD  A0

void setup() {
  pinMode(MALED,OUTPUT);
}

void loop() {
  int val=analogRead(POTARD);
  val=map(val, 0, 1023, 0, 255);
  analogWrite(MALED, val);
}

