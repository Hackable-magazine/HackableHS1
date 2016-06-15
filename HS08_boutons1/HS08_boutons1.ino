#include <LiquidCrystal.h>

// désignation des broches utilisées
#define LCD_RS  7
#define LCD_E   8
#define LCD_D4  9
#define LCD_D5  10
#define LCD_D6  11
#define LCD_D7  12

#define MALED    5
#define MALED2   6
#define POTARD  A0

#define BOUTON1 2
#define BOUTON2 3

// instanciation lcd
LiquidCrystal lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

int oldval = -1;
int mabarre;
int old_mabarre;

// variables d'anti-rebond
unsigned long previousMillisB1 = 0;
unsigned long previousMillisB2 = 0;
volatile boolean clicB1 = false;
volatile boolean clicB2 = false;

// routines d'interruption
void intB1() {
  clicB1 = true;
}
void intB2() {
  clicB2 = true;
}

// configuration
void setup() {
  // port série/moniteur
  Serial.begin(115200);
  // LCD
  lcd.begin(16, 2);
  // sorties/LEds
  pinMode(MALED,OUTPUT);
  pinMode(MALED2,OUTPUT);
  // entrées
  pinMode(BOUTON1,INPUT_PULLUP);
  pinMode(BOUTON2,INPUT_PULLUP);
  // interruptions
  attachInterrupt(digitalPinToInterrupt(BOUTON1), intB1, FALLING);
  attachInterrupt(digitalPinToInterrupt(BOUTON2), intB2, FALLING);
}

// bocule principale
void loop() {
  unsigned long currentMillis = millis();
  int val;

  // lecture potentiomètre
  val=analogRead(POTARD);
  // adaptation de valeur
  val=map(val, 0, 1023, 0, 16);
  // la valeur à changée ?
  if(val!=oldval) {
    // moniteur
    Serial.print("potentiometre: ");
    Serial.println(val);
    // LCD
    lcd.setCursor(0, 1);
    for(int i=0; i<val; i++) {
      lcd.print("*");
    }
    lcd.print("                ");
    // PWM / LED
    analogWrite(MALED, val*8);
    // mise à jour
    oldval=val;
  }

  // une pression sur le bouton 1 ?
  if(clicB1) {
    // 200ms se sont écoulées depuis la dernière fois ?
    if(currentMillis-previousMillisB1 > 200) {
      // oui, on réduit la barre
      previousMillisB1 = currentMillis;
      mabarre--;
      if(mabarre<0) mabarre = 0;
    }
    clicB1 = false;
  }

  // une pression sur le bouton 2 ?
  if(clicB2) {
    // 200ms se sont écoulées depuis la dernière fois ?
    if(currentMillis-previousMillisB2 > 200) {
      // oui, on augmente la barre
      mabarre++;
      if(mabarre>16) mabarre = 16;
      previousMillisB2 = currentMillis;
    }
    clicB2 = false;
  }

  // affichage de la barre gérée par les boutons
  if(mabarre!=old_mabarre) {
    // moniteur
    Serial.print("position boutons: ");
    Serial.println(mabarre);
    // LCD
    lcd.setCursor(0, 0);
    for(int i=0; i<mabarre; i++) {
      lcd.print("=");
    }
    lcd.print("                ");
    // PWM
    analogWrite(MALED2, mabarre*8);
    // mise à jour
    old_mabarre=mabarre;
  }
}

