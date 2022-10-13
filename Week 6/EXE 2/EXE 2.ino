#define CA1 30
#define CA2 31
#define CA3 32

byte seven_seg_digits[17][7] = {

    {0, 0, 0, 0, 0, 0, 1},  //0
    {1, 0, 0, 1, 1, 1, 1},  //1
    {0, 0, 1, 0, 0, 1, 0},  //2
    {0, 0, 0, 0, 1, 1, 0},  //3
    {1, 0, 0, 1, 1, 0, 0},  //4
    {0, 1, 0, 0, 1, 0, 0},  //5
    {0, 1, 0, 0, 0, 0, 0},  //6
    {0, 0, 0, 1, 1, 1, 1},  //7
    {0, 0, 0, 0, 0, 0, 0},  //8
    {0, 0, 0, 1, 1, 0, 0},  //9

};

byte segpin[7] = {2, 3, 4, 5, 6, 7, 8};

int num = 4, base1 = 37, base2 = 33;
int disnum = 0;
int k1mod = 0, k2mod = 0, k3mod = 0, k4mod = 0;

void setup() {
  // put your setup code here, to run once:

    for(int i = base1; i < base1 + num; i++) {

        pinMode(i, INPUT_PULLUP);

    }

    for(int i = base2; i < base2 + num; i++) {

        pinMode(i, INPUT_PULLUP);

    }

    for(int i = 0; i < 7; i++)
    {

        pinMode(segpin[i], OUTPUT);

    }

    pinMode(9, OUTPUT);
    digitalWrite(9, HIGH);

    pinMode(A13, OUTPUT);
    digitalWrite(A13, LOW);

    pinMode(30, OUTPUT);
    pinMode(31, OUTPUT);
    pinMode(32, OUTPUT);

    digitalWrite(30, LOW);
    digitalWrite(31, LOW);
    digitalWrite(32, LOW);

    pinMode(A15, OUTPUT);
    digitalWrite(A15, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

    int k1st = digitalRead(33);
    int k2st = digitalRead(34);
    int k3st = digitalRead(35);
    int k4st = digitalRead(36);

    int dipsw1st = digitalRead(37);
    int dipsw2st = digitalRead(38);
    int dipsw3st = digitalRead(39);
    int dipsw4st = digitalRead(40);

    pickDigit(1);
    for(int i = 0; i < 7; i++) {

        digitalWrite(segpin[i], seven_seg_digits[disnum % 10][i]);

    }

    delay(5);

    pickDigit(2);
    for(int i = 0; i < 7; i++) {

        digitalWrite(segpin[i], seven_seg_digits[disnum % 100 / 10][i]);

    }

    delay(5);

    pickDigit(3);
    for(int i = 0; i < 7; i++) {

        digitalWrite(segpin[i], seven_seg_digits[disnum % 1000 / 100][i]);

    }

    delay(5);

    pickDigit(4);
    for(int i = 0; i < 7; i++) {

        digitalWrite(segpin[i], seven_seg_digits[disnum / 1000][i]);

    }

    delay(5);

    if(dipsw1st == LOW) {

        k1mod = 1;

    }
    else {

        k1mod = -1;

    }

    if(dipsw2st == LOW) {

        k2mod = 1;

    }
    else {

        k2mod = -1;

    }

    if(dipsw3st == LOW) {

        k3mod = 1;

    }
    else {

        k3mod = -1;

    }

    if(dipsw4st == LOW) {

        k4mod = 1;

    }
    else {

        k4mod = -1;

    }

    if(k4st == LOW) {

        disnum += 1 * k1mod;

    }
    else if(k3st == LOW) {

        disnum += 10 * k2mod;

    }
    else if(k2st == LOW) {

        disnum += 100 * k3mod;

    }
    else if(k1st == LOW) {

        disnum += 1000 * k4mod;

    }

    if(disnum > 9999 || disnum < 0) {

        disnum = 0;

    }

}

void pickDigit(int x) {

    digitalWrite(CA1, HIGH);
    digitalWrite(CA2, HIGH);
    digitalWrite(CA3, HIGH);

    switch(x) {

        case 1:

            digitalWrite(CA1, LOW);
            digitalWrite(CA2, LOW);
            digitalWrite(CA3, LOW);
            break;

        case 2:

            digitalWrite(CA1, HIGH);
            digitalWrite(CA2, LOW);
            digitalWrite(CA3, LOW);
            break;

        case 3:

            digitalWrite(CA1, LOW);
            digitalWrite(CA2, HIGH);
            digitalWrite(CA3, LOW);
            break;

        case 4:

            digitalWrite(CA1, HIGH);
            digitalWrite(CA2, HIGH);
            digitalWrite(CA3, LOW);
            break;

    }

}