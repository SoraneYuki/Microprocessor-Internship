#define a 2
#define b 3
#define a_bar 4
#define b_bar 5 

#define trigpin 12
#define echopin 13

#include <Stepper.h>

Stepper stepper(200, a, a_bar, b, b_bar);

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

    stepper.setSpeed(100);

}

void loop() {

    long duration, cm;
    duration = ping();
    cm = duration / 58;

    if(cm < 8) {

        stepper.step(0);

    }
    else {

        stepper.step(200);

    }

    delay(50);

}