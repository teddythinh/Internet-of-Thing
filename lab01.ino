// C++ code
//
int button = 8;
int red_light = 7;
int blue_light = 6;
int white_light = 5;
int green_light = 4;
int orange_light = 3;
int yellow_light = 2;

long time = 0;

void setup() {
    pinMode(red_light, OUTPUT);
    pinMode(blue_light, OUTPUT);
    pinMode(white_light, OUTPUT);
    pinMode(green_light, OUTPUT);
    pinMode(orange_light, OUTPUT);
    pinMode(yellow_light, OUTPUT);
    pinMode(button, INPUT);
    Serial.begin(9600);
}

void loop() {
    if (digitalRead(button) == HIGH) {
        time = millis();
        while (digitalRead(button) == HIGH) {
            if (millis() - time > 12000) {
                digitalWrite(red_light, HIGH);
                digitalWrite(blue_light, HIGH);
                digitalWrite(white_light, HIGH);
                digitalWrite(green_light, HIGH);
                digitalWrite(orange_light, HIGH);
                digitalWrite(yellow_light, HIGH);
            } else {
                if (digitalRead(button) == 0) break;
                digitalWrite(red_light, HIGH);
                delay(1000); 
                digitalWrite(red_light, LOW);
                if (digitalRead(button) == 0) break;
                delay(1000); 
                digitalWrite(blue_light, HIGH);
                delay(1000); 
                digitalWrite(blue_light, LOW);
                if (digitalRead(button) == 0) break;
                delay(1000); 
                digitalWrite(white_light, HIGH);
                delay(1000); 
                digitalWrite(white_light, LOW);
                if (digitalRead(button) == 0) break;
                delay(1000);
                digitalWrite(green_light, HIGH);
                delay(1000); 
                digitalWrite(green_light, LOW);
                if (digitalRead(button) == 0) break;
                delay(1000); 
                digitalWrite(orange_light, HIGH);
                delay(1000); 
                digitalWrite(orange_light, LOW);
                if (digitalRead(button) == 0) break;
                delay(1000); 
                digitalWrite(yellow_light, HIGH);
                delay(1000);
                digitalWrite(yellow_light, LOW);
                delay(1000);
            }
        }
        digitalWrite(red_light, LOW);
        digitalWrite(blue_light, LOW);
        digitalWrite(white_light, LOW);
        digitalWrite(green_light, LOW);
        digitalWrite(orange_light, LOW);
        digitalWrite(yellow_light, LOW);
    }
}