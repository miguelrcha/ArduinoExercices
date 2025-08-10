#include <Arduino.h>

const byte pinButton[] = {8};
const byte pinLed[] = {9};

bool estadoLed = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinButton, INPUT_PULLUP);
  pinMode(pinLed, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  estadoLed = lerBotao();
  controleLED(estadoLed);
}

bool lerBotao() {
  // INPUT_PULLUP no void setup(){} == "!"
  return !digitalRead(pinButton);
}

void controleLED(bool estadoLed) {
  digitalWrite(pinLed, estadoLed);
}
