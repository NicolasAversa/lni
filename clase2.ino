const int PIN_TRIG = 9;
const int PIN_ECHO = 10;
const int PIN_LED = 13;

void setup()
{
    pinMode(PIN_TRIG, OUTPUT);
    pinMode(PIN_ECHO, INPUT);
    pinMode(PIN_LED, OUTPUT);
}

void loop()
{
    // 1. Lanzar el pulso de ultrasonido
    digitalWrite(PIN_TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(PIN_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(PIN_TRIG, LOW);

    // 2. Calcular distancia (0 a 255)
    long duracion = pulseIn(PIN_ECHO, HIGH);
    int distancia = constrains(duracion * 0.034 / 2, 0, 255);

    // 3. Mapear: Cerca (0) = Espera corta (0ms) -> Rápido
    //            Lejos (255) = Espera larga (5000ms) -> Lento
    long velocidad = map(distancia, 0, 255, 0, 5000);

    // 4. Parpadeo del LED
    digitalWrite(PIN_LED, HIGH);
    delay(velocidad);
    digitalWrite(PIN_LED, LOW);
    delay(velocidad); // Añadido para que se note el tiempo de apagado también
}