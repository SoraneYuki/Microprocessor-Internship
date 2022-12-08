#include <IRremote.h>

#define CA1 30
#define CA2 31
#define CA3 32

byte segs[7] = {2, 3, 4, 5, 6, 7, 8};

int delay_time = 4;

byte seven_seg_digits[11][7] = {

    {0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 1, 1},
    {0, 0, 1, 0, 0, 1, 0},
    {0, 0, 0, 0, 1, 1, 0},
    {1, 0, 0, 1, 1, 0, 0},
    {0, 1, 0, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 1}

};

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

int nownum = 4, num1 = 10, num2 = 10, num3 = 10, num4 = 10, outnum = 0;

void setup() {

    for(int i = 2; i < 10; i++) {

        pinMode(i, OUTPUT);

    }

    digitalWrite(9, HIGH);

    pinMode(CA1, OUTPUT);
    pinMode(CA2, OUTPUT);
    pinMode(CA3, OUTPUT);
    pinMode(A13, OUTPUT);

    digitalWrite(A13, LOW);

    Serial.begin(9600);
    irrecv.enableIRIn();

}

void loop() {

    if (irrecv.decode(&results)) {
        //Serial.println(results.value, HEX);

        switch (results.value) {

            case 417814695:
                outnum = 0;
                break;

            case 417794295:
                outnum = 1;
                break;

            case 417826935:
                outnum = 2;
                break;

            case 417810615:
                outnum = 3;
                break;

            case 417843255:
                outnum = 4;
                break;

            case 417802455:
                outnum = 5;
                break;

            case 417835095:
                outnum = 6;
                break;

            case 417818775:
                outnum = 7;
                break;

            case 417851415:
                outnum = 8;
                break;

            case 417798375:
                outnum = 9;
                break;

            default :
                outnum = 10;
                break;
        
        }

        if(outnum != 10) {

            num4 = num3;
            num3 = num2;
            num2 = num1;
            num1 = outnum;
            outnum = 10;

        }

        irrecv.resume();
    }

    lightDigit1(num1);
    delay(delay_time);
    lightDigit2(num2);
    delay(delay_time);
    lightDigit3(num3);
    delay(delay_time);
    lightDigit4(num4);
    delay(delay_time);

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

void lightDigit1(byte number) {

    pickDigit(1);
    lightSegments(number);

}

void lightDigit2(byte number) {

    pickDigit(2);
    lightSegments(number);

}

void lightDigit3(byte number) {

    pickDigit(3);
    lightSegments(number);

}

void lightDigit4(byte number) {

    pickDigit(4);
    lightSegments(number);

}

void lightSegments(byte number) {

    for(int i = 0; i < 7; i++){

        digitalWrite(segs[i], seven_seg_digits[number][i]);

    }

}