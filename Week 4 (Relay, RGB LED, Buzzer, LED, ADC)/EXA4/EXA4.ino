int redpin = 44;
int grnpin = 45;
int blupin = 46;
int speed = 10;

void setup() {
  // put your setup code here, to run once:

    pinMode(redpin, OUTPUT);
    pinMode(grnpin, OUTPUT);
    pinMode(blupin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

    analogWrite(redpin, 255);
    analogWrite(grnpin, 255);
    analogWrite(blupin, 255);

    for(int i = 0; i < 255; i++) {

        analogWrite(redpin, i);
        delay(speed);

    }

    delay(100);

    for(int i = 0; i < 255; i++) {

        analogWrite(grnpin, i);
        delay(speed);

    }

    delay(100);

    for(int i = 0; i < 255; i++) {

        analogWrite(blupin, i);
        delay(speed);

    }

    delay(100);

}
