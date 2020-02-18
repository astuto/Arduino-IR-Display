#include <IRremote.h>
#include <IRremoteInt.h>

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

int lcdColumns = 20;
int lcdRows = 4;

int IRpin = 6;
IRrecv irrecv(IRpin);
decode_results results;



void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
}


void loop(){
   if (irrecv.decode(&results))
    {
     lcd.begin(20,4);
     lcd.setCursor(0,0); // Zeile 0 Feld 0
     lcd.print("DEC: ");
     lcd.print(results.value, DEC);
     lcd.setCursor(0,1); // Zeile 1 Feld 0
     lcd.print("HEX: ");
     lcd.print(results.value, HEX);
     
     irrecv.resume();
     delay(1000);
    }
}
