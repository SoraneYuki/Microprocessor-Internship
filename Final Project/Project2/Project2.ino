#define ls138A 30
#define ls138B 31
#define ls138C 32

#define row 8
#define col 8

// 1 2 3 4  5   6   7   0
// 上下左右 路 起點 終點 牆

const int x = 3;
const int y = 5;

int map[5][3] = {

    {0, 0, 0},
    {0, 7, 0},
    {0, 5, 0},
    {0, 1, 0},
    {0, 0, 0}

}; 

const uint64_t IMAGES[] = {

    0x817e425a5a424242, // 0 終點
    0x8142240000000000, // 1 無盡路
    0x8142424242424242, // 2 岔路
    0x817e424242424242, // 3 死路
    0x81427c4040404040, // 4 右轉路
    0x81423e0202020202  // 5 左轉路

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

    for(int i = 0; i < y; i++)
    {

        for(int j = 0; j < x; j++)
        {

            if(map[i][j] == 1) {

                if(map[i - 1][j] == 0) {

                    dis = 3;

                }
                else if((map[i - 1][j] == 5) && (map[i - 1][j + 1] == 5) && (map[i - 1][j - 1] == 5)) {

                    dis = 2;                    

                }
                else if((map[i - 1][j] == 5) && (map[i - 1][j + 1] == 0) && (map[i - 1][j - 1] == 0)) {

                    dis = 1;                    

                }
                else if((map[i - 1][j] == 5) && (map[i - 1][j + 1] == 5) && (map[i - 1][j - 1] == 0)) {

                    dis = 4;                    

                }
                else if((map[i - 1][j] == 5) && (map[i - 1][j + 1] == 0) && (map[i - 1][j - 1] == 5)) {

                    dis = 5;                    

                }
                else if(map[i - 1][j] == 7) {

                    dis = 0;                    

                }

            }
        
        }

    }

    wordtoled(IMAGES[dis]);
    displayled(led, 200);

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