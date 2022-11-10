int pin = A6;
int Value = 0;

const int led[] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup() {

    for(int i = 0; i < 8; i++) {

        pinMode(led[i], OUTPUT);

    }

    pinMode(A15, OUTPUT);
    digitalWrite(A15, LOW);

}

void loop() {

    Value = analogRead(pin);

    if(Value / 4 > 250) {

        for(int i = 0; i < 8; i++) {

            digitalWrite(led[i], LOW);

        }

    }
    else {

        for(int i = 0; i < 8; i++) {

            digitalWrite(led[i], HIGH);

        }

    }

}