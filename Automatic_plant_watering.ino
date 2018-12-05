#include <LiquidCrystal.h>

// Kosteusanturien (analogi)pinnien määrittäminen
int moisture1 = A0;
int moisture2 = A1;
int moisture3 = A2;
int moisture4 = A3;

// Kosteusanturin arvo
int moisture1_value = 0;
int moisture2_value = 0;
int moisture3_value = 0;
int moisture4_value = 0;

// Releiden pinnien määrittäminen
int relay1 = 3;
int relay2 = 4;
int relay3 = 5;
int relay4 = 6;

// Vesipumpun pinnin määrittäminen
int pump = 2;

//Näytön pinnien määrittäminen
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Näytön taustavalo
const int lcdBacklight = 13;
#define lcdON = HIGH;
#define lcdOFF = LOW;

void setup() {
  // Ulostulojen määrittäminen
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(pump, OUTPUT);

  //Taustavalon ulostulon ja tervehdystekstin määrittäminen
  pinMode(lcdBacklight, OUTPUT);
  digitalWrite(lcdBacklight, HIGH);
  lcd.begin(16, 2);
  lcd.print("Hello beautiful!");
  /*lcd.begin(16, 2);
  lcd.print("Nro.1 janoinen! ");
  lcd.setCursor(0, 1);
  lcd.print("200             ");*/

  
  // Sarjaportin määrittäminen ulostuloksi
  Serial.begin(9600);  
}


  // Määritetään kasveille voidit loopin lukemisen helpottamiseksi  
  void Kasvi1(){
    String DisplayWords;
    DisplayWords = ("Nro.1 janoinen! ");
    Serial.println(DisplayWords);
    lcd.setCursor(0, 0);
    lcd.print(DisplayWords);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(moisture1_value);
  }

  void Kasvi2(){
    String DisplayWords;
    DisplayWords = ("Nro.2 janoinen! ");
    Serial.println(DisplayWords);
    lcd.setCursor(0, 0);
    lcd.print(DisplayWords);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(moisture2_value);
  }

  void Kasvi3(){
    String DisplayWords;
    DisplayWords = ("Nro.3 janoinen! ");
    Serial.println(DisplayWords);
    lcd.setCursor(0, 0);
    lcd.print(DisplayWords);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(moisture3_value);
  }

  void Kasvi4(){
    String DisplayWords;
    DisplayWords = ("Nro.4 janoinen! ");
    Serial.println(DisplayWords);
    lcd.setCursor(0, 0);
    lcd.print(DisplayWords);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(moisture4_value);
  }

void loop() {
  
 // Kosteusarvojen lukeminen antureista
 moisture1_value = analogRead(moisture1);
 moisture2_value = analogRead(moisture2);
 moisture3_value = analogRead(moisture3);
 moisture4_value = analogRead(moisture4);

  Serial.print("Anturi1: ");
  Serial.println(moisture1_value);
  Serial.print("Anturi2: ");
  Serial.println(moisture2_value);
  Serial.print("Anturi3: ");
  Serial.println(moisture3_value);
  Serial.print("Anturi4: ");
  Serial.println(moisture4_value);
    
 // Tarkistetaan tarvitseeko joku kasvi vettä
 // ja avataan kyseiselle kasville rele
 
 if(moisture1_value<=450){
  digitalWrite(relay1, HIGH);
  Kasvi1();
 }
 if(moisture2_value<=450){
  digitalWrite(relay2, HIGH);
  Kasvi2();
 }
 if(moisture3_value<=450){
  digitalWrite(relay3, HIGH);
  Kasvi3();
 }
 if(moisture4_value<=450){
  digitalWrite(relay4, HIGH);
  Kasvi4();
 }
 
 
 // Varmistetaan, että ainakin yksi kasvi tarvitsee vettä
 // jos tarvitsee, käynnistetään moottori
 if(moisture1_value<=450 || moisture2_value<=450 || moisture3_value<=450 || moisture4_value<=450){
   digitalWrite(pump, HIGH);
 }
 
 // Annetaan kasville 5 sekuntia vettä
 delay(5000);
 
 // Sammutetaan pumppu
 digitalWrite(pump, LOW);
 
 // Suljetaan jokainen rele
 digitalWrite(relay1, LOW);
 digitalWrite(relay2, LOW);
 digitalWrite(relay3, LOW);
 digitalWrite(relay4, LOW);
 
 // Odotetaan 30 sekuntia ja toistetaan prosessi
 delay(1000);
 
}

