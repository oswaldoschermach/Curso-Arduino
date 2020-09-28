#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int EstadoBotaoSeleciona;
int EstadoBotaoConfirma;

int milhar, centena, dezena, unidade, m = 0, c = 0, d = 0, u = 0;
int tentativas = 5;
int acertos = 0;
int digito = 1;
int inicializa = 1;

void setup()
{
  pinMode(8, INPUT); // Botao confirma
  pinMode(9, INPUT); // Botao seleciona

  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop()
{
  // inicializa o jogo sorteando os 4 digitos sem repeticao
  if(inicializa == 1)
  {
    milhar = random(0,9);
    Serial.println(milhar);
    delay(2000);

    do {
      centena = random(0,9);
    } while(centena == milhar);
    Serial.println(centena);
    delay(2000);

    do {
      dezena = random(0,9);
    } while(dezena == milhar || dezena == centena);
    Serial.println(dezena);
    delay(2000);

    do {
      unidade = random(0,9);
    } while(unidade == milhar || unidade == centena || unidade == dezena);
    Serial.println(unidade);

    lcd.begin(16, 2);
    lcd.setCursor(0,0);
    lcd.print("Master Mind");
    /*
    lcd.setCursor(0,1);
    lcd.print(milhar);
    lcd.print(centena);
    lcd.print(dezena);
    lcd.print(unidade);
    */
    delay(5000);

    inicializa = 0;
    lcd.setCursor(0,1);
    lcd.print("            ");
  } // fim da inicializacao com sorteio

  lcd.setCursor(0,1);
  lcd.print(m);
  lcd.print(c);
  lcd.print(d);
  lcd.print(u);
  lcd.print(" posicao = ");
  lcd.print(digito);

  //_________________________________________________________
  // Entrada do palpite

  EstadoBotaoConfirma = digitalRead(8);
  if(EstadoBotaoConfirma == HIGH && digito <= 5)
  {
    digito++;
    if(digito > 5)
    {
      digito = 1;
    }
    delay(500);
  }

  EstadoBotaoSeleciona = digitalRead(9);
  if(EstadoBotaoSeleciona == HIGH && digito == 1)
  {
    lcd.setCursor(0,1);
    m++;
    if(m > 9)
    {
      m = 0;
    }
  }

  if(EstadoBotaoSeleciona == HIGH && digito == 2)
  {
    lcd.setCursor(0,2);
    c++;
    if(c > 9)
    {
      c = 0;
    }
  }

  if(EstadoBotaoSeleciona == HIGH && digito == 3)
  {
    lcd.setCursor(0,3);
    d++;
    if(d > 9)
    {
      d = 0;
    }
  }

  if(EstadoBotaoSeleciona == HIGH && digito == 4)
  {
    lcd.setCursor(0,4);
    u++;
    if(u > 9)
    {
      u = 0;
    }
  }
  delay(500);

  if(EstadoBotaoSeleciona == HIGH && digito == 5){
        lcd.setCursor(0,1);
        lcd.print("            ");
        lcd.setCursor(0,1);
      tentativas-=1;

    if(tentativas>0){

      if(milhar==m && centena==c && dezena==d && unidade==u){
        lcd.print("Voce ganhou!");
        tentativas=5;
        inicializa=1;
      }
      else{

          if(milhar==m){
            lcd.print("[ ");
            lcd.print(m);
          }
          else if(milhar==c || milhar==d || milhar==u){
            lcd.print("[ ? ");
          }
          else{
            lcd.print("[ *");
          }

          lcd.setCursor(4,1);

          if(centena==c){
            lcd.print(c);
          }
          else if(centena==m || centena==d || centena==u){
            lcd.print("?");
          }
          else{
            lcd.print("*");
          }

          lcd.setCursor(6,1);

          if(dezena==d){
            lcd.print(d);
          }
          else if(dezena==m || dezena==c || dezena==u){
            lcd.print("?");
          }
          else{
            lcd.print("*");
          }

          lcd.setCursor(8,1);

          if(unidade==u){
            lcd.print(u);
            lcd.print(" ]");
          }
          else if(unidade==m || unidade==c || unidade==d){
            lcd.print("? ]");
          }
          else{
            lcd.print("* ]");
          }
      }
      delay(5000);
  }
    else{
      lcd.print("Voce perdeu!");
      delay(5000);
      lcd.setCursor(0,0);
      lcd.print("A SENHA É:");
      lcd.setCursor(0,1);
      lcd.print(milhar);
      lcd.print(centena);
      lcd.print(dezena);
      lcd.print(unidade);
      inicializa=1;
      m=0;
      c=0;
      d=0;
      u=0;
      tentativas=5;
    }
  }
}
