// C++ code
//

int trigger_pin = 2;
int echo_pin = 3;
int buzzer_pin = 4;

int blue_light = 8;
int red_light = 9;
int orange_light = 10;

long getDistance() {
    digitalWrite(trigger_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger_pin, LOW);

    long duration = pulseIn(echo_pin, HIGH);

    long distanceCm = duration * 0.034 / 2;

    return distanceCm;
}

void setup() {

    pinMode(trigger_pin, OUTPUT);
    pinMode(echo_pin, INPUT);

    pinMode(buzzer_pin, OUTPUT);

    pinMode(blue_light, OUTPUT);
    pinMode(red_light, OUTPUT);
    pinMode(orange_light, OUTPUT);

    Serial.begin(9600);

}

void loop() {
    long distanceCm = getDistance();
    Serial.println(distanceCm);

    // Khoảng cách an toàn (đèn xanh sáng, còn lại tắt)
    if (distanceCm >= 150) {
        digitalWrite(blue_light, HIGH);
        digitalWrite(red_light, LOW);
        digitalWrite(orange_light, LOW);
    }
    // Khoảng cách cảnh báo nguy hiểm (đèn đỏ sáng nhấp nháy, còi kêu liên tục)
    else if (distanceCm > 50 && distanceCm < 150) {
        distanceCm = getDistance();
        digitalWrite(blue_light, LOW);
        digitalWrite(orange_light, LOW);

        digitalWrite(red_light, HIGH);
        delay(50);
        digitalWrite(red_light, LOW);
        delay(50);

        tone(4, 4000);
        delay(500);
        noTone(buzzer_pin);
    }
    // Khoảng cách nguy hiểm (cả ba đèn nhấp nháy, càng gần thì càng nhanh)
    else if (distanceCm <= 50) {
        distanceCm = getDistance();
        digitalWrite(blue_light, HIGH);
        delay(50 + distanceCm);
        digitalWrite(blue_light, LOW);
        delay(50 + distanceCm);
        digitalWrite(red_light, HIGH);
        delay(50 + distanceCm);
        digitalWrite(red_light, LOW);
        delay(50 + distanceCm);
        digitalWrite(orange_light, HIGH);
        delay(50 + distanceCm);
        digitalWrite(orange_light, LOW);
        delay(50 + distanceCm);

        tone(4, 4000);
        delay(100 + distanceCm);
        noTone(buzzer_pin);
    }

}