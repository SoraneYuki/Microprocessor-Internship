#include <Keypad.h>

#define CA1 30
#define CA2 31
#define CA3 32

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

int num1 = 0;
int num2 = 0;
int num3 = 0;
int num4 = 0;

int redpin = 44;
int grnpin = 45;
int blupin = 46;

int mod = 0;
int waitdis = 0;

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {{'F','E','D','C'},
                         {'B','3','6','9'},
                         {'A','2','5','8'},
                         {'0','1','4','7'}};

byte rowPins[ROWS] = {25, 24, 23, 22};
byte colPins[COLS] = {29, 28, 27, 26};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

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

    pinMode(redpin, OUTPUT);
    pinMode(grnpin, OUTPUT);
    pinMode(blupin, OUTPUT);

    analogWrite(redpin, 255);
    analogWrite(grnpin, 255);
    analogWrite(blupin, 255);

}

void loop() {
  // put your main code here, to run repeatedly:

    int tempdis = 0;
    char key = keypad.getKey();

    pickDigit(1);
    for(int i = 0; i < 7; i++) {

        digitalWrite(segpin[i], seven_seg_digits[num4][i]);

    }

    delay(5);

    pickDigit(2);
    for(int i = 0; i < 7; i++) {

        digitalWrite(segpin[i], seven_seg_digits[num3][i]);

    }

    delay(5);

    pickDigit(3);
    for(int i = 0; i < 7; i++) {

        digitalWrite(segpin[i], seven_seg_digits[num2][i]);

    }

    delay(5);

    pickDigit(4);
    for(int i = 0; i < 7; i++) {

        digitalWrite(segpin[i], seven_seg_digits[num1][i]);

    }

    delay(5);

    if(key != NO_KEY) {

        if(key == 'C') {

            num1 = 0;
            num2 = 0;
            num3 = 0;
            num4 = 0;
            mod = 0;

        }
        else if(key == '0') {

            tempdis = 0;
            waitdis = 1;

        }
        else if(key == '1') {

            tempdis = 1;
            waitdis = 1;

        }
        else if(key == '2') {

            tempdis = 2;
            waitdis = 1;

        }
        else if(key == '3') {

            tempdis = 3;
            waitdis = 1;

        }
        else if(key == '4') {

            tempdis = 4;
            waitdis = 1;

        }
        else if(key == '5') {

            tempdis = 5;
            waitdis = 1;

        }
        else if(key == '6') {

            tempdis = 6;
            waitdis = 1;

        }
        else if(key == '7') {

            tempdis = 7;
            waitdis = 1;

        }
        else if(key == '8') {

            tempdis = 8;
            waitdis = 1;

        }
        else if(key == '9') {

            tempdis = 9;
            waitdis = 1;

        }

    }

    if(waitdis == 1) {

        if(mod == 0) {

            num1 = tempdis;
            mod = 1;

        }
        else if(mod == 1) {

            num2 = tempdis;
            mod = 2;

        }
        else if(mod == 2) {

            num3 = tempdis;
            mod = 3;

        }
        else if(mod == 3) {

            num4 = tempdis;

            if(num1 == 1 && num2 == 4 && num3 == 5 && num4 == 0) {

                analogWrite(redpin, 255);
                analogWrite(grnpin, 0);
                analogWrite(blupin, 255);

                delay(2000);

                analogWrite(redpin, 255);
                analogWrite(grnpin, 255);
                analogWrite(blupin, 255);

                num1 = 0;
                num2 = 0;
                num3 = 0;
                num4 = 0;

            }
            else {

                analogWrite(redpin, 0);
                analogWrite(grnpin, 255);
                analogWrite(blupin, 255);

                delay(2000);

                analogWrite(redpin, 255);
                analogWrite(grnpin, 255);
                analogWrite(blupin, 255);

                num1 = 0;
                num2 = 0;
                num3 = 0;
                num4 = 0;

            }

            mod = 0;

        }

        waitdis = 0;

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