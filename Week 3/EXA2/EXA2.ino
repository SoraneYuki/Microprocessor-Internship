#define CA1 30
#define CA2 31
#define CA3 32

int delay_time = 4;

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

    digitalWrite(9, HIGH);

    pinMode(CA1, OUTPUT);
    pinMode(CA2, OUTPUT);
    pinMode(CA3, OUTPUT);
    pinMode(A13, OUTPUT);

    digitalWrite(A13, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

    for(unsigned int number = 0; number < 10000; number++) {

        unsigned long startTime = millis();

        for(unsigned long elapsed = 0; elapsed < 300; elapsed = millis() - startTime) {

            pickDigit(1);
            pickNumber(number % 10);
            delay(delay_time);
            
            pickDigit(2);
            pickNumber((number / 10) % 10);
            delay(delay_time);

            pickDigit(3);
            pickNumber((number/ 100) % 10);
            delay(delay_time);

            pickDigit(4);
            pickNumber((number / 1000) % 10);
            delay(delay_time);

        }

    }

}

void SevenSegWrite(byte digit) {

    byte pin = 2;

    for(byte segCount = 0; segCount < 7; ++segCount) {

        digitalWrite(pin, seven_seg_digits[digit][segCount]);
        ++pin;

    }

}

void pickDigit(int x) {

    digitalWrite(CA1, HIGH);
    digitalWrite(CA2, HIGH);
    digitalWrite(CA3, HIGH);

    switch(x) {

        case 1:

            digitalWrite(CA1, LOW);
            digitalWrite(CA2, LOW);
            digitalWrite(CA3, LOW);
            break;

        case 2:

            digitalWrite(CA1, HIGH);
            digitalWrite(CA2, LOW);
            digitalWrite(CA3, LOW);
            break;

        case 3:

            digitalWrite(CA1, LOW);
            digitalWrite(CA2, HIGH);
            digitalWrite(CA3, LOW);
            break;

        case 4:

            digitalWrite(CA1, HIGH);
            digitalWrite(CA2, HIGH);
            digitalWrite(CA3, LOW);
            break;

    }

}

void pickNumber(int x) {

    SevenSegWrite(x);

}