int redpin = 44;
int grnpin = 45;
int blupin = 46;
int speed = 500;
int r_value = 0;
int g_value = 0;
int b_value = 0;

void setup() {
  // put your setup code here, to run once:

    pinMode(redpin, OUTPUT);
    pinMode(grnpin, OUTPUT);
    pinMode(blupin, OUTPUT);

    analogWrite(redpin, 255);
    analogWrite(grnpin, 255);
    analogWrite(blupin, 255);

}

void loop() {
  // put your main code here, to run repeatedly:

    r_value = random(0, 255);
    g_value = random(0, 255);
    b_value = random(0, 255);

    analogWrite(redpin, r_value);
    analogWrite(grnpin, g_value);
    analogWrite(blupin, b_value);

    delay(speed);

}
