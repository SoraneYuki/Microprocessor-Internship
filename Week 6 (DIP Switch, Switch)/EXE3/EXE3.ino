#define ls138A 30
#define ls138B 31
#define ls138C 32

#define row 8
#define col 8

#define greenman_0 {0, 1, 1, 0, 0, 0, 0, 0,\
                    0, 1, 1, 0, 0, 0, 0, 0,\
                    0, 0, 1, 1, 0, 0, 0, 0,\
                    0, 1, 1, 1, 1, 0, 0, 0,\
                    0, 0, 0, 1, 1, 0, 0, 0,\
                    0, 0, 1, 1, 0, 1, 0, 0,\
                    0, 0, 1, 0, 0, 0, 1, 0,\
                    0, 1, 1, 0, 0, 1, 1, 0}

#define greenman_1 {0, 1, 1, 0, 0, 0, 0, 0,\
                    0, 1, 1, 0, 0, 0, 0, 0,\
                    0, 0, 1, 1, 0, 0, 0, 0,\
                    0, 1, 1, 1, 1, 1, 0, 0,\
                    0, 1, 0, 1, 1, 0, 1, 0,\
                    0, 0, 1, 1, 0, 1, 0, 0,\
                    0, 1, 1, 0, 0, 0, 1, 0,\
                    0, 1, 0, 0, 0, 0, 1, 0}

#define greenman_2 {0, 1, 1, 0, 0, 0, 0, 0,\
                    0, 1, 1, 0, 0, 0, 0, 0,\
                    0, 0, 1, 1, 0, 0, 0, 0,\
                    0, 1, 1, 1, 1, 1, 0, 0,\
                    1, 0, 0, 1, 1, 0, 1, 0,\
                    0, 0, 0, 1, 1, 0, 0, 0,\
                    0, 1, 1, 0, 0, 1, 1, 0,\
                    0, 0, 0, 0, 0, 0, 1, 0}

#define greenman_3 {1, 1, 0, 0, 0, 0, 0, 0,\
                    1, 1, 0, 0, 0, 0, 0, 0,\
                    0, 1, 1, 1, 1, 0, 0, 0,\
                    0, 1, 1, 0, 0, 1, 0, 0,\
                    1, 0, 1, 1, 0, 0, 0, 0,\
                    0, 0, 1, 0, 1, 0, 0, 0,\
                    1, 1, 0, 0, 0, 1, 1, 0,\
                    0, 0, 0, 0, 0, 0, 1, 0}

#define greenman_4 {1, 1, 0, 0, 0, 0, 0, 0,\
                    1, 1, 0, 0, 0, 0, 0, 0,\
                    0, 1, 1, 0, 0, 0, 0, 0,\
                    0, 1, 1, 1, 1, 0, 0, 0,\
                    1, 0, 1, 1, 0, 1, 0, 0,\
                    0, 0, 1, 1, 1, 0, 1, 0,\
                    0, 0, 1, 0, 0, 1, 1, 0,\
                    1, 1, 1, 0, 0, 0, 1, 0}

#define greenman_5 {1, 1, 0, 0, 0, 0, 0, 0,\
                    1, 1, 0, 0, 0, 0, 0, 0,\
                    0, 1, 1, 0, 0, 0, 0, 0,\
                    0, 1, 1, 1, 1, 0, 0, 0,\
                    1, 0, 1, 1, 0, 1, 0, 0,\
                    0, 0, 1, 1, 0, 0, 1, 0,\
                    0, 1, 0, 0, 1, 1, 0, 0,\
                    1, 1, 0, 0, 0, 1, 0, 0}

#define greenman_6 {1, 1, 0, 0, 0, 0, 0, 0,\
                    1, 1, 0, 0, 0, 0, 0, 0,\
                    0, 1, 1, 0, 0, 0, 0, 0,\
                    0, 1, 1, 1, 1, 0, 0, 0,\
                    0, 1, 1, 1, 0, 1, 0, 0,\
                    0, 0, 1, 1, 0, 0, 0, 0,\
                    0, 1, 0, 1, 1, 0, 0, 0,\
                    0, 0, 1, 0, 1, 0, 0, 0}

#define greenman_7 {0, 1, 1, 0, 0, 0, 0, 0,\
                    0, 1, 1, 0, 0, 0, 0, 0,\
                    0, 0, 1, 1, 0, 0, 0, 0,\
                    0, 0, 1, 1, 1, 0, 0, 0,\
                    0, 0, 0, 1, 1, 0, 0, 0,\
                    0, 0, 0, 1, 0, 1, 0, 0,\
                    0, 0, 0, 1, 1, 1, 0, 0,\
                    0, 0, 0, 0, 0, 1, 0, 0}

#define greenman_stop {0, 0, 0, 1, 1, 0, 0, 0,\
                       0, 0, 0, 1, 1, 0, 0, 0,\
                       0, 0, 1, 1, 1, 1, 0, 0,\
                       0, 1, 0, 1, 1, 0, 1, 0,\
                       0, 1, 0, 1, 1, 0, 1, 0,\
                       0, 0, 1, 0, 0, 1, 0, 0,\
                       0, 0, 1, 0, 0, 1, 0, 0,\
                       0, 1, 1, 0, 0, 1, 1, 0}

boolean word_array[9][row][col] = {greenman_0, greenman_1, greenman_2, greenman_3, greenman_4, greenman_5, greenman_6, greenman_7, greenman_stop};
boolean led[row][col];

byte rowpin[row] = {2, 3, 4, 5, 6, 7, 8, 9};

int redpin = 44;
int grnpin = 45;
int blupin = 46;

int mod = 0;
int dis = 0;

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

    pinMode(33, INPUT_PULLUP);

    pinMode(redpin, OUTPUT);
    pinMode(grnpin, OUTPUT);
    pinMode(blupin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

    analogWrite(redpin, 255);
    analogWrite(grnpin, 255);
    analogWrite(blupin, 255);

    int st = digitalRead(33);

    if(st == LOW) {

        mod++;

        if(mod > 2) {

            mod = 0;

        }

        while(st == LOW) {

            st = digitalRead(33);
            delay(100);

        }

    }

    if(mod == 0) {

        analogWrite(redpin, 0);
        analogWrite(grnpin, 255);
        analogWrite(blupin, 255);

        wordtoled(8);
        displayled(led, 200);

    }
    else if(mod == 1) {

        analogWrite(redpin, 255);
        analogWrite(grnpin, 0);
        analogWrite(blupin, 255);

        wordtoled(dis);
        displayled(led, 200);
        dis++;
        if(dis > 7) {

            dis = 0;

        }

    }
    else if(mod == 2) {

        analogWrite(redpin, 0);
        analogWrite(grnpin, 0);
        analogWrite(blupin, 255);

        wordtoled(dis);
        displayled(led, 100);
        dis++;
        if(dis > 7) {

            dis = 0;

        }

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