#define trigpin 12
#define echopin 13

#include <LiquidCrystal.h>

LiquidCrystal lcd(49, 48, 47, 43, 42, 41);

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
    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.print("Distance:     cm");

}

void loop() {

    long duration, cm;
    String result = "Distance: ";
    duration = ping();
    cm = duration / 58;
    result += cm;
    result += "(cm).";
    Serial.println(result);
    lcd.setCursor(0, 0);
    lcd.print("Distance:     cm");
    lcd.setCursor(9, 0);
    lcd.print(cm);
    delay(1000);

}