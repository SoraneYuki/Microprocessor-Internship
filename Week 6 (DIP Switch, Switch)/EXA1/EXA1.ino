int base = 2, num = 4, base1 = 37, dipsw1st, dipsw2st, dipsw3st, dipsw4st;

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

    dipsw1st = digitalRead(37);
    digitalWrite(2, dipsw1st);

    dipsw2st = digitalRead(38);
    digitalWrite(3, dipsw2st);

    dipsw3st = digitalRead(39);
    digitalWrite(4, dipsw3st);

    dipsw4st = digitalRead(40);
    digitalWrite(5, dipsw4st);

}
