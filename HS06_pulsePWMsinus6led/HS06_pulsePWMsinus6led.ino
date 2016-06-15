#define LED1 11
#define LED2 10
#define LED3 9
#define LED4 6
#define LED5 5
#define LED6 3

#define DECAL PI*2/6

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
}

void loop() {
  for (float i=0; i<PI*2; i=i+PI*2/1000) {
    analogWrite(LED1,sin(i)*127.5+127.5);
    analogWrite(LED2,sin(i+DECAL)*127.5+127.5);
    analogWrite(LED3,sin(i+DECAL*2)*127.5+127.5);
    analogWrite(LED4,sin(i+DECAL*3)*127.5+127.5);
    analogWrite(LED5,sin(i+DECAL*4)*127.5+127.5);
    analogWrite(LED6,sin(i+DECAL*5)*127.5+127.5);
  }
}
