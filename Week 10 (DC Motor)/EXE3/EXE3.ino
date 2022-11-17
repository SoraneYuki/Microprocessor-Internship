#include <LiquidCrystal.h>

const int motorin1 = 2;
const int motorin2 = 3;

int joypinx = A1;
int joypiny = A2;

int value = 0;
int xzero = 0;
int yzero = 0;

int nowtime = 0;

LiquidCrystal lcd(49, 48, 47, 43, 42, 41);

void setup()
{
    // put your setup code here, to run once:

    xzero = analogRead(joypinx);
    yzero = analogRead(joypiny);

    pinMode(motorin1, OUTPUT);
    pinMode(motorin2, OUTPUT);

    lcd.begin(16, 2);
    lcd.clear();

}

void loop()
{
    // put your main code here, to run repeatedly:

    int x, y, value;

    value = analogRead(joypinx);
    x = value - xzero;

    value = analogRead(joypiny);
    y = value - yzero;

    if(y > 300)
    {

        digitalWrite(motorin1, HIGH);
        digitalWrite(motorin2, LOW);
        nowtime++;

    }
    else if(y < -300)
    {

        digitalWrite(motorin1, LOW);
        digitalWrite(motorin2, HIGH);
        nowtime++;

    }
    else
    {

        digitalWrite(motorin1, LOW);
        digitalWrite(motorin2, LOW);
        nowtime = 0;

    }

    lcd.setCursor(0, 0);
    lcd.print("Time:           ");
    lcd.setCursor(6, 0);
    lcd.print(nowtime / 10);
    delay(100);
    
}