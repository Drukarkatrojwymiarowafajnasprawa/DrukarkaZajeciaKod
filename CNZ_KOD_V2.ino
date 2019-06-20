#include <stdlib.h>

#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62

//
// Limit Switches
//
#define X_MIN_PIN           3
#define X_MAX_PIN           2
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19


int krok = 0, kroka = 0, krokb = 0, krokc = 0;
int kierunek = 0, kieruneka = 0, kierunekb = 0, kierunekc = 0;
String a;

void setup()
{
  Serial.begin(115200);
  
  pinMode(X_ENABLE_PIN, OUTPUT);
  digitalWrite(X_ENABLE_PIN, LOW);
  pinMode(X_DIR_PIN, OUTPUT);
  digitalWrite(X_DIR_PIN, LOW);
  pinMode(X_STEP_PIN, OUTPUT);

  pinMode(Y_ENABLE_PIN, OUTPUT);
  digitalWrite(Y_ENABLE_PIN, LOW);
  pinMode(Y_DIR_PIN, OUTPUT);
  digitalWrite(Y_DIR_PIN, LOW);
  pinMode(Y_STEP_PIN, OUTPUT);

  pinMode(Z_ENABLE_PIN, OUTPUT);
  digitalWrite(Z_ENABLE_PIN, LOW);
  pinMode(Z_DIR_PIN, OUTPUT);
  digitalWrite(Z_DIR_PIN, LOW);
  pinMode(Z_STEP_PIN, OUTPUT);

  pinMode(X_MAX_PIN, INPUT_PULLUP);
  pinMode(Y_MAX_PIN, INPUT_PULLUP);
  pinMode(Z_MAX_PIN, INPUT_PULLUP);

}


void loop()
{
  if ((kierunek == 1 || (kierunek == 0 && digitalRead (X_MAX_PIN) == 0)) && kroka > 0)
    {
      digitalWrite(X_STEP_PIN, HIGH);
      kroka--;
    }
  if ((kierunek == 1 || (kierunek == 0 && digitalRead (Y_MAX_PIN) == 0)) && krokb > 0)
    {
      digitalWrite(Y_STEP_PIN, HIGH);
      krokb--;
    }
  if ((kierunek == 1 || (kierunek == 0 && digitalRead (Z_MAX_PIN) == 0)) && krokc > 0)
    {
      digitalWrite(Z_STEP_PIN, HIGH);
      krokc--;
    }

  delay(1);
  digitalWrite(X_STEP_PIN, LOW);
  digitalWrite(Y_STEP_PIN, LOW);
  digitalWrite(Z_STEP_PIN, LOW);
  delay(1);

  krok = krok + 1;
/*  if (krok == 500)
  {
    krok = 0;
    kierunek = !kierunek;Write(X_DIR_PIN, dir1);
    }
    if (s2 < 0)
    {
      dir2 = 1;
      digitalWrite(Y_DIR_PIN, dir2);
      s2 = -s2;
    }
    else
    {
      dir2 = 0;
      digitalWrite(Y_DIR_PIN, dir2);
    }
    if (s3 < 0)
    {
      dir3 = 1;
      digitalWrite(Z_DIR_PIN, dir3);
      s3 = -s3;
    }
    else
    {
      dir3 = 0;
      digitalWrite(Z_DIR_PIN, dir3);
    }
    digitalWrite(X_DIR_PIN, kierunek);
    digitalWrite(Y_DIR_PIN, kierunek);
    digitalWrite(Z_DIR_PIN, kierunek);

  }*/

//  Serial.println(digitalRead(X_MAX_PIN));
//  Serial.println(digitalRead(Y_MAX_PIN));
//  Serial.println(digitalRead(Z_MAX_PIN));

  while(Serial.available()>0)
  {
      a = Serial.readStringUntil('\n');
      sscanf(a.c_str(),"a %d b %d c %d", &kroka, &krokb, &krokc);

      Serial.println(kroka);
      Serial.println(krokb);
      Serial.println(krokc);

      kieruneka = kroka < 0;
      digitalWrite(X_DIR_PIN, kieruneka);
      kroka = abs(kroka);

      kierunekb = krokb < 0;
      digitalWrite(Y_DIR_PIN, kierunekb);
      krokb = abs(krokb);

      kierunekc = krokc < 0;
      digitalWrite(Z_DIR_PIN, kierunekc);
      krokc = abs(krokc);
  }
}



