#include <LiquidCrystal.h>
#include <Keypad.h>

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

void setup() {

    lcd.begin(16, 2);
    lcd.print("KEY IN:  ");

}

void loop() {

    lcd.setCursor(7, 0);
    char customkey = keypad.getKey();
    if(customkey) {
        lcd.print(customkey);
    }

}