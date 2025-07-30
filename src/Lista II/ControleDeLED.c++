#include <Arduino.h>

int botaoPin = 7;  //Refere-se ao Botão
int ledPin = 10;    //Refere-se ao LED
bool estadoBotao = 0; //Utilizada para armazenar o estado do Botão

void setup() { //Inicialização
  pinMode(ledPin, OUTPUT);          
  pinMode(botaoPin, INPUT_PULLUP); 
}

bool lerBotao() { //Ler o estado do Botão
  return digitalRead(botaoPin); 
}

void controleLED(bool estado) { //Controlar o estado do LED
  digitalWrite(ledPin, estado ? HIGH : LOW);
}

void loop() { //Lógica Principal
  estadoBotao = lerBotao(); //Leitura do Botão   
  controleLED(estadoBotao); //Controle do LED conforme leitura     
}
