int vrpin = A0;
int vrvalue = 0;

int ledpin = 13;

void setup() {
  // put your setup code here, to run once:

    pinMode(ledpin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

    vrvalue = analogRead(vrpin);
    digitalWrite(ledpin, HIGH);
    delay(vrvalue);
    digitalWrite(ledpin, LOW);
    delay(vrvalue);

}
