const int motorin1 = 2;
const int motorin2 = 3;
const int DELAY = 500;

void setup() {
    
    pinMode(motorin1, OUTPUT);
    pinMode(motorin2, OUTPUT);

}

void loop() {

    digitalWrite(motorin2, LOW);

    for(int i = 0; i <= 255; i += 10) {
        
        analogWrite(motorin1, i);
        delay(DELAY);

    }

    for(int i = 255; i >= 100; i -= 10) {
        
        analogWrite(motorin1, i);
        delay(DELAY);

    }

}