#include <Arduino.h>

void setup() {
  pinMode(2, OUTPUT); // Led Verde
  pinMode(4, OUTPUT); // Led Amarelo
  pinMode(6, OUTPUT); // Led Vermelho
  pinMode(7, INPUT_PULLUP); // Switch
}

void loop() {
 // if (digitalRead(7) == HIGH) == DIA
 // if (digitalRead(7) == LOW) == NOITE
if (digitalRead(7) == HIGH) {
  // Modo DIA == Semáforo Simples
  digitalWrite(2, HIGH); 
  delay(1000);
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH); 
  delay(1000);
  digitalWrite(4, LOW);
  digitalWrite(6, HIGH); 
  delay(3000);
  digitalWrite(6, LOW);
} else 
{
  // Modo NOITE == Led Amarelo continuar intermitente
  digitalWrite(2, LOW);
  digitalWrite(6, LOW);
  digitalWrite(4, HIGH);
  delay(1000);
  digitalWrite(4, LOW);
  delay(1000);
}
}
