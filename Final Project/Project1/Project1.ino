#include <LiquidCrystal.h>
#include <Stepper.h>

#define a 2
#define b 3
#define a_bar 4
#define b_bar 5

LiquidCrystal lcd(49, 48, 47, 43, 42, 41);
Stepper stepper(200, a, a_bar, b, b_bar);

void setup() {

    lcd.begin(0, 0);
    lcd.clear();

    stepper.setSpeed(20);

}

void loop() {

}