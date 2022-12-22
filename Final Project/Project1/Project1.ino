#include <LiquidCrystal.h>
#include <Stepper.h>
#include <DHT.h>
#include <IRremote.h>

#define a 2
#define b 3
#define a_bar 4
#define b_bar 5

LiquidCrystal lcd(49, 48, 47, 43, 42, 41);
Stepper stepper(200, a, a_bar, b, b_bar);
DHT dht(20, DHT11);

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

int RY5V = A4;

boolean relayopen = false;
boolean relaystate = false;
boolean relayneedopen = false;
boolean relayautoopen = false;

boolean stepperopen = false;
boolean steppermove = false;
boolean stepperneedopen = false;
boolean stepperautoopen = false;

void setup() {

    lcd.begin(16, 2);
    lcd.clear();

    stepper.setSpeed(150);

    dht.begin();

    pinMode(RY5V, OUTPUT);
    digitalWrite(RY5V, LOW);

    irrecv.enableIRIn();

    Serial.begin(9600);

}

void loop() {

    float h = dht.readHumidity();
    float t = dht.readTemperature();

    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    lcd.print(int(h));
    lcd.print("%");

    lcd.setCursor(0, 0);
    lcd.print("Temperature: ");
    lcd.print(int(t));
    lcd.print("C");

    if(int(h) >= 65 ) {

        stepperneedopen = true;

    }
    else {

        stepperneedopen = false;

    }

    if(int(t) >= 28) {

        relayneedopen = true;

    }
    else {

        relayneedopen = false;

    }

    if(irrecv.decode(&results)) {

        Serial.println(results.value);

        switch(results.value) {

            case 417794295:
                stepperopen = !stepperopen;
                steppermove = true;
                break;

            case 417826935:
                relayopen = !relayopen;
                relaystate = true;
                break;

        }

        irrecv.resume();

    }

    

    if(stepperopen == true && steppermove) {

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Curtain Open");
        lcd.setCursor(0, 1);
        lcd.print("     (OwO)");
        stepper.step(1025);
        steppermove = false;

    }
    else if(stepperopen == false && steppermove) {

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Curtain Close");
        lcd.setCursor(0, 1);
        lcd.print("     (UwU)");
        stepper.step(-1025);
        steppermove = false;
        stepperautoopen = false;

    }
    else if(stepperneedopen == true && stepperautoopen == false) {

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Curtain Open");
        lcd.setCursor(0, 1);
        lcd.print("(Audo Open)");
        stepper.step(1025);
        stepperopen = true;
        stepperautoopen = true;

    }

    if(relayopen == true && relaystate) {

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Fan Open");
        
        digitalWrite(RY5V, HIGH);

        relaystate = false;

        delay(500);

    }
    else if(relayopen == false && relaystate){

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Fan Close");

        digitalWrite(RY5V, LOW);

        relaystate = false;
        relayautoopen = false;

        delay(500);

    }
    else if(relayneedopen == true && relayautoopen == false) {

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Fan Open");
        lcd.setCursor(0, 1);
        lcd.print("(Audo Open)");

        digitalWrite(RY5V, HIGH);

        relayopen = true;
        relayautoopen = true;

        delay(500);

    }
    
    delay(500);

}