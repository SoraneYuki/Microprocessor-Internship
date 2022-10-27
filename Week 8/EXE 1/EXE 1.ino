#include <LiquidCrystal.h>
#include <Keypad.h>

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

boolean word_array[3][row][col] = {data_O, data_X, data_N};
boolean led[row][col];

byte rowpin[row] = {2, 3, 4, 5, 6, 7, 8, 9};

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {{'F','E','D','C'},
                         {'B','3','6','9'},
                         {'A','2','5','8'},
                         {'0','1','4','7'}};

byte rowPins[ROWS] = {25, 24, 23, 22};
byte colPins[COLS] = {29, 28, 27, 26};

LiquidCrystal lcd(49, 48, 47, 43, 42, 41);
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int cursor = 0;
int q = 0;
int pw = 0;

void setup() {

    lcd.begin(16, 2);
    lcd.clear();

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

}

void loop() {

    wordtoled(2);
    displayled(led, 1);

    while(q == 0)
    {
        
        lcd.setCursor(0, 0);
        lcd.print("Password:       "); //103

        char customkey = keypad.getKey();

        lcd.setCursor(cursor, 1);

        if(customkey) {

            lcd.print(customkey);
            cursor++;

            pw = pw + customkey;

            if(pw == 103) {

                q = 1;
                pw = 0;
                cursor = 0;

                wordtoled(0);
                displayled(led, 2000);

                lcd.setCursor(0, 1);
                lcd.print("                ");

                wordtoled(2);
                displayled(led, 1);

            }
            else if(cursor == 2) {

                cursor = 0;
                pw = 0;

                wordtoled(1);
                displayled(led, 2000);

                lcd.setCursor(0, 1);
                lcd.print("                ");

                wordtoled(2);
                displayled(led, 1);

            }

        }
    
    }

    lcd.clear();
    delay(1000);

    while (q == 1)
    {

        lcd.setCursor(0, 0);
        lcd.print("Student ID:     ");

        char customkey = keypad.getKey();

        lcd.setCursor(cursor, 1);

        if(customkey) {

            lcd.print(customkey);
            cursor++;

            pw = pw + customkey;

            if(pw == 505) {

                q = 0;
                pw = 0;
                cursor = 0;

                wordtoled(0);
                displayled(led, 2000);

                lcd.setCursor(0, 1);
                lcd.print("                ");

                wordtoled(2);
                displayled(led, 1);

            }
            else if(cursor == 9) {

                cursor = 0;
                pw = 0;

                wordtoled(1);
                displayled(led, 2000);

                lcd.setCursor(0, 1);
                lcd.print("                ");

                wordtoled(2);
                displayled(led, 1);

            }

        }

    }

    lcd.clear();
    delay(1000);

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