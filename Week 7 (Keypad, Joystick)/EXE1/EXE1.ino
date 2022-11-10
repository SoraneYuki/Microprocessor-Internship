#include <Keypad.h>

#define ls138A 30
#define ls138B 31
#define ls138C 32

#define row 8
#define col 8

#define data_0 {0, 0, 1, 1, 1, 0, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 0, 1, 1, 1, 0, 0, 0}

#define data_1 {0, 0, 0, 1, 0, 0, 0, 0,\
                0, 0, 1, 1, 0, 0, 0, 0,\
                0, 0, 0, 1, 0, 0, 0, 0,\
                0, 0, 0, 1, 0, 0, 0, 0,\
                0, 0, 0, 1, 0, 0, 0, 0,\
                0, 0, 0, 1, 0, 0, 0, 0,\
                0, 0, 0, 1, 0, 0, 0, 0,\
                0, 0, 1, 1, 1, 0, 0, 0}

#define data_2 {0, 0, 1, 1, 1, 0, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 0, 0, 0, 0, 1, 0, 0,\
                0, 0, 0, 0, 0, 1, 0, 0,\
                0, 0, 0, 0, 1, 0, 0, 0,\
                0, 0, 0, 1, 0, 0, 0, 0,\
                0, 0, 1, 0, 0, 0, 0, 0,\
                0, 1, 1, 1, 1, 1, 0, 0}

#define data_3 {0, 0, 1, 1, 1, 0, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 0, 0, 0, 0, 1, 0, 0,\
                0, 0, 0, 0, 1, 0, 0, 0,\
                0, 0, 0, 1, 1, 0, 0, 0,\
                0, 0, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 0, 1, 1, 1, 0, 0, 0}

#define data_4 {0, 0, 0, 0, 1, 0, 0, 0,\
                0, 0, 0, 1, 1, 0, 0, 0,\
                0, 0, 1, 0, 1, 0, 0, 0,\
                0, 0, 1, 0, 1, 0, 0, 0,\
                0, 1, 0, 0, 1, 0, 0, 0,\
                0, 1, 1, 1, 1, 1, 0, 0,\
                0, 0, 0, 0, 1, 0, 0, 0,\
                0, 0, 0, 0, 1, 0, 0, 0}

#define data_5 {0, 1, 1, 1, 1, 1, 0, 0,\
                0, 1, 0, 0, 0, 0, 0, 0,\
                0, 1, 0, 0, 0, 0, 0, 0,\
                0, 1, 1, 1, 1, 0, 0, 0,\
                0, 0, 0, 0, 0, 1, 0, 0,\
                0, 0, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 0, 1, 1, 1, 0, 0, 0}

#define data_6 {0, 0, 0, 1, 1, 1, 0, 0,\
                0, 0, 1, 0, 0, 0, 0, 0,\
                0, 1, 0, 0, 0, 0, 0, 0,\
                0, 1, 1, 1, 1, 0, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 0, 1, 1, 1, 0, 0, 0}

#define data_7 {0, 1, 1, 1, 1, 1, 0, 0,\
                0, 0, 0, 0, 0, 1, 0, 0,\
                0, 0, 0, 0, 0, 1, 0, 0,\
                0, 0, 0, 0, 1, 0, 0, 0,\
                0, 0, 0, 1, 0, 0, 0, 0,\
                0, 0, 1, 0, 0, 0, 0, 0,\
                0, 0, 1, 0, 0, 0, 0, 0,\
                0, 0, 1, 0, 0, 0, 0, 0}

#define data_8 {0, 0, 1, 1, 1, 0, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 0, 1, 1, 1, 0, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 0, 1, 1, 1, 0, 0, 0}

#define data_9 {0, 0, 1, 1, 1, 0, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 0, 1, 1, 1, 1, 0, 0,\
                0, 0, 0, 0, 0, 1, 0, 0,\
                0, 0, 0, 0, 0, 1, 0, 0,\
                0, 0, 0, 0, 1, 0, 0, 0,\
                0, 0, 1, 1, 0, 0, 0, 0}

#define data_A {0, 0, 1, 1, 1, 0, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 1, 1, 1, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0}

#define data_B {0, 1, 1, 1, 1, 0, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 1, 1, 1, 0, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 1, 1, 1, 0, 0, 0}

#define data_C {0, 0, 1, 1, 1, 0, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 0, 0, 0,\
                0, 1, 0, 0, 0, 0, 0, 0,\
                0, 1, 0, 0, 0, 0, 0, 0,\
                0, 1, 0, 0, 0, 0, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 0, 1, 1, 1, 0, 0, 0}

#define data_D {0, 1, 1, 1, 0, 0, 0, 0,\
                0, 1, 0, 0, 1, 0, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 1, 0, 0, 0,\
                0, 1, 1, 1, 0, 0, 0, 0}

