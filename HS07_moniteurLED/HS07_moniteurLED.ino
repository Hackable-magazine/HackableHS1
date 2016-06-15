void setup() {
  for(int i=5; i<=12; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(115200);
}

void loop() {
  while (Serial.available() > 0) {
    int nombre = Serial.parseInt();
    Serial.print("recu : ");
    Serial.println(nombre);
    if(nombre >= 5 && nombre <=12) {
      digitalWrite(nombre, !digitalRead(nombre));
      Serial.println("ok");
    } else if(nombre==-1) {
      for(int i=5; i<=12; i++) {
        digitalWrite(i, LOW);
      }
      Serial.println("reset");
    } else {
      Serial.println("PAS OK!");
    }
  }
}
