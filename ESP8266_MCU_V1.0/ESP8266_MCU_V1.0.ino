/*************************************************************
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_MAX_SENDBYTES 256 //alargar el maxiomo del mensaje
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
  char auth[] = "bc5aa1f8e8954a4992fbce283d802d15";//nicolas
//char auth[] = "cbde13b152d3432da53ad5585f9eb550";//jefer

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "JAPEREZ";
char pass[] = "26071967";
int alert=0;
char tweets[256];
char dato[12];
BLYNK_WRITE(V0) // V5 is the number of Virtual Pin  Boton 1
{
  Serial.print("w");
}
BLYNK_WRITE(V1) // V5 is the number of Virtual Pin  Boton 2
{
  Serial.print("x");
}

BLYNK_WRITE(V2) // V5 is the number of Virtual Pin  
{
  Serial.print("y");
}

BLYNK_WRITE(V3) // V5 is the number of Virtual Pin  
{
  Serial.print("z");
}

BLYNK_WRITE(V4) // V5 is the number of Virtual Pin  
{
  int pinValue = param.asInt();
  
  //sprintf(dato,"S%d",pinValue);
  Serial.print("s");
  Serial.write(pinValue);
}

BLYNK_WRITE(V5) // V5 is the number of Virtual Pin  
{
  int pinValue = param.asInt();
  Serial.print("h");
  Serial.write(pinValue);
}

BLYNK_WRITE(V6) // V5 is the number of Virtual Pin  Sala
{
 int hora, minuto;
  int pinValue = param.asInt();
  hora=char(pinValue/3600);
  minuto=char((pinValue%3600)/60);
  Serial.print("i");  
  Serial.write(hora);//Envia parte alta
  Serial.write(minuto);//Envia parte baja 
}

BLYNK_WRITE(V7) // V5 is the number of Virtual Pin  
{
  int hora, minuto;
  int pinValue = param.asInt();
  hora=char(pinValue/3600);
  minuto=char((pinValue%3600)/60);
  Serial.print("f");  
  Serial.write(hora);//Envia parte alta
  Serial.write(minuto);//Envia parte baja 
}

BLYNK_WRITE(V8) // V5 is the number of Virtual Pin  
{
  int pinValue = param.asInt();
  Serial.print("m");
  Serial.write(pinValue);
}

void BlYNK_CONECTED_PSOC(int Puerto,int Hora,int Minuto)
{
 int tiempo=(Hora*3600)+(Minuto*60);
 Blynk.virtualWrite(Puerto,tiempo);
}



BLYNK_CONNECTED() {
  //seconds from the start of a day. 0 - min, 86399 - max
  int startAt = 5 * 60; //00:05

  //seconds from the start of a day. 0 - min, 86399 - max
  int stopAt = (60 + 5) * 60; //01:05

  //timezone
  //full list of supported timezones could be found here
  //https://www.mkyong.com/java/java-display-list-of-timezone-with-gmt/
  char tz[] = "America/Bogota";

  Blynk.virtualWrite(V6, startAt, stopAt, tz);

  //you may also pass day
  //char days[] = "1"; //Monday
  //Blynk.virtualWrite(V1, startAt, stopAt, tz, days);

  //or days
  //char days[] = "1,2,3"; //Monday, Tuesday, Wednesday
  //Blynk.virtualWrite(V1, startAt, stopAt, tz, days);
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  Serial.print("*");
  //BLYNK_CONNECTED();
}

void loop()
{
  Blynk.run();
  if(Serial.available()>0)
  {
    char in_serial=Serial.read();
    if (in_serial=='t')
    {
      sprintf(tweets,"alerta N%d.temperatura",alert);
      Blynk.tweet(tweets);
      alert=1+alert;
    }
    
  }
  
}