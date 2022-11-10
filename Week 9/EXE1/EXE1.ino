const int led[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int ledlight[] = {0, 85, 170, 255};

void setup() {
  // put your setup code here, to run once:

    for(int i = 0; i < 8; i++) {

        pinMode(led[i], OUTPUT);

    }

    for(int i = 33; i < 37; i++) {

        pinMode(i, INPUT_PULLUP);

    }

    pinMode(A15, OUTPUT);
    digitalWrite(A15, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

    int k1st = digitalRead(36);
    int k2st = digitalRead(35);
    int k3st = digitalRead(34);
    int k4st = digitalRead(33);

    if(k1st == LOW) {

        for(int i = 0; i < 8; i++) {

            analogWrite(led[i], ledlight[0]);

        }

    } else if(k2st == LOW) {

        for(int i = 0; i < 8; i++) {

            analogWrite(led[i], ledlight[1]);

        }

    } else if(k3st == LOW) {

        for(int i = 0; i < 8; i++) {

            analogWrite(led[i], ledlight[2]);

        }

    } else if(k4st == LOW) {

        for(int i = 0; i < 8; i++) {

            analogWrite(led[i], ledlight[3]);

        }

    }

}
