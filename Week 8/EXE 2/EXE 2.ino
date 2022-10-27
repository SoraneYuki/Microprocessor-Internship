#include <LiquidCrystal.h>

LiquidCrystal lcd(49, 48, 47, 43, 42, 41);

int joyx = A1;
int joyy = A2;

int value = 0;
int xzero = 0;
int yzero = 0;

int cursorx = 0;
int cursory = 0;

void setup() {

    xzero = analogRead(joyx);
    yzero = analogRead(joyy);

    lcd.begin(16, 2);

}

void loop() {

    int x, y, value;

    value = analogRead(joyx);
    x = value - xzero;
    value = analogRead(joyy);
    y = value - yzero;

    //x -500 up, 500 down
    //y -500 right, 500 left

    lcd.setCursor(cursory, cursorx);
    lcd.print("Arduino");

    if(y > 500) {

        if(cursory > 0) {

            cursory--;

        }

    }
    else if(y < -500) {

        if(cursory < 9) {

            cursory++;

        }

    }
    else if(x < -500) {

        if(cursorx == 1) {

            cursorx = 0;

        }

    }
    else if(x > 500) {

        if(cursorx == 0) {

            cursorx = 1;

        }

    }

    delay(30);

    lcd.clear();

}