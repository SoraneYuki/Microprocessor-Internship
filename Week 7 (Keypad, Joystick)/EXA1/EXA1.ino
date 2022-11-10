#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {{'F','E','D','C'},
                         {'B','3','6','9'},
                         {'A','2','5','8'},
                         {'0','1','4','7'}};

byte rowPins[ROWS] = {25, 24, 23, 22};
byte colPins[COLS] = {29, 28, 27, 26};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {

    Serial.begin(9600);

}

void loop() {

    char key = keypad.getKey();

    if (key) {

        Serial.println(key);

    }

}