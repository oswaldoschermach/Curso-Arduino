const int ledPin1 = 13;
const int botao1 = 2;
int estadoBotao1 = 0;
int estadoled1 = 0;

const int ledPin2 = 12;
const int botao2 = 3;
int estadoBotao2 = 0;
int estadoled2 = 0;

const int ledPin3 = 11;
const int botao3 = 4;
int estadoBotao3 = 0;
int estadoled3 = 0;

void setup(){
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
  pinMode(botao3, INPUT);  
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);

  Serial.begin(9600);
  randomSeed(analogRead(0));
}



void loop()
{
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  int numero = random(1, 3);
  Serial.println(numero);
  estadoBotao1 = digitalRead(botao1);
  estadoBotao2 = digitalRead(botao2);
  estadoBotao3 = digitalRead(botao3);
  
  if(estadoBotao1 == HIGH && numero == 1){
    digitalWrite(ledPin1, HIGH);
    delay(2000);
  }
  else if(estadoBotao1 == HIGH && numero != 1){
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    delay(2000);
  }
  
  if(estadoBotao2 == HIGH && numero == 2){
    digitalWrite(ledPin2, HIGH);
    delay(2000);
  }
  else if(estadoBotao2 == HIGH && numero != 2){
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    delay(2000);
  }
  
  if(estadoBotao3 == HIGH && numero == 3){
    digitalWrite(ledPin3, HIGH);
    delay(2000);
  }
  else if(estadoBotao3 == HIGH && numero != 3){
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    delay(2000);
  } 
 }
