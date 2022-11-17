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

boolean word_array[4][row][col] = {data_0, data_1, data_2, data_3};
boolean led[row][col];

byte rowpin[row] = {2, 3, 4, 5, 6, 7, 8, 9};

const int motorin1 = 2;
const int motorin2 = 3;

int dis = 0;
int num = 4, base1 = 33, speed = 0;

void setup()
{
    // put your setup code here, to run once:

    pinMode(ls138A, OUTPUT);
    pinMode(ls138B, OUTPUT);
    pinMode(ls138C, OUTPUT);

    pinMode(motorin1, OUTPUT);
    pinMode(motorin2, OUTPUT);

    for (int i = 0; i < 8; i++)
    {

        pinMode(rowpin[i], OUTPUT);

    }

    for(int i = base1; i < base1 + num; i++) {

        pinMode(i, INPUT_PULLUP);

    }

    clearled();
    pinMode(A14, OUTPUT);
    digitalWrite(A14, LOW);

}

void loop()
{
    // put your main code here, to run repeatedly:

    int k1st = digitalRead(33);
    int k2st = digitalRead(34);
    int k3st = digitalRead(35);
    int k4st = digitalRead(36);

    digitalWrite(motorin2, LOW);

    wordtoled(dis);
    displayled(led, 10);
    
    if(k1st == LOW) {

        speed = 0;
        dis = 0;

    }
    else if(k2st == LOW) {

        speed = 90;
        dis = 1;

    }
    else if(k3st == LOW) {

        speed = 170;
        dis = 2;

    }
    else if(k4st == LOW) {

        speed = 255;
        dis = 3;

    }

    analogWrite(motorin1, speed);
    delay(10);

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