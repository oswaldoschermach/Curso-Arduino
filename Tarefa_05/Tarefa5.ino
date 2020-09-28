
const int ledPin1 = 13;
const int botao1 = 2;
int estadoBotao1 = 0;

const int ledPin2 = 12;
const int botao2 = 3;
int estadoBotao2 = 0;

const int ledPin3 = 11;
const int botao3 = 4;
int estadoBotao3 = 0;

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
}

void loop() {

  estadoBotao1 = digitalRead(botao1);
  estadoBotao2 = digitalRead(botao2);
  estadoBotao3 = digitalRead(botao3);

  if(estadoBotao1 == HIGH){
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
    }
  else if(estadoBotao2 == HIGH){
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, LOW);
    }
  else if(estadoBotao3 == HIGH){
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, HIGH);
  }

}
