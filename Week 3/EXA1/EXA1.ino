byte seven_seg_digits[10][7] = {

    {0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 1, 1},
    {0, 0, 1, 0, 0, 1, 0},
    {0, 0, 0, 0, 1, 1, 0},
    {1, 0, 0, 1, 1, 0, 0},
    {0, 1, 0, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0}

};

void setup() {
  // put your setup code here, to run once:

    for(int i = 2; i < 10; i++) {

        pinMode(i, OUTPUT);

    }

    writeDot(1);

    pinMode(A13, OUTPUT);

    digitalWrite(A13, LOW);
    
    pinMode(30, OUTPUT);
    pinMode(31, OUTPUT);
    pinMode(32, OUTPUT);

    digitalWrite(30, LOW);
    digitalWrite(31, LOW);
    digitalWrite(32, LOW);

}

void writeDot(byte dot) {

    digitalWrite(9, dot);

}

void SevenSegWrite(byte digit) {

    byte pin = 2;

    for(byte segCount = 0; segCount < 7; ++segCount) {

        digitalWrite(pin, seven_seg_digits[digit][segCount]);
        ++pin;

    }

}

void loop() {
  // put your main code here, to run repeatedly:

    for(int count = 0; count < 10; count++) {

        delay(1000);
        SevenSegWrite(count);

    }

}
