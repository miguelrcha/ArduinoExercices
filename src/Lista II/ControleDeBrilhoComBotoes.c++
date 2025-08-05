#include <Arduino.h>

const byte pinLed[] = {6};
const byte pinButtonInc = 10;
const byte pinButtonDec = 9;

bool estadoButtonInc = 0;
bool estadoButtonDec = 0;
byte count = 0;

void setup() {
  pinMode(pinButtonInc, INPUT_PULLUP);
  pinMode(pinButtonDec, INPUT_PULLUP);
  pinMode(pinLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:T
  // Contador de incrementar e decrementar
  estadoButtonInc = !digitalRead(pinButtonInc);
  if(estadoButtonInc == true && count < 5){
    delay(250);
    count++;
  }
  estadoButtonDec = !digitalRead(pinButtonDec);
  if(estadoButtonDec == true && count > 0){
    delay(250);
    count--;
  }
  switch(count) {
    case 0:
    analogWrite(pinLed, 0);
      break;
    case 1:
    analogWrite(pinLed, 64);
      break;
    case 2:
    analogWrite(pinLed, 128);
      break;
    case 3:
    analogWrite(pinLed, 192);
      break;
    case 4:
    analogWrite(pinLed, 255);
      break;
  }
}


