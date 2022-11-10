int brightness = 0;
int fadeAmount = 5;
int delayDuration = 20;

void setup() {

    pinMode(9, OUTPUT);
    pinMode(A15, OUTPUT);
    digitalWrite(A15, LOW);

}

void loop() {

    analogWrite(9, brightness);

    brightness = brightness + fadeAmount;

    if(brightness <= 0 || brightness >= 255) {

        fadeAmount = -fadeAmount;

    }

    delay(delayDuration);

}