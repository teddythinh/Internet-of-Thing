// C++ code
//

int light_pin = A0;
int red_light = 7;
void setup()
{
    Serial.begin(9600);
    pinMode(light_pin, INPUT);
    pinMode(red_light, OUTPUT);
}

void loop()
{
    // if (analogRead(light_pin) < 500) mở đèn
    // else tắt đèn
    // digitalWrite(red_light, HIGH);
    if (analogRead(light_pin) < 500){
        digitalWrite(red_light, HIGH);
    }
    else{
        digitalWrite(red_light, LOW);
    }

    Serial.println(analogRead(light_pin));
    delay(100);
}