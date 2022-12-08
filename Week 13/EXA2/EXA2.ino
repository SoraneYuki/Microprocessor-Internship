#include <IRremote.h>

int RECV_PIN = 11;
int RELAY_PIN = A4;

IRrecv irrecv(RECV_PIN);
decode_results results;

void dump(decode_results *results) {

    int count = results->rawlen;
    if (results->decode_type == UNKNOWN) {
        Serial.print("Unknown encoding: ");
    } else if (results->decode_type == NEC) {
        Serial.print("Decoded NEC: ");
    } else if (results->decode_type == SONY) {
        Serial.print("Decoded SONY: ");
    } else if (results->decode_type == RC5) {
        Serial.print("Decoded RC5: ");
    } else if (results->decode_type == RC6) {
        Serial.print("Decoded RC6: ");
    }
    // else if(results -> decode_type == PANASONIC) {

    //     Serial.print("Decoded PANASONIC - Address: ");
    //     Serial.print(results->panasonicAddress, HEX);
    //     Serial.print(" Value: ");

    // }
    Serial.println(results->value, HEX);
    Serial.print("(");
    Serial.print(results -> bits, DEC);
    Serial.print("bits)");
    Serial.print("Raw (");
    Serial.print(count, DEC);
    Serial.print("): ");
    for (int i = 0; i < count; i++) {
        if ((i % 2) == 1) {
            Serial.print(results->rawbuf[i]*USECPERTICK, DEC);
        } else {
            Serial.print(-results->rawbuf[i]*USECPERTICK, DEC);
        }
        Serial.print(" ");
    }
    Serial.println(" ");

}

void setup() {

    pinMode(RELAY_PIN, OUTPUT);
    pinMode(13, OUTPUT);
    Serial.begin(9600);
    irrecv.enableIRIn();

}

int on = 0;
unsigned long last = millis();

void loop() {

    if(irrecv.decode(&results)) {
        if(millis() - last > 1000) {
            on = !on;
            digitalWrite(RELAY_PIN, on ? HIGH : LOW);
            digitalWrite(13, on ? HIGH : LOW);
            dump(&results);
        }
        last = millis();
        irrecv.resume();
    }

}