const int TRIG = 9, ECHO = 10, LED = 13;

void setup()
{
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(LED, OUTPUT);
}

void loop()
{
    // 1. Pulso rápido para activar el sensor
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    // 2. Medir distancia directamente en METROS
    float metros = (pulseIn(ECHO, HIGH) * 0.034 / 2) / 100.0;

    // 3. Mapear: 0 a 2 metros -> 0 a 4 segundos de delay (0 a 4000 ms)
    long velocidad = map(metros * 100, 0, 200, 0, 4000);

    // 4. Parpadeo del LED
    digitalWrite(LED, HIGH);
    delay(velocidad);
    digitalWrite(LED, LOW);
    delay(velocidad);
}