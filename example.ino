#include <Servo.h>

// Declaramos la variable para controlar el servo
Servo servoMotor;

int analogPin = 0; // el ping analogico donde pondras tu interruptor o sensor
int valorLDR = 501; // el valor inicial con el que empieza
int umbralNumber = 500; // Ejemplo, puede ser cualquier número deseable

// Variable para almacenar el estado previo del sensor de luz
bool estadoPrevio = false;

void setup() {
  Serial.begin(9600);
  servoMotor.attach(9);
  servoMotor.write(0); // Inicializa el servo en la posición 0 grados
}

void loop() {
  // valorLDR = analogRead(analogPin);   // es la senal que quieres leer con cualquier otro sensor
  bool estadoActual = valorLDR >= umbralNumber; // Determina si hay luz o no

  // Comprobamos si hubo un cambio de estado (de luz a oscuridad o viceversa)
  if (estadoActual != estadoPrevio) {
    // Movemos el servomotor 180 grados
    servoMotor.write(0);
    delay(400); // Espera 0.4 segundos

    // Actualizamos el estado previo
    estadoPrevio = estadoActual;
  }
  else {
    servoMotor.write(90);
  }

}
