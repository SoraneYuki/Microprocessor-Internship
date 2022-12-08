#define a 2
#define b 3
#define a_bar 4
#define b_bar 5 
#define tt 20

unsigned run1_f[4] = {a, b, a_bar, b_bar};

void stop() {

    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(a_bar, LOW);
    digitalWrite(b_bar, LOW);

}

void setup() {

    for(int i = 2; i < 6; i++) {
    
        pinMode(i, OUTPUT);
    
    }

}

void loop() {

    for(int i = 0; i < 4; i++) {
    
        stop();
        digitalWrite(run1_f[i], HIGH);
        delay(tt);
    
    }

}