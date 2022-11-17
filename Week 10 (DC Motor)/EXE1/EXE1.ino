const int motorin1 = 2;
const int motorin2 = 3;
const int DELAY = 100;

int VR_pin = A0;
int VR_value = 0;

void setup() {
    
    pinMode(motorin1, OUTPUT);
    pinMode(motorin2, OUTPUT);
    pinMode(VR_pin, INPUT);

}

void loop() {

    VR_value = analogRead(VR_pin) / 4;

    digitalWrite(motorin2, LOW);
 
    analogWrite(motorin1, VR_value);
    delay(DELAY);

}