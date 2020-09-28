const int ledPin[8] = {6, 7, 8, 9, 10, 11, 12, 13};
int i;
int numero;
String texto = ""; // cria uma string vazia

void setup() 
{
  pinMode(ledPin[0], OUTPUT);
  pinMode(ledPin[1], OUTPUT);
  pinMode(ledPin[2], OUTPUT);
  pinMode(ledPin[3], OUTPUT);
  pinMode(ledPin[4], OUTPUT);
  pinMode(ledPin[5], OUTPUT);
  pinMode(ledPin[6], OUTPUT);
  pinMode(ledPin[7], OUTPUT);  

  Serial.begin(9600);  

  Serial.println("Numero decimal a converter para binario terminando com a letra d (exemplo: 123d) = ");
}

void sequencia()
{
  for(i = 0; i < 8; i++)
  {
    Serial.println(i);
    digitalWrite(ledPin[i], HIGH);
    delay(1000);
  }
  for(i = 7; i >= 0; i--)
  {
    Serial.println(i);
    digitalWrite(ledPin[i], LOW);
    delay(1000);
  }
}

void loop()
{ 
  /* lendo caracteres ASCII no monitor serial, acumulando-os na string texto e depois convertendo a string para um numero inteiro. */
   if(Serial.available() > 0)
  {
    char caractere = Serial.read();
    if(isDigit(caractere))
    {
      texto += caractere;
      Serial.println(texto);
    }

    if(caractere == 'd')
    {
      numero = texto.toInt();
      Serial.println("Numero decimal = ");
      Serial.println(numero);
      texto = "";      
      sequencia();
      verifica(numero);
    }
  }
}

void verifica(int num){
    if(num >= 128){
      digitalWrite(ledPin[7], HIGH);
      num-=128;
    }
    if(num >= 64){
        digitalWrite(ledPin[6], HIGH);
        num-=64;
    }
    if(num >= 32){
        digitalWrite(ledPin[5], HIGH);
        num-=32;
    }
    if(num >= 16){
        digitalWrite(ledPin[4], HIGH);
      num-=16;
    }
    if(num >= 8){
        digitalWrite(ledPin[3], HIGH);
        num-=8;
    }
    if(num >= 4){
        digitalWrite(ledPin[2], HIGH);
        num-=4;
    }
    if(num >= 2){
        digitalWrite(ledPin[1], HIGH);          
        num-=2;
    }
    if(num >= 1){
      digitalWrite(ledPin[0], HIGH);
    }
  delay(3000);
}
