#include <LiquidCrystal.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {{'F', 'E', 'D', 'C'},
                         {'B', '3', '6', '9'},
                         {'A', '2', '5', '8'},
                         {'0', '1', '4', '7'}};

byte rowPins[ROWS] = {25, 24, 23, 22};
byte colPins[COLS] = {29, 28, 27, 26};

LiquidCrystal lcd(49, 48, 47, 43, 42, 41);
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int temp = 0;
int numa = 0;
int numb = 0;
int nummod = 0;
int mod = 0;
int ans = 0;
int havechar = 0;

void setup()
{

    lcd.begin(16, 2);
    Serial.begin(9600);
}

void loop()
{

    char key = keypad.getKey();

    if (key != NO_KEY)
    {

        if (key == '1')
        {

            temp = 1;
            havechar = 1;
        }
        else if (key == '2')
        {

            temp = 2;
            havechar = 1;
        }
        else if (key == '3')
        {

            temp = 3;
            havechar = 1;
        }
        else if (key == '4')
        {

            temp = 4;
            havechar = 1;
        }
        else if (key == '5')
        {

            temp = 5;
            havechar = 1;
        }
        else if (key == '6')
        {

            temp = 6;
            havechar = 1;
        }
        else if (key == '7')
        {

            temp = 7;
            havechar = 1;
        }
        else if (key == '8')
        {

            temp = 8;
            havechar = 1;
        }
        else if (key == '9')
        {

            temp = 9;
            havechar = 1;
        }
        else if (key == '0')
        {

            temp = 0;
            havechar = 1;
        }

        if (key == 'A')
        {

            mod = 1;

            if (nummod == 0)
            {

                nummod = 1;
            }
            else
            {

                nummod = 0;
            }
            lcd.setCursor(0, 0);
            lcd.print("                ");
        }
        else if (key == 'B')
        {

            mod = 2;

            if (nummod == 0)
            {

                nummod = 1;
            }
            else
            {

                nummod = 0;
            }
            lcd.setCursor(0, 0);
            lcd.print("                ");
        }
        else if (key == 'C')
        {

            mod = 3;

            if (nummod == 0)
            {

                nummod = 1;
            }
            else
            {

                nummod = 0;
            }
            lcd.setCursor(0, 0);
            lcd.print("                ");
        }
        else if (key == 'D')
        {

            mod = 4;

            if (nummod == 0)
            {

                nummod = 1;
            }
            else
            {

                nummod = 0;
            }

            lcd.setCursor(0, 0);
            lcd.print("                ");

        }
        else if (key == 'F')
        {

            if (mod == 1)
            {

                ans = numa + numb;
            }
            else if (mod == 2)
            {

                ans = numa - numb;
            }
            else if (mod == 3)
            {

                ans = numa * numb;
            }
            else if (mod == 4)
            {

                ans = numa / numb;
            }

            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(ans);
            delay(3000);
            lcd.clear();

            mod = 0;
            numa = 0;
            numb = 0;
            nummod = 0;
            havechar = 0;
            temp = 0;
        }
    }

    if (havechar == 1)
    {

        if (nummod == 0)
        {

            numa = (numa * 10) + temp;
            temp = 0;
        }
        else if (nummod == 1)
        {

            numb = (numb * 10) + temp;\
            temp = 0;
        }
        havechar = 0;
    }

    if (nummod == 0)
    {

        lcd.setCursor(0, 0);
        lcd.print(numa);
        
    }
    else if (nummod == 1)
    {

        lcd.setCursor(0, 0);
        lcd.print(numb);
    }

    if (mod == 1)
    {

        lcd.setCursor(0, 1);
        lcd.print("+");
    }
    else if (mod == 2)
    {

        lcd.setCursor(0, 1);
        lcd.print("-");
    }
    else if (mod == 3)
    {

        lcd.setCursor(0, 1);
        lcd.print("*");
    }
    else if (mod == 4)
    {

        lcd.setCursor(0, 1);
        lcd.print("/");
    }
}