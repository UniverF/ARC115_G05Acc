// Definicion de pines
#define trigPin 11  // Pin conectado al TRIG del sensor ultrasonico
#define echoPin 10  // Pin conectado al ECHO del sensor ultrasonico
#define motor 7     // Pin conectado al motor
#define buzzer 4    // Pin conectado al buzzer (zumbador)

// Funcion de configuracion inicial
void setup() { 
  pinMode(trigPin, OUTPUT);   // Configura el pin del TRIG como salida
  pinMode(echoPin, INPUT);    // Configura el pin del ECHO como entrada
  pinMode(motor, OUTPUT);     // Configura el pin del motor como salida
  pinMode(buzzer, OUTPUT);    // Configura el pin del buzzer como salida
}

// Funcion principal que se ejecuta repetidamente
void loop() { 
  // Declaracion de variables locales
  long duration, distance;    // 'duration' almacena el tiempo del pulso y 'distance' la distancia calculada

  // Enviar un pulso al sensor ultrasonico
  digitalWrite(trigPin, LOW);         // Asegurarse de que el TRIG este en bajo antes de iniciar
  delayMicroseconds(2);               // Pausa de 2 microsegundos
  digitalWrite(trigPin, HIGH);        // Enviar un pulso alto de 10 microsegundos
  delayMicroseconds(10);              // Duracion del pulso alto
  digitalWrite(trigPin, LOW);         // Poner el TRIG en bajo nuevamente
  digitalWrite(buzzer, HIGH);        // Activa el buzzer a través del transistor
  digitalWrite(buzzer, LOW);        // Desactiva el buzzer


  // Medir la duracion del pulso recibido por el pin ECHO
  duration = pulseIn(echoPin, HIGH);  // Captura el tiempo en que el pulso se mantiene en alto

  // Calcular la distancia en centimetros
  // La formula divide el tiempo por 2 (ida y vuelta del pulso) y lo convierte a distancia
  distance = (duration / 2) / 29.1;  

  // Verificar si la distancia es menor o igual a 100 cm
  if (distance <= 100) {
    // Si la distancia es menor o igual a 100 cm, encender el motor y el buzzer
    digitalWrite(motor, HIGH);  // Activa el motor
    digitalWrite(buzzer, HIGH); // Activa el buzzer
    tone(buzzer, 2000);  // Genera un tono de 2000 Hz en el buzzer
    delay(500);          // Espera 500 milisegundos
    noTone(buzzer);      // Detiene el tono
  } else {
    // Si la distancia es mayor a 100 cm, apagar el motor y el buzzer
    digitalWrite(motor, LOW);   // Apaga el motor
    digitalWrite(buzzer, LOW);  // Apaga el buzzer
  }

  // Pausa de 500 milisegundos antes de la proxima lectura
  delay(500);  
}
