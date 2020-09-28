const int ledPinVerde = 11;
int estadoLedVerde = 0;
const int ledPinAmarelo = 12;
int estadoLedAmarelo = 0;
const int ledPinVermelho = 13;
int estadoLedVermelho = 1;

void setup()
{
  pinMode(ledPinVerde, OUTPUT);
  pinMode(ledPinAmarelo, OUTPUT);
  pinMode(ledPinVermelho, OUTPUT);
}

void loop()
{
  if(estadoLedVerde == 1)
  {
    digitalWrite(ledPinVerde, HIGH);
    delay(3000);
    digitalWrite(ledPinVerde, LOW);
    estadoLedVerde = 0;
    estadoLedAmarelo = 1;
  } 
  else if(estadoLedAmarelo == 1)
  {
    digitalWrite(ledPinAmarelo, HIGH);
    delay(1000);
    digitalWrite(ledPinAmarelo, LOW);
    estadoLedAmarelo = 0;
    estadoLedVermelho = 1;
  }
  else //if(estadoLedVermelho == 1)
  {
    digitalWrite(ledPinVermelho, HIGH);
    delay(2000);
    digitalWrite(ledPinVermelho, LOW);
    estadoLedVermelho = 0;
    estadoLedVerde = 1;
  }
}
