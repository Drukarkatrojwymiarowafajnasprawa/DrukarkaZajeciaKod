#include <LiquidCrystal.h>

#define TEMP_0_PIN 13

#ifndef RAMPS_D10_PIN
  #define RAMPS_D10_PIN    10
#endif

#define HEATER_0_PIN       RAMPS_D10_PIN

#define a -4.52095923146465e-07
#define b 0.000771676586865781
#define c -0.546501992496493
#define d 242.002559782888

LiquidCrystal lcd(16, 17, 23, 25, 27, 29);

double e, calka, proporcja;
int k = 75, u;

void setup() 
{
  lcd.begin(20, 4);
  pinMode(HEATER_0_PIN, OUTPUT);
   
}

void loop() 
{
  lcd.setCursor(0, 0);
  lcd.print("Howdy");

  double temp = analogRead(TEMP_0_PIN);

  double aproks = a*pow(temp,3) + b*pow(temp,2) + c*temp + d;
  
  lcd.setCursor(0, 1);
  lcd.print(aproks);

/*
  if(k != 0)
  {
    digitalWrite(HEATER_0_PIN, HIGH);
    k--;
  }
  else
  {
    digitalWrite(HEATER_0_PIN, LOW);
  }*/

  e = 180 - aproks;

  if(calka < 500)
  {
    
  }
  calka = calka + 0.06 * e;

  proporcja = 255/80*e;
  
  u = round(255/80*e+0.1*calka);
  
  if(u > 255)
  {
    u = 255; 
  }
  if(u < 0)
  {
    u = 0;
  }

  analogWrite(HEATER_0_PIN, u);
  lcd.setCursor(0,2);
  lcd.print(proporcja);
  lcd.setCursor(0,3);
  lcd.print(calka);

  delay(100);
  
}
  


