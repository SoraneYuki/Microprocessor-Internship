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

int num = 60;
int dl = 3;
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

    for(unsigned long elapsed = 0; elapsed < 400; elapsed = millis() - startTime) {

        pickDigit(1);
        for(int i = 0; i < 7; i++){

            digitalWrite(segpin[i], seven_seg_digits[num % 10][i]);

        }

        delay(4);

        pickDigit(2);
        for(int i = 0; i < 7; i++){

            digitalWrite(segpin[i], seven_seg_digits[num / 10][i]);

        }

        delay(4);

        if(num <= 10) {

        for(int i = 44; i < 47; i++) {

            analogWrite(i, 0);

        }

        delay(200 - (10 - num) * 20);

        for(int i = 44; i < 47; i++) {

            analogWrite(i, 255);

        }

        delay(200 - (10 - num) * 20);

        }

        if(num <= 0) {

            num = 60;
            for(int i = 44; i < 47; i++) {

                analogWrite(i, 255);

            }

        }

    }

    num--;

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