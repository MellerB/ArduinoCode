#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(8, 2, NEO_GRB + NEO_KHZ800);



void goTo (int &P, int &T)
{
  if(T>255)
  T=255;
  if(T<0)
  T=0;
  if(P<T)
  P++;
  if(P>T)
  P--;
  
}



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pixels.begin();
}




String input;
String command;
String value;
int P1R=64, P1G=64, P1B=64;
int P2R=64, P2G=64, P2B=64;
int P3R=64, P3G=64, P3B=64;
int P4R=64, P4G=64, P4B=64;

int T1R=64, T1G=64, T1B=64;
int T2R=64, T2G=64, T2B=64;
int T3R=64, T3G=64, T3B=64;
int T4R=64, T4G=64, T4B=64;

int chosen=5;
char color;
int plus;

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
  input=Serial.readString();
  command=String(input[0])+String(input[1])+String(input.length()/2);
  color=input[0];
 
  
  
  if(command[1]=='-')
  plus=(0-(command[2]-48))*8;
  if(command[1]=='+')
  plus=(command[2]-48)*8;

  Serial.println(command);
  Serial.println(plus);
  if(chosen==1)
  {
    if(color=='R')
      T1R+=plus;
    if(color=='G')
      T1G+=plus;
    if(color=='B')
      T1B+=plus;
  }
  
  if(chosen==2)
  {
    if(color=='R')
      T2R+=plus;
    if(color=='G')
      T2G+=plus;
    if(color=='B')
      T2B+=plus;
  }
  
  if(chosen==3)
  {
    if(color=='R')
      T3R+=plus;
    if(color=='G')
      T3G+=plus;
    if(color=='B')
      T3B+=plus;
  }
  
  if(chosen==4)
  {
    if(color=='R')
      T4R+=plus;
    if(color=='G')
      T4G+=plus;
    if(color=='B')
      T4B+=plus;
  }

  if(chosen==5)
  {
    if(color=='R')
    {
      T1R+=plus;
      T2R+=plus;
      T3R+=plus;
      T4R+=plus;
    }
    if(color=='G')
    {
      T1G+=plus;
      T2G+=plus;
      T3G+=plus;
      T4G+=plus;
    }
    if(color=='B')
    {
      T1B+=plus;
      T2B+=plus;
      T3B+=plus;
      T4B+=plus;
    }
  }
  }
goTo(P1R,T1R);
goTo(P1G,T1G);
goTo(P1B,T1B);
goTo(P2R,T2R);
goTo(P2G,T2G);
goTo(P2B,T2B);
goTo(P3R,T3R);
goTo(P3G,T3G);
goTo(P3B,T3B);
goTo(P4R,T4R);
goTo(P4G,T4G);
goTo(P4B,T4B);

  
  pixels.setPixelColor(0, pixels.Color(P1R, P1G, P1B));
  pixels.setPixelColor(7, pixels.Color(P1R, P1G, P1B));

  pixels.setPixelColor(1, pixels.Color(P2R, P2G, P2B));
  pixels.setPixelColor(6, pixels.Color(P2R, P2G, P2B));

  pixels.setPixelColor(2, pixels.Color(P3R, P3G, P3B));
  pixels.setPixelColor(5, pixels.Color(P3R, P3G, P3B));

  pixels.setPixelColor(3, pixels.Color(P4R, P4G, P4B));
  pixels.setPixelColor(4, pixels.Color(P4R, P4G, P4B));
  pixels.show();
  
  //Serial.println(T1G);
  delay(10);
}

