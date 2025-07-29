#include <Arduino.h>

void setup() {
  
  // Semáforo 1 (Via A)
  pinMode(2, OUTPUT); // Led Verde
  pinMode(4, OUTPUT); // Led Amarelo
  pinMode(6, OUTPUT); // Led Vermelho
  
  // Semáforo 2 (Via B)
  pinMode(11, OUTPUT); // Led Verde
  pinMode(12, OUTPUT); // Led Amarelo
  pinMode(13, OUTPUT); // Led Vermelho

}

void loop() {
 digitalWrite(2, HIGH); // Via A(Verde)
 digitalWrite(13, HIGH); // Via B(Vermelho)
 delay(3000);
 digitalWrite(2, LOW); // Via A(Verde)
 digitalWrite(4, HIGH); // Via A(Amarelo)
 delay(3000);
 digitalWrite(4, LOW);
 digitalWrite(6, HIGH);
 delay(1000);
 // Correto
  
 digitalWrite(13, LOW);
 delay(3000);
 digitalWrite(11, HIGH);
 delay(3000);
 digitalWrite(11, LOW);
 digitalWrite(12, HIGH);
  
}
