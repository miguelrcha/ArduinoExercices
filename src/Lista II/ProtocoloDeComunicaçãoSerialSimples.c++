#include <Arduino.h>

//Definição de PINOS utilizados;
const int ledPino = 5;        //Definição de LED;
const int potenciaPino = A0;  //Definição de Potenciômetro;
const int botaoPino = 13;    //Definição de Botão;


bool ledEstado = false; //Definição do estado do LED;

void setup() {
  pinMode(ledPino, OUTPUT);
  pinMode(botaoPino, INPUT_PULLUP); 
  
  Serial.begin(9600); // Inicia comunicação serial a 9600 bps
  Serial.println("Envie comandos como: LED:ON< LED:OFF, READ:POT, READ:BTN, STATUS");
}

void loop() {
  if (Serial.available() > 0) { //Verificação de Solicitações;
  String comando = Serial.readStringUntil('\n');


    if (comando.equalsIgnoreCase("LED:ON")) {
      ledEstado = true;
      digitalWrite(ledPino, HIGH);
      Serial.println("LED ligado."); //Comando 1;

    }
    else if (comando.equalsIgnoreCase("LED:OFF")) {
      ledEstado = false;
      digitalWrite(ledPino, LOW);
      Serial.println("LED desligado.");//Comando 2;
    }
    else if (comando.equalsIgnoreCase("READ:POT")) {
      int potenciaValor = analogRead(potenciaPino);
      Serial.print("Potenciometro: ");
      Serial.println(potenciaValor); //Comando 3;
    }
    else if (comando.equalsIgnoreCase("READ:BTN")) {
      int botaoEstado = digitalRead(botaoPino);
      Serial.print("Botao: ");
      Serial.println(botaoEstado == LOW ? "Pressionado" : "Despressionado");
    }
    else if (comando.equalsIgnoreCase("STATUS")) {
  
      Serial.print("LED: ");
      Serial.println(ledEstado ? "Ligado" : "Desligado"); //Referente ao LED;

    
      Serial.print("PotenciÔmetro: ");
      Serial.println(analogRead(potenciaPino)); //Referente ao Potenciômetro;

    
      Serial.print("Botao: ");
      Serial.println(digitalRead(botaoPino) == LOW ? "Pressionado" : "Despressionado"); //Referente ao Botão;
    }
  }
}