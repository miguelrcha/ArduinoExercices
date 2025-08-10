#include <Arduino.h>

const int leds[4] = {6, 5, 4, 3};          //Definição dos LEDS;
const int botoes[4] = {11, 10, 9, 8};      //Definição dos Botões;
const int potenciometro = A0;              //Definição do Potenciômetro;

int delayTime = 0;   //Delay do Potenciômetro

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);   //LEDS iniciam-se apagados;
  }

  for (int i = 0; i < 4; i++) {
    pinMode(botoes[i], INPUT_PULLUP);
  }
}

void loop() {
  delayTime = map(analogRead(potenciometro), 0, 1023, 100, 1000);

  if (digitalRead(botoes[0]) == LOW) {
    sequenciaEsquerda(); //Referente ao botão 1;
  } 
  else if (digitalRead(botoes[1]) == LOW) {
    sequenciaDireita(); //Referente ao botão 2;
  } 
  else if (digitalRead(botoes[2]) == LOW) {
    piscarTodos(); //Referente a botão 3;
  } 
  else if (digitalRead(botoes[3]) == LOW) {
    piscarAlternado(); //Referente ao botão 4;
  } 
  else {
    for (int i = 0; i < 4; i++) {
      digitalWrite(leds[i], LOW);
    }
  }
}

void sequenciaEsquerda() {   //Definição das Animações;
  for (int i = 0; i < 4; i++) {
    digitalWrite(leds[i], HIGH);
    delay(300);
    digitalWrite(leds[i], LOW);
  }
}

void sequenciaDireita() {   //Definição das Animações;
  for (int i = 3; i >= 0; i--) {
    digitalWrite(leds[i], HIGH);
    delay(300);
    digitalWrite(leds[i], LOW);
  }
}

void piscarTodos() { //Definição das Animações;
  for (int i = 0; i < 4; i++) {
    digitalWrite(leds[i], HIGH);
  }
  delay(300);
  for (int i = 0; i < 4; i++) {
    digitalWrite(leds[i], LOW);
  }
  delay(300);
}

void piscarAlternado() { //Definição das Animações;
  //Referentes aos LEDS 1 e 3;
  digitalWrite(leds[0], HIGH);
  digitalWrite(leds[2], HIGH);
  delay(delayTime);
  digitalWrite(leds[0], LOW);
  digitalWrite(leds[2], LOW);

  //Referentes aos LEDS 2 e 4;
  digitalWrite(leds[1], HIGH);
  digitalWrite(leds[3], HIGH);
  delay(300);
  digitalWrite(leds[1], LOW);
  digitalWrite(leds[3], LOW);
}