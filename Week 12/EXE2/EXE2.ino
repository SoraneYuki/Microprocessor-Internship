#define trigpin 12
#define echopin 13

int BUZZER = A9;

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
    pinMode(BUZZER, OUTPUT);

    pinMode(blupin, OUTPUT);

}

void loop() {

    long duration, cm;
    duration = ping();
    cm = duration / 40;

    if(cm > 500) {

        digitalWrite(BUZZER, HIGH);
        digitalWrite(blupin, LOW);
        delay(300);
        digitalWrite(BUZZER, LOW);
        digitalWrite(blupin, HIGH);
        delay(300);

    }
    else {

        digitalWrite(BUZZER, HIGH);
        digitalWrite(blupin, HIGH);
        delay(cm);
        digitalWrite(BUZZER, LOW);
        digitalWrite(blupin, LOW);
        delay(cm);

    }

    

    delay(300);

}