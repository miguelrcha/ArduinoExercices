#include <Arduino.h>

// Aplicar no Tinkercad

int leds[] = {2, 3, 4, 5}; // Pinos dos LEDs
const int botaoUp = 6;
const int botaoDown = 7;

int contador = 0;
bool ultimoEstadoUp = false;
bool ultimoEstadoDown = false;

void setup() {
  for (int i = 0; i < 4; i++) pinMode(leds[i], OUTPUT);
  pinMode(botaoUp, INPUT);
  pinMode(botaoDown, INPUT);
  atualizarLeds();
}

void loop() {
  bool estadoUp = digitalRead(botaoUp);
  bool estadoDown = digitalRead(botaoDown);

  if (estadoUp && !ultimoEstadoUp) {
    if (contador < 15) {
      contador++;
      atualizarLeds();
    } else {
      piscarLeds();
    }
  }

  if (estadoDown && !ultimoEstadoDown) {
    if (contador > 0) {
      contador--;
      atualizarLeds();
    } else {
      piscarLeds();
    }
  }

  ultimoEstadoUp = estadoUp;
  ultimoEstadoDown = estadoDown;
  delay(50); // debounce simples
}

void atualizarLeds() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(leds[i], (contador >> i) & 1);
  }
}

void piscarLeds() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) digitalWrite(leds[j], LOW);
    delay(150);
    for (int j = 0; j < 4; j++) digitalWrite(leds[j], HIGH);
    delay(150);
  }
  atualizarLeds(); // Volta pro valor correto
}