#define data_E {0, 1, 1, 1, 1, 1, 0, 0,\
                0, 1, 0, 0, 0, 0, 0, 0,\
                0, 1, 0, 0, 0, 0, 0, 0,\
                0, 1, 1, 1, 1, 0, 0, 0,\
                0, 1, 0, 0, 0, 0, 0, 0,\
                0, 1, 0, 0, 0, 0, 0, 0,\
                0, 1, 0, 0, 0, 0, 0, 0,\
                0, 1, 1, 1, 1, 1, 0, 0}

#define data_F {0, 1, 1, 1, 1, 1, 0, 0,\
                0, 1, 0, 0, 0, 0, 0, 0,\
                0, 1, 0, 0, 0, 0, 0, 0,\
                0, 1, 1, 1, 1, 0, 0, 0,\
                0, 1, 0, 0, 0, 0, 0, 0,\
                0, 1, 0, 0, 0, 0, 0, 0,\
                0, 1, 0, 0, 0, 0, 0, 0,\
                0, 1, 0, 0, 0, 0, 0, 0}

boolean word_array[16][row][col] = {data_0, data_1, data_2, data_3, data_4, data_5, data_6, data_7, data_8, data_9, data_A, data_B, data_C, data_D, data_E, data_F};
boolean led[row][col];

byte rowpin[row] = {2, 3, 4, 5, 6, 7, 8, 9};

int dis = 0;

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

    pinMode(ls138A, OUTPUT);
    pinMode(ls138B, OUTPUT);
    pinMode(ls138C, OUTPUT);

    for (int i = 0; i < 8; i++) {

        pinMode(rowpin[i], OUTPUT);

    }

    clearled();
    pinMode(A14, OUTPUT);
    digitalWrite(A14, LOW);

    Serial.begin(9600);

}

void loop() {
    // put your main code here, to run repeatedly:

    char key = keypad.getKey();

    if (key != NO_KEY) {

        Serial.println(key);

        if(key == '0') {

            dis = 0;

        }
        else if(key == '1') {

            dis = 1;

        }
        else if(key == '2') {

            dis = 2;

        }
        else if(key == '3') {

            dis = 3;

        }
        else if(key == '4') {

            dis = 4;

        }
        else if(key == '5') {

            dis = 5;

        }
        else if(key == '6') {

            dis = 6;

        }
        else if(key == '7') {

            dis = 7;

        }
        else if(key == '8') {

            dis = 8;

        }
        else if(key == '9') {

            dis = 9;

        }
        else if(key == 'A') {

            dis = 10;

        }
        else if(key == 'B') {

            dis = 11;

        }
        else if(key == 'C') {

            dis = 12;

        }
        else if(key == 'D') {

            dis = 13;

        }
        else if(key == 'E') {

            dis = 14;

        }
        else if(key == 'F') {

            dis = 15;
            
        }

    }

    wordtoled(dis);
    displayled(led, 50);

}

void wordtoled(int n) {

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < col; j++) {

            led[i][j] = word_array[n][i][j];

        }

    }

}

void clearled() {

    for (int i = 0; i < row; i++) {

        digitalWrite(rowpin[i], LOW);

    }

}

void displayled(boolean led[row][col], int continue_time) {

    for(int k = 0; k < continue_time; k++) {

        for(int i = 0; i < col; i++) {

            clearled();
            low_74138pin(i);

            for(int j = 0; j < row; j++) {

                if(led[j][i] == 1) {

                    digitalWrite(rowpin[j], HIGH);

                }

            }

        }

    }

}

void low_74138pin(int num) {

    switch(num) {

        case 0:

            digitalWrite(ls138A, LOW);
            digitalWrite(ls138B, LOW);
            digitalWrite(ls138C, LOW);
            break;

        case 1:

            digitalWrite(ls138A, HIGH);
            digitalWrite(ls138B, LOW);
            digitalWrite(ls138C, LOW);
            break;

        case 2:

            digitalWrite(ls138A, LOW);
            digitalWrite(ls138B, HIGH);
            digitalWrite(ls138C, LOW);
            break;

        case 3:

            digitalWrite(ls138A, HIGH);
            digitalWrite(ls138B, HIGH);
            digitalWrite(ls138C, LOW);
            break;

        case 4:

            digitalWrite(ls138A, LOW);
            digitalWrite(ls138B, LOW);
            digitalWrite(ls138C, HIGH);
            break;

        case 5:

            digitalWrite(ls138A, HIGH);
            digitalWrite(ls138B, LOW);
            digitalWrite(ls138C, HIGH);
            break;

        case 6:

            digitalWrite(ls138A, LOW);
            digitalWrite(ls138B, HIGH);
            digitalWrite(ls138C, HIGH);
            break;

        case 7:

            digitalWrite(ls138A, HIGH);
            digitalWrite(ls138B, HIGH);
            digitalWrite(ls138C, HIGH);
            break;

    }

}