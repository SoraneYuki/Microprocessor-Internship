#define ls138A 30
#define ls138B 31
#define ls138C 32

#define row 8
#define col 8

#define data_A {0, 0, 1, 1, 1, 0, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 1, 1, 1, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0,\
                0, 1, 0, 0, 0, 1, 0, 0}

boolean word_array[4][row][col] = {data_A};
boolean led[row][col];

byte rowpin[row] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup()
{
    // put your setup code here, to run once:

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

void loop()
{
    // put your main code here, to run repeatedly:
    wordtoled(0);
    displayled(led, 1000);
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