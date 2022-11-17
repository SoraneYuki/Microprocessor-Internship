const int motorin1 = 2;
const int motorin2 = 3;
const int DELAY = 1000;

void setup() {
    
    pinMode(motorin1, OUTPUT);
    pinMode(motorin2, OUTPUT);

}

void loop() {

    forward();
    delay(DELAY);
    motorstop();
    delay(500);
    backward();
    delay(DELAY);
    motorstop();
    delay(500);

}

void forward() {

    digitalWrite(motorin1, HIGH);
    digitalWrite(motorin2, LOW);

}

void backward() {

    digitalWrite(motorin1, LOW);
    digitalWrite(motorin2, HIGH);

}

void motorstop() {

    digitalWrite(motorin1, LOW);
    digitalWrite(motorin2, LOW);

}