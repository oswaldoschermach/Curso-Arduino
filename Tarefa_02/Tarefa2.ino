const int botao = 2;
const int led = 13;
int estadobotao = 0;
int estadoled = 0;

void setup() {
  
  pinMode(botao, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  estadobotao = digitalRead(botao);
  estadoled = digitalRead(led);

  if(estadobotao == HIGH && estadoled == 0)
  {
      digitalWrite(led, HIGH);
      estadoled = 1;
      delay(2000);
  }
  estadobotao = digitalRead(botao);
  if(estadobotao == HIGH && estadoled == 1)
  {
      digitalWrite(led, LOW);
      estadoled = 0;
      delay(2000);
  }
  
}
