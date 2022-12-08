#define a 2
#define b 3
#define a_bar 4
#define b_bar 5 

#include <Stepper.h>

Stepper stepper(200, a, a_bar, b, b_bar);

void setup() {

    stepper.setSpeed(20);

}

void loop() {

    stepper.step(200);
    stepper.step(-200);

}