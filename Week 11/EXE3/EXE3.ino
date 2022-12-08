#define a 2
#define b 3
#define a_bar 4
#define b_bar 5 

#include <Stepper.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(49, 48, 47, 43, 42, 41);

Stepper stepper(200, a, a_bar, b, b_bar);

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {{'F','E','D','C'},
                         {'B','3','6','9'},
                         {'A','2','5','8'},
                         {'0','1','4','7'}};

byte rowPins[ROWS] = {25, 24, 23, 22};
byte colPins[COLS] = {29, 28, 27, 26};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int mod = 0, rmod = 0, R = 0, nowr = 0;

void setup() {

    stepper.setSpeed(200);

    lcd.begin(16, 2);
    lcd.clear();

}

void loop() {

    lcd.setCursor(0, 0);
    lcd.print("F=A? R=B?");
    lcd.setCursor(0, 1);

    char key = keypad.getKey();

    if (key != NO_KEY) {

        if(key == '0') {

        }
        else if(key == '1') {

        }
        else if(key == '2') {

        }
        else if(key == '3') {

        }
        else if(key == '4') {

        }
        else if(key == '5') {

        }
        else if(key == '6') {

        }
        else if(key == '7') {

        }
        else if(key == '8') {

        }
        else if(key == '9') {

        }
        else if(key == 'A') {

            lcd.print("A");
            delay(1000);
            lcd.clear();
            rmod = 1;
            mod = 1;

        }
        else if(key == 'B') {

            lcd.print("B");
            delay(1000);
            lcd.clear();
            rmod = 2;
            mod = 1;

        }

    }

    while(mod == 1) {

        lcd.setCursor(0, 0);
        lcd.print("R?");
        lcd.setCursor(0, 1);

        char key = keypad.getKey();

        if (key != NO_KEY) {

            if(key == '0') {

                R = (R * 10) + 0;

            }
            else if(key == '1') {

                R = (R * 10) + 1;

            }
            else if(key == '2') {

                R = (R * 10) + 2;

            }
            else if(key == '3') {

                R = (R * 10) + 3;

            }
            else if(key == '4') {

                R = (R * 10) + 4;

            }
            else if(key == '5') {

                R = (R * 10) + 5;

            }
            else if(key == '6') {

                R = (R * 10) + 6;

            }
            else if(key == '7') {

                R = (R * 10) + 7;

            }
            else if(key == '8') {

                R = (R * 10) + 8;

            }
            else if(key == '9') {

                R = (R * 10) + 9;

            }
            else if(key == 'A') {

                lcd.clear();
                mod = 2;

            }
            else if(key == 'C') {

                lcd.clear();
                R = 0;

            }

        }

        lcd.print(R);

    }

    while(mod == 2) {

        lcd.clear();

        lcd.setCursor(0, 0);
        lcd.print("R=    ");
        lcd.setCursor(2, 0);
        lcd.print(R - nowr);

        if(rmod == 1) {

            stepper.step(-1000 * R);
            nowr++;

        }
        else if(rmod == 2) {

            stepper.step(1000 * R);
            nowr++;

        }

        if(nowr == R) {

            mod = 0;
            nowr = 0;
            R = 0;

        }

    }

}