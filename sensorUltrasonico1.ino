//Programa sensor de presença com sensor ultrassônico

/*#include <ultrasonic.h>

//define os pinos do arduino ligados ao trigger e echo

#define PINO_TRG 7
#define PINO_ECHO 6

//distancia em centimetros 
float distancia_minima = 5;
float distancia_maxima = 80;

//pino a ser acionado em caso de detecção 
const int buzzer = 10;

//inicializa o sensor ultrasonico nos pinos especificos
Ultrasonic ultrasonic(PINO_TRG, PINO_ECHO);


void setup() {
  //inicializa a serial
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {
 //variaveis p/ guardar os valores em 
 // cm (cmSec) e polegadas (inMsec)
 float cmMsec, inMsec;

 //lê os valres do sensor ultrasonico 
 long micrisec = ultrasonic.timing();
 //Atribui os valores em cm ou polegadas as variavéis
 cmMsec = ultrasonic.convert(microsec,Ultrasonic: :CM);
 inMsec = ultrasonic.convert(microsec, Ultrasonic: :IN);

 if (cmMsec > distancia_minima && cmMsec < distancia_maxima){
    tone(buzzer, 1000);
  delay(500);

    tone(buzzer, 1000);
  delay(500);

    tone(buzzer, 1000);
   delay(500);    
 }

 else {
    noTone(buzzer);
 }

 delay(200);
}*/

//Configuração de Distancia Mínima em centimetros
const int distancia_carro = 30; 

//Configurações de Portas do Arduino

//Sensor
const int TRIG = 3;
const int ECHO = 2;

//Demais componentes
const int ledGreen = 7;
const int ledRed = 8;
const int buzzer = 9;

// Variaveis para funcionamento do Buzzer
float seno;
int frequencia;

void setup() {
  Serial.begin(9600);
  
  // Configurações do Sensor
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  
  // Configurações do LED
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);

  //Configurações do Buzzer
  pinMode(buzzer, OUTPUT); 
  
}

void loop() {
  int distancia = sensor_morcego(TRIG,ECHO);

    if(distancia <= distancia_carro){
      Serial.print("Atenção: ");
      Serial.print(distancia);
      Serial.println("cm");
      digitalWrite(ledGreen, HIGH);
      digitalWrite(ledRed, HIGH);
      tocaBuzzer();
    }
    else{
      Serial.print("Livre: ");
      Serial.print(distancia);
      Serial.println("cm");
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, LOW);
      noTone(buzzer);
    }
  delay(100);
  
}

int sensor_morcego(int pinotrig,int pinoecho){
  digitalWrite(pinotrig,LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig,LOW);

  return pulseIn(pinoecho,HIGH)/60;
}

//Função para execução do Alarme Sonoro
void tocaBuzzer(){
 for(int x=0;x<180;x++){
  seno=(sin(x*3.1416/180));
  frequencia = 2000+(int(seno*1000));
  tone(buzzer,frequencia);
  delay(2);
}

}
