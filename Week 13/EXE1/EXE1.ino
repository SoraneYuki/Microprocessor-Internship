#include <IRremote.h>

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

#define data_10 {0, 0, 0, 0, 0, 0, 0, 0,\
                0, 0, 0, 0, 0, 0, 0, 0,\
                0, 0, 0, 0, 0, 0, 0, 0,\
                0, 0, 0, 0, 0, 0, 0, 0,\
                0, 0, 0, 0, 0, 0, 0, 0,\
                0, 0, 0, 0, 0, 0, 0, 0,\
                0, 0, 0, 0, 0, 0, 0, 0,\
                0, 0, 0, 0, 0, 0, 0, 0}

boolean word_array[11][row][col] = {data_0, data_1, data_2, data_3, data_4, data_5, data_6, data_7, data_8, data_9, data_10};
boolean led[row][col];

byte rowpin[row] = {2, 3, 4, 5, 6, 7, 8, 9};

int dis = 10;

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {

    pinMode(ls138A, OUTPUT);
    pinMode(ls138B, OUTPUT);
    pinMode(ls138C, OUTPUT);

    for (int i = 0; i < 8; i++)
    {

        pinMode(rowpin[i], OUTPUT);
    }

    clearled();
    pinMode(A14, OUTPUT);
    digitalWrite(A14, LOW);

    Serial.begin(9600);
    irrecv.enableIRIn();

}

void loop() {

    // 417814695 0
    // 417794295 1
    // 417826935 2
    // 417810615 3
    // 417843255 4
    // 417802455 5
    // 417835095 6
    // 417818775 7
    // 417851415 8
    // 417798375 9

    if (irrecv.decode(&results)) {
        Serial.println(results.value);

        switch (results.value) {
            case 417814695:
                dis = 0;
                break;

            case 417794295:
                dis = 1;
                break;
            
            case 417826935:
                dis = 2;
                break;
            
            case 417810615:
                dis = 3;
                break;

            case 417843255:
                dis = 4;
                break;
            
            case 417802455:
                dis = 5;
                break;
            
            case 417835095:
                dis = 6;
                break;
            
            case 417818775:
                dis = 7;
                break;
            
            case 417851415:
                dis = 8;
                break;
            
            case 417798375:
                dis = 9;
                break;
        
        }

        irrecv.resume();
    }

    wordtoled(dis);
    displayled(led, 100);

}

void wordtoled(int n)
{

    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {

            led[i][j] = word_array[n][i][j];
        }
    }
}

void clearled()
{

    for (int i = 0; i < row; i++)
    {

        digitalWrite(rowpin[i], LOW);
    }
}

void displayled(boolean led[row][col], int continue_time)
{

    for (int k = 0; k < continue_time; k++)
    {

        for (int i = 0; i < col; i++)
        {

            clearled();
            low_74138pin(i);

            for (int j = 0; j < row; j++)
            {

                if (led[j][i] == 1)
                {

                    digitalWrite(rowpin[j], HIGH);
                }
            }
        }
    }
}

void low_74138pin(int num)
{

    switch (num)
    {

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