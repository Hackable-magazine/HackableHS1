#include <LiquidCrystal.h>

//                RS RW   E  D4  D5  D6  D7 
LiquidCrystal lcd( 4, 3, A0, A1, A2, A3, A4);

int pos=0;
void spin() {
  lcd.write(byte(pos));
  pos++;
  if(pos==7)
    pos=0;
}

byte symbole[8][8] = {{
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
},{
  B00000,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
},{
  B00000,
  B00000,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000
},{
  B00000,
  B00000,
  B00000,
  B11111,
  B00000,
  B00000,
  B00000
},{
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B00000,
  B00000
},{
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B00000
},{
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111
},{
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
}};


void setup() {
  lcd.begin(16, 2);
  for(int i=0; i<8; i++) {
    lcd.createChar(i, symbole[i]);
  }
  lcd.setCursor(0, 0);
  lcd.print("Hackable Mag HS");
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print("compteur:");
  lcd.setCursor(9, 1);
  lcd.print(millis()/500);
  lcd.setCursor(15, 1);
  spin();
  delay(150);
}
