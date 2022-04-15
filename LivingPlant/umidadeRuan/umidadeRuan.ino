#define pinoSinal A0

unsigned long intervalo = 12000; // intervalo de tempo em MS para cada leitura
unsigned long tempoInicial= 0;

int valorSinal;

//protoType:
void apagaled();
void acendeLed();

void setup() {
  Serial.begin(9600);
  pinMode(pinoSinal, INPUT);
  DDRD = B11100000;
}

void loop() {

// millis usado para um controle melhor de informação
  unsigned long tempoAtual = millis();

  if(tempoAtual - tempoInicial > intervalo){

    tempoInicial = tempoAtual;

      valorSinal = analogRead(pinoSinal);

  Serial.print("Porta analogica: ");
  Serial.print(valorSinal);
  Serial.print("\n");
  if(valorSinal <= 0){
      Serial.print("Senser sem contato\n");
        acendeLed();
        delay(500);
        apagaLed();  
  }
    
    if(valorSinal > 0 && valorSinal < 400){
        Serial.print("Status: Solo umido\n");
        apagaLed();
        PORTD = B10000000;
      }

    if(valorSinal > 400 && valorSinal < 800){
        Serial.print("Status: Solo moderado\n");
        apagaLed();
        PORTD = B01000000;
     }

    if(valorSinal > 800 && valorSinal > 1024){
        Serial.print("Status: Solo seco\n");
        apagaLed();
        PORTD = B00100000;
     }
  }
}
 void apagaLed(){
    PORTD = B00000000;
  }
  void acendeLed(){
    PORTD = B11100000; 
   }

