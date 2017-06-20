#include <ST_HW_HC_SR04.h>
#define buzzer 9
int old=0;
int act=0;
ST_HW_HC_SR04 uSensor(13, 12); // ST_HW_HC_SR04(TRIG, ECHO)

void setup() {
    Serial.begin(9600);

}

int makeSense(ST_HW_HC_SR04 S)
{
  int tmp=(S.getHitTime()-200)/200;
  if (tmp>8)
  tmp=8;
  return tmp;
}



int val;
String mess;
void loop() {
    
    mess="";
    act=makeSense(uSensor);
    if(act!=-1)
    {
    val=act;
    old=act;
    }
    else
    val=old;
    
    for(int i=0;i<val;i++)
    mess=mess+"XXXXXXXX";
    
    Serial.println(mess);
    noTone(buzzer);
    if (val==1)
    tone(buzzer, 262); 
    else if (val==2)
    tone(buzzer, 294); 
    else if (val==3)
    tone(buzzer, 330); 
    else if (val==4)
    tone(buzzer, 349);
    else if (val==5)
    tone(buzzer, 392); 
    else if (val==6)
    tone(buzzer, 440); 
    else if (val==7)
    tone(buzzer, 494); 
    else if (val==8)
    tone(buzzer, 523);    
    else
    noTone(buzzer);
}
