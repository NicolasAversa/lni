// Definición de los pines para el sensor y el LED
const int PIN_TRIG = 9;
const int PIN_ECHO = 10;
const int PIN_LED = 13;

void setup()
{
    // Configuración de los pines
    pinMode(PIN_TRIG, OUTPUT);
    pinMode(PIN_ECHO, INPUT);
    pinMode(PIN_LED, OUTPUT);

    // Opcional: Iniciar el monitor serie para ver los valores en pantalla
    Serial.begin(9600);
}

void loop()
{
    // 1. Medir la distancia con el sensor de ultrasonido
    long duracion;
    int distancia;

    digitalWrite(PIN_TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(PIN_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(PIN_TRIG, LOW);

    duracion = pulseIn(PIN_ECHO, HIGH);

    // Calcular la distancia en centímetros
    distancia = duracion * 0.034 / 2;

    // Limitar el rango de la distancia entre 0 y 255
    distancia = constrain(distancia, 0, 255);

    // 2. Mapear la distancia al tiempo de espera (0 a 5000 milisegundos)
    long velocidad = map(distancia, 0, 255, 0, 5000);

    // Mostrar los datos en el monitor serie para comprobar que funciona
    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.print(" | Velocidad (ms): ");
    Serial.println(velocidad);

    // 3. Lógica del LED
    digitalWrite(PIN_LED, HIGH); // LED 13 HIGH
    delay(velocidad);            // await velocidad (espera los milisegundos de la variable)
    digitalWrite(PIN_LED, LOW);  // LED 13 LOW

    // Una pequeña pausa de 100ms antes de la siguiente lectura para dar estabilidad
    delay(100);
}