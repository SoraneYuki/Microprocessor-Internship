#define trigpin 12
#define echopin 13

#include <LiquidCrystal.h>

LiquidCrystal lcd(49, 48, 47, 43, 42, 41);

int redpin = 44;
int grnpin = 45;
int blupin = 46;

long ping() {

    digitalWrite(trigpin, LOW);
    delayMicroseconds(12);
    digitalWrite(trigpin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin, LOW);
    return pulseIn(echopin, HIGH);

}

void setup() {

    pinMode(trigpin, OUTPUT);
    pinMode(echopin, INPUT);

    pinMode(redpin, OUTPUT);
    pinMode(grnpin, OUTPUT);
    pinMode(blupin, OUTPUT);

    lcd.begin(16, 2);
    lcd.print("Distance:     in");

}

void loop() {

    long duration, in;
    duration = ping();
    in = duration / 148;
    lcd.setCursor(0, 0);
    lcd.print("Distance:     in");
    lcd.setCursor(9, 0);
    lcd.print(in);

    if(in <= 10) {

        analogWrite(redpin, 0);
        analogWrite(grnpin, 255);
        analogWrite(blupin, 255);

    }
    else {

        analogWrite(redpin, 255);
        analogWrite(grnpin, 0);
        analogWrite(blupin, 255);

    }

    delay(500);

}