int base = 6, num = 4, base1 = 33;

void setup() {
  // put your setup code here, to run once:

    for(int i = base; i < base + num; i++) {

        pinMode(i, OUTPUT);

    }

    for(int i = base1; i < base1 + num; i++) {

        pinMode(i, INPUT_PULLUP);

    }

    pinMode(A15, OUTPUT);
    digitalWrite(A15, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

    int k1st = digitalRead(33);
    digitalWrite(9, k1st);

    int k2st = digitalRead(34);
    digitalWrite(8, k2st);

    int k3st = digitalRead(35);
    digitalWrite(7, k3st);

    int k4st = digitalRead(36);
    digitalWrite(6, k4st);

}
