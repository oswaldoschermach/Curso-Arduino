const int pinoPotenciometro = A0;
const int led = 13;
int valorPot = 0;

void setup()
{
  pinMode(led, OUTPUT);
}

void loop()
{
  valorPot = analogRead(pinoPotenciometro);
  digitalWrite(led, HIGH);
  delay(valorPot);
  
  digitalWrite(led, LOW);
  delay(valorPot);
  
}
