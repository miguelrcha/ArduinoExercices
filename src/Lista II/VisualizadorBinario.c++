#include <Arduino.h>

// Define os pinos conectados aos botões (botaoPin[0] = INCREMENTAR, botaoPin[1] = DECREMENTAR)
int botaoPin[] = {7, 6};  

// Define os pinos conectados aos 4 LEDs (de bit menos significativo para o mais)
int ledPin[] = {10, 11, 12, 13}; 

// Variável do contador binário (vai de 0 até 15)
int contador = 0;

// Variáveis para guardar o último estado dos botões (para detectar transições)
bool ultimoEstadoBotaoMais = HIGH;
bool ultimoEstadoBotaoMenos = HIGH;

void setup() {
  // Configura todos os LEDs como saída
  for (int i = 0; i < 4; i++) {
    pinMode(ledPin[i], OUTPUT);
  }

  // Configura os dois botões como entrada com resistor de pull-up
  pinMode(botaoPin[0], INPUT_PULLUP); // botão de incrementar
  pinMode(botaoPin[1], INPUT_PULLUP); // botão de decrementar
}

void loop() {
  // Lê o estado atual dos botões
  bool estadoMais = digitalRead(botaoPin[0]);
  bool estadoMenos = digitalRead(botaoPin[1]);

  // Se o botão de incremento foi pressionado (transição HIGH → LOW)
  if (estadoMais == LOW && ultimoEstadoBotaoMais == HIGH) {
    if (contador < 15) {
      contador++; // Incrementa o contador
    } else {
      piscarLEDs(); // Pisca LEDs se passar do limite
    }
    delay(200); // Delay para debounce
  }

  // Se o botão de decremento foi pressionado (transição HIGH → LOW)
  if (estadoMenos == LOW && ultimoEstadoBotaoMenos == HIGH) {
    if (contador > 0) {
      contador--; // Decrementa o contador
    } else {
      piscarLEDs(); // Pisca LEDs se passar do limite
    }
    delay(200); // Delay para debounce
  }

  // Atualiza os LEDs com base no valor atual do contador
  atualizarLEDs(contador);

  // Atualiza o estado anterior dos botões para próxima leitura
  ultimoEstadoBotaoMais = estadoMais;
  ultimoEstadoBotaoMenos = estadoMenos;
}

// Função que acende os LEDs de acordo com o valor binário de 'valor'
void atualizarLEDs(int valor) {
  for (int i = 0; i < 4; i++) {
    int bit = (valor >> i) & 1; // Extrai o bit correspondente
    digitalWrite(ledPin[i], bit); // Acende ou apaga o LED
  }
}

// Função que pisca todos os LEDs 3 vezes para indicar erro/limite
void piscarLEDs() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      digitalWrite(ledPin[j], HIGH); // Liga todos os LEDs
    }
    delay(100);

    for (int j = 0; j < 4; j++) {
      digitalWrite(ledPin[j], LOW); // Desliga todos os LEDs
    }
    delay(100);
  }
}
