#include <IRremote.h>
#include <LiquidCrystal.h>

#define ls138A 30
#define ls138B 31
#define ls138C 32

#define row 8
#define col 8

#define data_O {0, 0, 1, 1, 1, 1, 0, 0,\
                0, 1, 0, 0, 0, 0, 1, 0,\
                1, 0, 0, 0, 0, 0, 0, 1,\
                1, 0, 0, 0, 0, 0, 0, 1,\
                1, 0, 0, 0, 0, 0, 0, 1,\
                1, 0, 0, 0, 0, 0, 0, 1,\
                0, 1, 0, 0, 0, 0, 1, 0,\
                0, 0, 1, 1, 1, 1, 0, 0}

#define data_X {1, 0, 0, 0, 0, 0, 0, 1,\
                0, 1, 0, 0, 0, 0, 1, 0,\
                0, 0, 1, 0, 0, 1, 0, 0,\
                0, 0, 0, 1, 1, 0, 0, 0,\
                0, 0, 0, 1, 1, 0, 0, 0,\
                0, 0, 1, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 0, 1, 0,\
                1, 0, 0, 0, 0, 0, 0, 1}

#define data_N {0, 0, 0, 0, 0, 0, 0, 0,\
                0, 0, 0, 0, 0, 0, 0, 0,\
                0, 0, 0, 0, 0, 0, 0, 0,\
                0, 0, 0, 0, 0, 0, 0, 0,\
                0, 0, 0, 0, 0, 0, 0, 0,\
                0, 0, 0, 0, 0, 0, 0, 0,\
                0, 0, 0, 0, 0, 0, 0, 0,\
                0, 0, 0, 0, 0, 0, 0, 0}

boolean word_array[11][row][col] = {data_O, data_X, data_N};
boolean led[row][col];

byte rowpin[row] = {2, 3, 4, 5, 6, 7, 8, 9};

int num = 0, nownum = 0;

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

LiquidCrystal lcd(49, 48, 47, 43, 42, 41);

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

    lcd.begin(16, 2);

    Serial.begin(9600);
    irrecv.enableIRIn();

    lcd.clear();

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

    lcd.setCursor(0, 0);
    lcd.print("Password:     ");

    if (irrecv.decode(&results)) {
        Serial.println(results.value);

        switch (results.value) {

            case 417814695:
                num = num * 10 + 0;
                nownum++;
                break;

            case 417794295:
                num = num * 10 + 1;
                nownum++;
                break;

            case 417826935:
                num = num * 10 + 2;
                nownum++;
                break;

            case 417810615:
                num = num * 10 + 3;
                nownum++;
                break;

            case 417843255:
                num = num * 10 + 4;
                nownum++;
                break;

            case 417802455:
                num = num * 10 + 5;
                nownum++;
                break;

            case 417835095:
                num = num * 10 + 6;
                nownum++;
                break;

            case 417818775:
                num = num * 10 + 7;
                nownum++;
                break;

            case 417851415:
                num = num * 10 + 8;
                nownum++;
                break;

            case 417798375:
                num = num * 10 + 9;
                nownum++;
                break;
        
        }

        irrecv.resume();
    }

    if(num != 0) {

        lcd.setCursor(10, 0);
        lcd.print(num);

    }

    if(num == 1234) {

        wordtoled(0);
        displayled(led, 2000);

        num = 0;
        nownum = 0;

        wordtoled(2);

    }
    else if(nownum >= 4) {

        wordtoled(1);
        displayled(led, 2000);

        num = 0;
        nownum = 0;

        wordtoled(2);

    }
    else {

        wordtoled(2);
        displayled(led, 100);

    }

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