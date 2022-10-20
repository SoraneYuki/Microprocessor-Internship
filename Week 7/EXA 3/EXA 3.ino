#include <LiquidCrystal.h>

int joypinx = A1;
int joypiny = A2;
int joysw = A3;

int value = 0;
int xzero = 0;
int yzero = 0;
int swst = 0;

LiquidCrystal lcd(49, 48, 47, 43, 42, 41);

void setup() {

    pinMode(swst, INPUT_PULLUP);
    xzero = analogRead(joypinx);
    yzero = analogRead(joypiny);

    lcd.begin(16, 2);

}

void loop() {

    int x, y, value;

    lcd.setCursor(0, 0);
    lcd.print("X=      Y=    ");
    lcd.setCursor(0, 1);
    lcd.print("SW= ");

    value = analogRead(joypinx);
    x = value - xzero;

    value = analogRead(joypiny);
    y = value - yzero;

    swst = digitalRead(joysw);

    lcd.setCursor(2, 0);
    lcd.print(x);

    lcd.setCursor(10, 0);
    lcd.print(y);

    lcd.setCursor(3, 1);
    lcd.print(swst);

    delay(30);

}