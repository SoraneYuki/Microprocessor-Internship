#define ls138A 30
#define ls138B 31
#define ls138C 32

#define row 8
#define col 8

// 1 2 3 4  5   6   7   0
// 上下左右 路 起點 終點 牆

const int map[5][3] = {

    {0, 0, 0},
    {0, 7, 0},
    {0, 5, 0},
    {0, 1, 0},
    {0, 0, 0}

}; 

const uint64_t IMAGES[] = {

    0x817e425a5a424242,
    0x8142240000000000,
    0x8142424242424242,
    0x817e424242424242,
    0x81427c4040404040,
    0x81423e0202020202

};

const int IMAGES_LEN = sizeof(IMAGES) / 8;

boolean led[row][col];
byte rowpin[row] = {2, 3, 4, 5, 6, 7, 8, 9};

int dis = 0;

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

}

void loop() {

    wordtoled(IMAGES[dis]);
    Serial.println(led[0][0]);
    displayled(led, 200);
    dis++;
    if(dis >= 8) {
      dis = 0;
    }

}

void wordtoled(uint64_t image)
{

    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {

            led[i][j] = (image >> i * 8) & 0xFF;
        
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