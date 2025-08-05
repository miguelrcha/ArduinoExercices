#include <Arduino.h>

const byte pinLed[4] = {8, 7, 6, 5};

const byte pinButtonInc = 9;
const byte pinButtonDec = 10;

bool estadoButtonInc = 0;
bool estadoButtonDec = 0;

byte count = 0;
String binario = "";

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<4; i++) {
    pinMode(pinLed[i], OUTPUT);
  }
  pinMode(pinButtonInc, INPUT_PULLUP);
  pinMode(pinButtonDec, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:T
  estadoButtonInc = !digitalRead(pinButtonInc);
  if(pinButtonInc == true && count < 15){
    delay(250);
    count++; // Ação de contar de 0 ate 15
  }
  estadoButtonDec = !digitalRead(pinButtonDec);
  if(pinButtonDec == true && count > 0){
    delay(250);
    count--; // Ação de diminuir de 15 para 0 
  }
  binario = String(count,BIN);
  while(binario.length() < 4) {
    binario = "0" + binario; // Implementar os zeros à esquerda do número
  }
  for(int i=0; i<4; i++) {
    if (binario[i] == '1') {
      digitalWrite(pinLed[i], HIGH);
    } else {
      digitalWrite(pinLed[i], LOW);
    }
  }
}
