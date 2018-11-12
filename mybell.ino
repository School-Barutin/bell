#include <TimeLib.h>

#include <DS3231.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

const int relay = 7;

DS3231  rtc(A4, A5);

unsigned long startMillis = 0;
unsigned long currentMillis = 0;

int bellDuration = 7000; 

unsigned long eventDuration;

String eventName;

unsigned long  timeElapsed;

//h- hour, m- minute of next event
int h,m;

void selectNextEvent(){
  
  if(hour()<= 7 && minute()< 55 ){
    //1 lesson 1 bell
    h=7; 
    m=55;
    eventDuration=(7*60*60000+54*60000-3500)-(hour()*60*60000 + minute()*60000 + second()*1000);
    eventName = "1 Mejduchasie 1 zv";
  }

  if(hour()== 7 && minute()>= 55 ){
    //1 lesson 2 bell
    h=8; 
    m=0;
    eventDuration=5*60000;
    eventName = "1 Mejduchasie 2 zv";
  }

  if(hour()== 8 && minute()<45 ){
    //1 lesson 3 bell
    h=8; 
    m=45;
    eventDuration=45*60000;
    eventName = "1 Chas            ";
    
  }

  if(hour()== 8 && minute()>=45 ){
    //2 lesson 1 bell
    h=9; 
    m=0;
    eventDuration=15*60000;
    eventName = "2 Mejduchasie 1 zv";
  }
  if(hour()== 9 && minute()>=0 && minute()<5){
    //2 lesson 2 bell
    h=9; 
    m=5;
    eventDuration=5*60000;
    eventName = "2 Mejduchasie 2 zv";
  }
  if(hour()== 9 && minute()>=5 && minute()<50){
    //2 lesson 3 bell
    h=9; 
    m=50;
    eventDuration=45*60000;
    eventName = "2 Chas            ";
  }

  if(hour()== 9 && minute()>=50 && minute()<55){
    //3 lesson 1 bell
    h=9; 
    m=55;
    eventDuration=5*60000;
    eventName = "3 Mejduchasie 1 zv";
  }

  if(hour()== 9 && minute()>=55){
    //3 lesson 2 bell
    h=10; 
    m=0;
    eventDuration=5*60000;
    eventName = "3 Mejduchasie 2 zv";
  }

  if(hour()== 10 && minute()<45){
    //3 lesson 3 bell
    h=10; 
    m=45;
    eventDuration=45*60000;
    eventName = "3 Chas            ";
  }
   
  if(hour()== 10 && minute()>=45 && minute()<50){
    //4 lesson 1 bell
    h=10; 
    m=50;
    eventDuration=5*60000;
    eventName = "4 Mejduchasie 1 zv";
  }

  if(hour()== 10 && minute()>=50 && minute()<55){
    //4 lesson 2 bell
    h=10; 
    m=55;
    eventDuration=5*60000;
    eventName = "4 Mejduchasie 2 zv";
  }

  if((hour()== 10 && minute()>=55) || (hour()== 11 && minute()<40)){
    //4 lesson 3 bell
    h=11; 
    m=40;
    eventDuration=45*60000;
    eventName = "4 Chas            ";
  }

  if(hour()== 11 && minute()>=40 && minute()<45){
     //5 lesson 1 bell
    h=11; 
    m=45;
    eventDuration=5*60000;
    eventName = "5 Mejduchasie 1 zv";
  }

  if(hour()== 11 && minute()>=45 && minute()<50){
     //5 lesson 2 bell
    h=11; 
    m=50;
    eventDuration=5*60000;
    eventName = "5 Mejduchasie 2 zv";
  }

  if((hour()== 11 && minute()>=50) || (hour()== 12 && minute()<35)){
     //5 lesson 3 bell
    h=12; 
    m=35;
    eventDuration=45*60000;
    eventName = "5 Chas            ";
  }

  if(hour()== 12 && minute()>=35 && minute()<40){
     //6 lesson 1 bell
    h=12; 
    m=40;
    eventDuration=5*60000;
    eventName = "6 Mejduchasie 1 zv";
  }

  if(hour()== 12 && minute()>=40 && minute()<45){
     //6 lesson 2 bell
    h=12; 
    m=45;
    eventDuration=5*60000;
    eventName = "6 Mejduchasie 2 zv";
  }

  if((hour()== 12 && minute()>=45) || (hour()== 13 && minute()<30)){
     //6 lesson 3 bell
    h=13; 
    m=30;
    eventDuration=45*60000;
    eventName = "6 Chas            ";
  }

  if(hour()== 13 && minute()>=30 && minute()<35){
     //7 lesson 1 bell
    h=13; 
    m=35;
    eventDuration=5*60000;
    eventName = "7 Mejduchasie 1 zv";
  }

  if(hour()== 13 && minute()>=35 && minute()<40){
     //7 lesson 2 bell
    h=13; 
    m=40;
    eventDuration=5*60000;
    eventName = "7 Mejduchasie 2 zv";
  }

  if((hour()== 13 && minute()>=40) || (hour()== 14 && minute()<25)){
     //7 lesson 3 bell
    h=14; 
    m=25;
    eventDuration=45*60000;
    eventName = "7 Chas            ";
  }
  
//  if((hour()== 14 && minute()>25) || (hour()> 14 && minute()>=25)){
//     //1 lesson 1 bell
//    h=14; 
//    m=25;
//    eventDuration=5*60000;
//    eventName = "1 Mejduchasie 1 zv";
//  }
  
}

