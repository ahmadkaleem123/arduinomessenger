#include <SoftwareSerial.h>
SoftwareSerial BTserial(9, 10);
#include <stdio.h>
#include <ctype.h>
int n = 0;
#include <LiquidCrystal.h>
char state;
char state2;
char text;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  Serial.begin(9600);
  BTserial.begin(9600);
  lcd.print("Send a Text");

}

void loop() {
  if(Serial.available()>0)
  {
    state = Serial.read();
    BTserial.print(state);
    Serial.println(state);
  }
   if(BTserial.available()>0)
    {     
      state = BTserial.read();
      delay(100);  
      if (state == '#'){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Send a Text");
        n=0;
      }
      if (isalpha(state) != 0 || isdigit(state) !=0 || state == ' '){
        text = state;
        lcd.setCursor(n,1);
        lcd.print(text);
        //Serial.print(text);
        if (n<15){
          n++;
        }
        else{
          delay(100);
          n = 0;
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Send a Text");
      }
    }

    }
    

}
