//Project 26 StopWatch
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);        // select the pins used on the LCD panel
#define SELECT  4
#define NONE 5
int adc_key_in = 0;
int lcd_key = 0;
long offset = 0;

int read_LCD_buttons(){               // read the buttons
    adc_key_in = analogRead(0);       // read sensor value

    if (adc_key_in < 850 && adc_key_in > 651)  return SELECT; 

    else return NONE;    
}

void setup(){
    lcd.begin(16, 2);                       // start the library
}

void loop(){
    lcd.setCursor(0, 0);                   // set the LCD cursor position
    long ms = millis();
    int sec = ms/1000;
    int min = sec / 60;
    unsigned long  finalms;

    // print the results to the lcd
    lcd.print("MS:");
    lcd.print(ms);
    lcd.print(" SEC:");
    lcd.print(sec);
    lcd.setCursor(0, 1);
    lcd.print("MIN:");
    lcd.print(min);

    lcd_key = read_LCD_buttons();

        switch (lcd_key){
            case SELECT:{
                delay(5000);
                offset+=5000;
                break;
                }
                case NONE:{
                    break;
                }
            }
     }



