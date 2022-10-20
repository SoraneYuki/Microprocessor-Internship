int joypinx = A1;
int joypiny = A2;
int joysw = A3;

int value = 0;
int xzero = 0;
int yzero = 0;
int swst = 0;

void setup() {

    Serial.begin(9600);

    pinMode(swst, INPUT_PULLUP);
    xzero = analogRead(joypinx);
    yzero = analogRead(joypiny);

}

void loop() {

    int x, y, value;

    value = analogRead(joypinx);
    x = value - xzero;

    value = analogRead(joypiny);
    y = value - yzero;

    swst = digitalRead(joysw);

    Serial.print("X= ");
    Serial.print(x);
    Serial.print(" Y= ");
    Serial.println(y);
    Serial.print("SW= ");
    Serial.println(swst);
    delay(20);

}