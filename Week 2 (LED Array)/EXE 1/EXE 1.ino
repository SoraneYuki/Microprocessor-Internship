const int LED[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int LEDOpen = A15;

void setup() {
  // put your setup code here, to run once:

    for(int i = 0; i < 8; i++)
    {

        pinMode(LED[i], OUTPUT);
        digitalWrite(LED[i], HIGH);

    }

    pinMode(LEDOpen, OUTPUT);
    digitalWrite(LEDOpen, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

    for(int i = 0; i < 7; i++)
    {

        digitalWrite(LED[i], LOW);
        delay(100);
        digitalWrite(LED[i], HIGH);

    }

    for(int i = 7; i >= 1; i--)
    {

        digitalWrite(LED[i], LOW);
        delay(100);
        digitalWrite(LED[i], HIGH);

    }

}
