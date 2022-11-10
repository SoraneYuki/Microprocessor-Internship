int pin = A6;
int Value = 0;

void setup() {

    Serial.begin(9600);

}

void loop() {

    Value = analogRead(pin);
    Serial.print("Value: ");
    Serial.println(Value/4);
    delay(100);

}