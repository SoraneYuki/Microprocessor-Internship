const int LED[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int LEDOpen = A15;

int BUZZER = A9;

int vrpin = A0;
int vrvalue = 0;

int RY5V = A4;

void setup() {
  // put your setup code here, to run once:

    for(int i = 0; i < 8; i++)
    {

        pinMode(LED[i], OUTPUT);
        digitalWrite(LED[i], HIGH);

    }

    pinMode(LEDOpen, OUTPUT);
    digitalWrite(LEDOpen, LOW);

    pinMode(RY5V, OUTPUT);
    digitalWrite(RY5V, LOW);

    pinMode(BUZZER, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

    vrvalue = analogRead(vrpin);

    for(int i = 0; i < 8; i++)
    {

        digitalWrite(LED[i], LOW);

    }
    delay(vrvalue);

    for(int i = 0; i < 8; i++)
    {

        digitalWrite(LED[i], HIGH);

    }
    delay(vrvalue);

    if(vrvalue > 1000) {

        digitalWrite(RY5V, HIGH);
        digitalWrite(BUZZER, HIGH);

    }
    else {

        digitalWrite(RY5V, LOW);
        digitalWrite(BUZZER, LOW);

    }

}
