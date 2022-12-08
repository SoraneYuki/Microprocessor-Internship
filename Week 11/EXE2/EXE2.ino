#define a 2
#define b 3
#define a_bar 4
#define b_bar 5 

#include <Stepper.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(49, 48, 47, 43, 42, 41);

Stepper stepper(200, a, a_bar, b, b_bar);

int joypiny = A2;

int value = 0;
int yzero = 0;

int R = 0, nowr = 0;

void setup() {

    stepper.setSpeed(100);

    yzero = analogRead(joypiny);

    lcd.begin(16, 2);
    lcd.clear();

}

void loop() {

    int y, value;

    value = analogRead(joypiny);
    y = value - yzero;

    if(y > 100) {

        stepper.step(-20);
        R++;

        if(R >= 100) {

            nowr++;
            R = 0;

        }

        lcd.setCursor(4, 0);
        lcd.print(nowr);

    }
    else if(y < -100) {

        stepper.step(20);
        R++;

        if(R >= 100) {

            nowr++;
            R = 0;

        }

        lcd.setCursor(4, 0);
        lcd.print(nowr);

    }
    else {

        R = 0;
        nowr = 0;
    
    }

    lcd.setCursor(0, 0);
    lcd.print("R =     ");
    lcd.setCursor(4, 0);
    lcd.print(nowr);

}