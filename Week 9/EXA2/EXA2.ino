int BASE = 2;
int NUM = 8;
int brightness = 0;
int fadeAmount = 5;
int delayDuration = 20;

void setup() {

    for(int i = 0; i < BASE + NUM; i++) {

        pinMode(i, OUTPUT);

    }
    
    pinMode(A15, OUTPUT);
    digitalWrite(A15, LOW);

}

void loop() {

    for(int i = BASE; i < BASE + NUM; i++) {

        analogWrite(i, brightness);

    }

    brightness = brightness + fadeAmount;

    if(brightness <= 0 || brightness >= 255) {

        fadeAmount = -fadeAmount;

    }

    delay(delayDuration);

}