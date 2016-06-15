int compteur = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print("Compteur : ");
  Serial.println(compteur);
  compteur++;
  delay(1000);
}
