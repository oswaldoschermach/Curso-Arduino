const int R = 9;
const int G = 10;
const int B = 11;
int valorR = 255;
int valorG = 0;
int valorB = 0;

void setup()
{
   pinMode(R, OUTPUT);
   pinMode(G, OUTPUT);
   pinMode(B, OUTPUT);
   analogWrite(R, valorR);
   analogWrite(G, valorG);
   analogWrite(G, valorG);
}

void loop(){
  //valorR = 255;
  //valorG = valorB = 0;
  for(valorB; valorB < 256; valorB++){
    analogWrite(B, valorB);
    delay(10);
  }
  for(valorG; valorG < 256; valorG++){
    analogWrite(G, valorG);
    delay(10);
  }
  for(valorR; valorR >= 0; valorR--){
    analogWrite(R, valorR);
    delay(10);
  } 
}
