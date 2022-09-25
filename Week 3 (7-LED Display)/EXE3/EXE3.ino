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
    {0, 0, 0, 1, 0, 0, 0},  //A
    {1, 1, 0, 0, 0, 0, 0},  //b
    {0, 1, 1, 0, 0, 0, 1},  //C
    {1, 0, 0, 0, 0, 1, 0},  //d
    {0, 1, 1, 0, 0, 0, 0},  //E
    {0, 1, 1, 1, 0, 0, 0}   //F

};

byte segpin[7] = {2, 3, 4, 5, 6, 7, 8};

int nnum = 0;
int snum = 0;

void setup() {
  // put your setup code here, to run once:

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

}

void loop() {
  // put your main code here, to run repeatedly:

    pickDigit(1);
    for(int i = 0; i < 7; i++) {

        digitalWrite(segpin[i], seven_seg_digits[snum % 10][i]);

    }

    delay(5);

    pickDigit(2);
    for(int i = 0; i < 7; i++) {

        digitalWrite(segpin[i], seven_seg_digits[snum / 10][i]);

    }

    delay(5);

    pickDigit(3);
    for(int i = 0; i < 7; i++) {

        digitalWrite(segpin[i], seven_seg_digits[nnum % 10][i]);

    }

    delay(5);

    pickDigit(4);
    for(int i = 0; i < 7; i++) {

        digitalWrite(segpin[i], seven_seg_digits[nnum / 10][i]);

    }

    delay(5);

    snum++;

    if(snum >= 60) {

        nnum++;
        snum = 0;

        if(nnum >= 60) {

            nnum = 0;

        }

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