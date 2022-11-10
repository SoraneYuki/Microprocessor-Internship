int pin = A6;
int Value = 0;
int ledPin = 9;

void setup() {

    pinMode(ledPin, OUTPUT);
    pinMode(A15, OUTPUT);
    digitalWrite(A15, LOW);

}

void loop() {

    Value = analogRead(pin);
    analogWrite(ledPin, Value / 4);

}