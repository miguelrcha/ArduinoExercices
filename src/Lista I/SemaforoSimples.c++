#include <Arduino.h>

void setup() {
  pinMode(2, OUTPUT); // Led Verde
  pinMode(4, OUTPUT); // Led Amarelo
  pinMode(6, OUTPUT); // Led Vermelho
}

void loop() {
  // Preferência Led Verde
  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  delay(1000);

  // Preferência Led Amarelo
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(6, LOW);
  delay(1000);

  // Preferência Led Vermelho
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(6, HIGH);
  delay(3000);
}
