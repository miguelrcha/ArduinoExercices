#include <Arduino.h>

// ------------------ CONFIGURAÇÃO ------------------
const byte pinButtonInc = 10; // Botão: troca programa
const byte pinButtonDec = 9;  // Botão: inicia/reinicia ciclo

// LED azul, verde, amarelo, vermelho
const byte leds[] = {7, 6, 5, 4};

// Estados
enum Estado { ENCHENDO, LAVANDO, ENXAGUANDO, CENTRIFUGANDO };
enum Programa { NORMAL, DELICADO, PESADO };

// Estrutura para associar estado, tempo e LED
struct Etapa {
  Estado estado;
  unsigned long duracao; // em ms
  byte ledPin;
};

// Lista de programas com tempos diferentes
Etapa programas[3][4] = {
  // NORMAL
  {
    {ENCHENDO,    5000, leds[0]}, // Azul
    {LAVANDO,     8000, leds[1]}, // Verde
    {ENXAGUANDO,  6000, leds[2]}, // Amarelo
    {CENTRIFUGANDO, 4000, leds[3]} // Vermelho
  },
  // DELICADO
  {
    {ENCHENDO,    4000, leds[0]},
    {LAVANDO,     5000, leds[1]},
    {ENXAGUANDO,  5000, leds[2]},
    {CENTRIFUGANDO, 3000, leds[3]}
  },
  // PESADO
  {
    {ENCHENDO,    7000, leds[0]},
    {LAVANDO,    10000, leds[1]},
    {ENXAGUANDO,  8000, leds[2]},
    {CENTRIFUGANDO, 5000, leds[3]}
  }
};

// Variáveis de controle
Programa progAtual = NORMAL;
int etapaAtual = 0;
unsigned long inicioEtapa;
bool cicloAtivo = false;

// ------------------ SETUP ------------------
void setup() {
  Serial.begin(9600);
  for (byte i = 0; i < 4; i++) pinMode(leds[i], OUTPUT);
  pinMode(pinButtonInc, INPUT_PULLUP);
  pinMode(pinButtonDec, INPUT_PULLUP);

  Serial.println("Maquina de Lavar pronta!");
  mostrarPrograma();
}

// ------------------ LOOP ------------------
void loop() {
  // Trocar programa
  if (digitalRead(pinButtonInc) == LOW && !cicloAtivo) {
    progAtual = (Programa)((progAtual + 1) % 3);
    mostrarPrograma();
    delay(300);
  }

  // Iniciar/Reiniciar ciclo
  if (digitalRead(pinButtonDec) == LOW && !cicloAtivo) {
    etapaAtual = 0;
    cicloAtivo = true;
    inicioEtapa = millis();
    mostrarEtapa();
    delay(300);
  }

  // Executar ciclo
  if (cicloAtivo) {
    Etapa etapa = programas[progAtual][etapaAtual];

    // Piscar LED
    if ((millis() / 500) % 2 == 0) {
      digitalWrite(etapa.ledPin, HIGH);
    } else {
      digitalWrite(etapa.ledPin, LOW);
    }

    // Passar para próxima etapa
    if (millis() - inicioEtapa >= etapa.duracao) {
      digitalWrite(etapa.ledPin, LOW);
      etapaAtual++;
      if (etapaAtual >= 4) {
        Serial.println("Ciclo finalizado!");
        cicloAtivo = false;
      } else {
        inicioEtapa = millis();
        mostrarEtapa();
      }
    }
  }
}

// ------------------ FUNÇÕES ------------------
void mostrarPrograma() {
  const char* nomesProg[] = {"NORMAL", "DELICADO", "PESADO"};
  Serial.print("Programa selecionado: ");
  Serial.println(nomesProg[progAtual]);
}

void mostrarEtapa() {
  const char* nomesEtapas[] = {"ENCHENDO", "LAVANDO", "ENXAGUANDO", "CENTRIFUGANDO"};
  Serial.print("Etapa: ");
  Serial.println(nomesEtapas[etapaAtual]);
}
