#include <Arduino.h>

byte pinBTN = 2;       // LED no pino 2
byte botaoBTN = 3;     // Botão no pino 3
bool estadoBTN = false;
int VAR = 0;
int VAR2 = 0;

void setup() {
  pinMode(pinBTN, OUTPUT);         // LED como saída
  pinMode(botaoBTN, INPUT_PULLUP); // Botão com pull-up
  digitalWrite(pinBTN, LOW);       // Começa desligado
}

void loop() {
  controleLED(); // Controla LED com botão
}

bool lerBotao(byte botao) {
  return !digitalRead(botao); // Inverte leitura
}

void controleLED() {
  VAR = lerBotao(botaoBTN); // Lê botão

  if (VAR == HIGH && VAR2 == LOW) {
    estadoBTN = !estadoBTN; // Alterna estado do LED
    delay(100);             // Debounce
  }

  VAR2 = VAR;

  digitalWrite(pinBTN, estadoBTN ? HIGH : LOW); // Liga ou desliga LED
}
// Controle de LED com botão
// Usa pull-up interno para simplificar circuito    