void setup() {
  for(int i=5; i<=12; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(115200);
}

void loop() {
  while (Serial.available() > 0) {
    int nombre = Serial.read();
    Serial.print("recu : ");
    Serial.println(nombre);
    if(nombre-48 >= 1 && nombre-48 <=8) {
      digitalWrite(nombre-48+4, !digitalRead(nombre-48+4));
      Serial.println("ok");
    } else if(nombre-48==0) {
      for(int i=5; i<=12; i++) {
        digitalWrite(i, LOW);
      }
      Serial.println("reset");
    } else {
      Serial.println("PAS OK!");
    }
  }
}
