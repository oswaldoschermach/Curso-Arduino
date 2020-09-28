const int botao = 2;
const int led = 13;
int estadobotao = 0;


void setup() {
  
  pinMode(botao, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  estadobotao = digitalRead(botao);
  
  if(estadobotao == HIGH){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }
}