void setup() {
  
  Serial.begin(9600);
  
  pinMode(relay, OUTPUT);
  
  digitalWrite(relay, HIGH);
  
  lcd.init();  
  lcd.backlight(); 
  
  rtc.begin();

//  rtc.setDOW(MONDAY);     // Set Day-of-Week to SUNDAY
//  rtc.setTime(17, 18, 20);     // Set the time to 12:00:00 (24hr format)
//  rtc.setDate(12, 11, 2018); 
  
  setTime(rtc.getUnixTime(rtc.getTime()));

  selectNextEvent();
  
}

void loop() {

  if(hour() == h && minute() == m && second()== 0){
     startMillis = millis();
     selectNextEvent();
  }

  currentMillis = millis();

  timeElapsed = currentMillis-startMillis;

  if( timeElapsed <= bellDuration && startMillis > 0){
    digitalWrite(relay, LOW);
  }
  else {
    digitalWrite(relay, HIGH);
  }

  lcd.setCursor(15, 3);
    if(((eventDuration - timeElapsed)/60000)<10)
      lcd.print("0");
  lcd.print((eventDuration - timeElapsed)/60000);

  lcd.setCursor(17, 3);
  lcd.print(F(":"));
  
  lcd.setCursor(18, 3);
    if(((eventDuration - timeElapsed)%60000)<10)
      lcd.print("0");
  lcd.print((eventDuration - timeElapsed)%60000);
  
  lcd.setCursor(0, 0);
  lcd.print(rtc.getDOWStr());

  lcd.setCursor(10, 0);
  lcd.print(rtc.getDateStr());\

  lcd.setCursor(0, 1);
  lcd.print(rtc.getTimeStr());

  lcd.setCursor(13, 1);
  lcd.print(rtc.getTemp());
  lcd.print(" C");

  lcd.setCursor(0, 2);
  lcd.print(eventName);

  lcd.setCursor(0, 3);
    if(h<10)
      lcd.print("0");
  lcd.print(h);

  lcd.setCursor(2, 3);
  lcd.print(F(":"));

  lcd.setCursor(3, 3);
    if(m<10)
      lcd.print("0");
  lcd.print(m);

  lcd.setCursor(5, 3);
  lcd.print(F(":00"));

  lcd.setCursor(10, 3);
  lcd.print(F("Ost:"));
}
