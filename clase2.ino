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

    // 2. Calcular distancia en centímetros (0 a 255 cm)
    int cms = pulseIn(ECHO, HIGH) * 0.034 / 2;

    // 3. Mapear: 0 a 255 cm -> 0 a 500 milisegundos (0 a 5 segundos)
    long velocidad = map(cms, 0, 255, 0, 500);

    // 4. Parpadeo del LED (Cerca = Delay corto = Parpadeo rápido)
    digitalWrite(LED, HIGH);
    delay(velocidad);
    digitalWrite(LED, LOW);
    delay(velocidad);
}