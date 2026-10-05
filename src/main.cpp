#include <Arduino.h>
#include <Bounce2.h>

Bounce btn = Bounce();




//Explicação millis()
//#define pinLed 2
//
//bool estadoLed = 0;
//
//unsigned long tempoAnterior = 0;
//unsigned long intervalo = 500;
//
//void setup() {
//  pinMode(pinLed, OUTPUT);
//}
//
//void loop() {
//  unsigned long tempoAtual = millis();
//  
//  if(tempoAtual - tempoAnterior >= intervalo){
//
//    estadoLed = !estadoLed;
//
//    tempoAnterior = tempoAtual;
//  }
//
//  digitalWrite(pinLed, estadoLed);
//}



#define led1 2
#define led2 17
#define botao 23





//Ex. 1 millis()

bool estadoLed1 = LOW; 
bool estadoLed2 = HIGH;

unsigned long tempoAnterior = 0;
unsigned long tempoAnterior1 = 0;
unsigned long tempoAnterior2 = 0;
//unsigned long intervalo = 1000;
unsigned long intervalo1 = 500;
unsigned long intervalo2 = 2000;
unsigned long intervalo3 = 3000; 


//void setup(){
//   
//  pinMode(led1, OUTPUT);
//  pinMode(led2, OUTPUT);
//}
//
//void loop(){
//  unsigned long tempoAtual = millis();
//
//  if(tempoAtual - tempoAnterior >= intervalo){
//
//    estadoLed1 = !estadoLed1;
//    estadoLed2 =! estadoLed2;
//
//    tempoAnterior = tempoAtual;
//  }
//
//  digitalWrite(led1, estadoLed1);
//  digitalWrite(led2, estadoLed2);
//}

//Ex. 2 millis()
//
//void setup(){
//   
//  pinMode(led1, OUTPUT);
//  pinMode(led2, OUTPUT);
//}
//
//void loop(){
//  unsigned long tempoAtual = millis();
//
//  if(tempoAtual - tempoAnterior1 >= intervalo1){
//
//    estadoLed1 = !estadoLed1;
//    tempoAnterior1 = tempoAtual;
//   
//  }
//
//  if(tempoAtual - tempoAnterior2 >= intervalo2){
//
//    estadoLed2 = !estadoLed2;
//    tempoAnterior2 = tempoAtual;
//     
//  }
//
//  
//
//  digitalWrite(led1, estadoLed1);
//  digitalWrite(led2, estadoLed2);
//}


// Ex. 3

//void setup(){  
//  Serial.begin(115200);
//}
//
//void loop(){
//  unsigned long tempoAtual = millis();
//
//  if(tempoAtual - tempoAnterior >= intervalo2){
//
//    Serial.print("Contagem: ");
//    Serial.println(tempoAtual);
//
//    tempoAnterior = tempoAtual;
//   
//  }
//}

void setup(){
  pinMode(led2, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
  btn.attach(botao); 

}

void loop(){
  unsigned long tempoAtual = millis();

  btn.update();


  if (btn.fell()){
    estadoLed1 = HIGH;
    digitalWrite(led2, estadoLed1);
    tempoAnterior = tempoAtual;       
  }

  if(btn.read() == HIGH && tempoAtual - tempoAnterior >= intervalo3){
    estadoLed1 = LOW;
    digitalWrite(led2, estadoLed1);

  }

}  
  


