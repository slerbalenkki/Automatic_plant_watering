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
//#define lcdON = HIGH;
//#define lcdOFF = LOW;



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
  delay(5000);
   
  // Sarjaportin määrittäminen
  Serial.begin(9600);  
}


  // Määritetään janoisille kasveille voidit   
  /*void Kasvi1(){
    String DisplayWords;
    DisplayWords = ("Nro.1 janoinen! ");
    Serial.println(DisplayWords);
    lcd.setCursor(0, 0);
    lcd.print(DisplayWords);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(moisture1_value);
    delay(3000);
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
    delay(3000);
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
    delay(3000);
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
    delay(3000);
  }*/

  /*void Alotus(){
  lcd.setCursor(0 ,0);
  lcd.print("Hello beautiful!");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  delay(5000);
  }*/  

    
     
  
  void Kukat(){

    // Kosteusarvojen lukeminen antureista ja 
     // arvojen muuttaminen prosenteiksi
     moisture1_value = analogRead(moisture1);
     int percentValue1 = (moisture1_value)*100L/(1023-110);
     moisture2_value = analogRead(moisture2);
     int percentValue2 = (moisture2_value)*100L/(1023-110);
     moisture3_value = analogRead(moisture3);
     int percentValue3 = (moisture3_value)*100L/(1023-110);
     moisture4_value = analogRead(moisture4);
     int percentValue4 = (moisture4_value)*100L/(1023-110);

      Serial.print("Anturi1: ");
  Serial.print(percentValue1);
  Serial.println("%");
  Serial.print("Anturi2: ");
  Serial.print(percentValue2);
  Serial.println("%");
  Serial.print("Anturi3: ");
  Serial.print(percentValue3);
  Serial.println("%");
  Serial.print("Anturi4: ");
  Serial.print(percentValue4);
  Serial.println("%");
  Serial.println(" "); 

      
    //Näytönalustus
    lcd.clear(); 

    //Kukka 1
    lcd.setCursor(0, 0);
    lcd.print("K1");
    lcd.setCursor(4, 0);
    lcd.print(percentValue1);
    lcd.setCursor(6, 0);
    lcd.print("%");
       
    //kukka 2
    lcd.setCursor(8, 0);
    lcd.print("K2");
    lcd.setCursor(12, 0);
    lcd.print(percentValue2);
    lcd.setCursor(14, 0);
    lcd.print("%");
    
    //Kukka 3
    lcd.setCursor(0, 1);
    lcd.print("K3");
    lcd.setCursor(4, 1);
    lcd.print(percentValue3);
    lcd.setCursor(6, 1);
    lcd.print("%");
    
    //Kukka 4
    lcd.setCursor(8, 1);
    lcd.print("K4");
    lcd.setCursor(12, 1);
    lcd.print(percentValue4);
    lcd.setCursor(14, 1);
    lcd.print("%");    
    
    Anturi();  
  }
 

  void Anturi(){
  if(moisture1_value<=450){
  digitalWrite(relay1, HIGH);
  lcd.setCursor(2, 0);
  lcd.print("!");
  //Kasvi1();
 }
 if(moisture2_value<=450){
  digitalWrite(relay2, HIGH);
  lcd.setCursor(10, 0);
  lcd.print("!");
  //Kasvi2();
 }
 if(moisture3_value<=450){
  digitalWrite(relay3, HIGH);
  lcd.setCursor(2, 1);
  lcd.print("!");
  //Kasvi3();
 }
 if(moisture4_value<=450){
  digitalWrite(relay4, HIGH);
  lcd.setCursor(10, 1);
  lcd.print("!");
  //Kasvi4();
 }
}

 

 
 // Varmistetaan, että ainakin yksi kasvi tarvitsee vettä
 // jos tarvitsee, käynnistetään moottori

 void Kastelu(){
 if(moisture1_value<=450 || moisture2_value<=450 || moisture3_value<=450 || moisture4_value<=450){
   digitalWrite(pump, HIGH);
 }
 
 // Annetaan kasville 5 sekuntia vettä
 delay(5000);
 
 // Sammutetaan pumppu
 digitalWrite(pump, LOW);
 
 // Suljetaan jokainen venttiili
 digitalWrite(relay1, LOW);
 digitalWrite(relay2, LOW);
 digitalWrite(relay3, LOW);
 digitalWrite(relay4, LOW); 
}
  
  



void loop() {
   
  Kukat();
  Kastelu();
     
 // Odotetaan 1 sekuntia ja toistetaan prosessi
 delay(1000);
} 
