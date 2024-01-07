const int sensorPin = A0;
const int motorPin = 2; 
const int ledPin = 7; 
const int buzzerPin = 4; 

void setup() {
  Serial.begin(9600); 

  pinMode(motorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
   float temperaturaC = map(sensorValue, 102, 307, 0, 100); // Convertendo a leitura para temperatura


  Serial.print("Valor do Sensor: ");
  Serial.print(sensorValue);
  Serial.print("V / Temperatura: ");
  Serial.print(temperaturaC);
  Serial.println("°C");

 
  if (temperaturaC >= 30) {
    digitalWrite(motorPin, HIGH); // Liga o motor do ventilador
  } else {
    digitalWrite(motorPin, LOW); // Desliga o motor do ventilador
  }

  if (temperaturaC >= 50) {
    digitalWrite(ledPin, HIGH); // Liga Led
    tone(buzzerPin, 1000); // Ativa Buzzer
  } else {
    digitalWrite(ledPin, LOW); // Desliga Led
    noTone(buzzerPin); // Desativa Buzzer
  }

  delay(1000); // Aguarda 1 segundo antes de realizar a próxima leitura
}