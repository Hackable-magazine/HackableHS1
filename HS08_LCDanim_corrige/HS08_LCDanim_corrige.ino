#include <LiquidCrystal.h>

#define LCD_RS  7
#define LCD_E   8
#define LCD_D4  9
#define LCD_D5  10
#define LCD_D6  11
#define LCD_D7  12

LiquidCrystal lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

int pos=0;
void spin() {
  switch(pos) {
    case 0: lcd.print("/");
            pos++;
            break;
    case 1: lcd.print("-");
            pos++;
            break;
    case 2: lcd.print('\00');
            //lcd.write(byte(0));
            pos++;
            break;
    case 3: lcd.print("|");
            pos=0;
            break;
  }
}

byte symbole[8] = {
  B00000,
  B10000,
  B01000,
  B00100,
  B00010,
  B00001,
  B00000
};

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, symbole);
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
  delay(100);
}
