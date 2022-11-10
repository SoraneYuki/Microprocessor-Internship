#define CA1 30
#define CA2 31
#define CA3 32

int rp = 44;
int gp = 45;
int bp = 46;

byte seven_seg_digits[10][7] = {

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

int lnum = 60;
int rnum = 60;
int num = 7;

int mod = 0;

void setup() {
  // put your setup code here, to run once:

    pinMode(rp, OUTPUT);
    pinMode(gp, OUTPUT);
    pinMode(bp, OUTPUT);

    for(int i = 0; i < 7; i++)
    {

        pinMode(segpin[i], OUTPUT);

    }

    pinMode(9, OUTPUT);
    digitalWrite(9, HIGH);

    pinMode(A13, OUTPUT);
    digitalWrite(A13, LOW);

    pinMode(CA1, OUTPUT);
    pinMode(CA2, OUTPUT);
    pinMode(CA3, OUTPUT);

    digitalWrite(CA1, LOW);
    digitalWrite(CA2, LOW);
    digitalWrite(CA3, LOW);

    analogWrite(rp, 255);
    analogWrite(gp, 255);
    analogWrite(bp, 255);

}

void loop() {
  // put your main code here, to run repeatedly:

    unsigned long startTime = millis();

    for(unsigned long elapsed = 0; elapsed < 300; elapsed = millis() - startTime) {

        pickDigit(1);
        for(int i = 0; i < 7; i++){

            digitalWrite(segpin[i], seven_seg_digits[rnum % 10][i]);

        }

        delay(4);

        pickDigit(2);
        for(int i = 0; i < 7; i++){

            digitalWrite(segpin[i], seven_seg_digits[rnum / 10][i]);

        }

        delay(4);

        pickDigit(3);
        for(int i = 0; i < 7; i++){

            digitalWrite(segpin[i], seven_seg_digits[lnum % 10][i]);

        }

        delay(4);

        pickDigit(4);
        for(int i = 0; i < 7; i++){

            digitalWrite(segpin[i], seven_seg_digits[lnum / 10][i]);

        }

        delay(4);

    }

    if(mod == 0) {

        analogWrite(gp, 0);
        lnum--;

        if(lnum <= 0) {

            analogWrite(rp, 0);
            mod = 1;

        }

    }
    else if(mod == 1) {

        num--;
        if(num <= 0) {

            mod = 2;
            num = 7;

        }

    }
    else if(mod == 2) {
    
        analogWrite(gp, 255);
        rnum--;

        if(rnum < 0) {

            analogWrite(gp, 0);
            analogWrite(rp, 255);
            lnum = 60;
            rnum = 60;
            mod = 0;

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