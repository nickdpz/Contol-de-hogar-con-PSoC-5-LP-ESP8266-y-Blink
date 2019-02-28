/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_MAX_SENDBYTES 256 //alargar el maxiomo del mensaje
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "cbde13b152d3432da53ad5585f9eb550";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "JAPEREZ";
char pass[] = "26071967";
int alert=0;
char tweets[256];
char dato[12];
BLYNK_WRITE(V0) // V5 is the number of Virtual Pin  
{
  int pinValue = param.asInt();
  sprintf(dato,"A%d",pinValue);
  Serial.println(dato);
}
BLYNK_WRITE(V1) // V5 is the number of Virtual Pin  
{
  int pinValue = param.asInt();
  sprintf(dato,"C%d",pinValue);
  Serial.println(dato);
}

BLYNK_WRITE(V2) // V5 is the number of Virtual Pin  
{
  int pinValue = param.asInt();
  sprintf(dato,"B%d",pinValue);
  Serial.println(dato);
}

BLYNK_WRITE(V3) // V5 is the number of Virtual Pin  
{
  int pinValue = param.asInt();
  sprintf(dato,"D%d",pinValue);
  Serial.println(dato);
}

BLYNK_WRITE(V4) // V5 is the number of Virtual Pin  
{
  int pinValue = param.asInt();
  sprintf(dato,"S%d",pinValue);
  Serial.println(dato);
}

BLYNK_WRITE(V5) // V5 is the number of Virtual Pin  
{
  int pinValue = param.asInt();
  sprintf(dato,"H%d",pinValue);
  Serial.println(dato);
}

BLYNK_WRITE(V6) // V5 is the number of Virtual Pin  
{
  int pinValue = param.asInt();
  sprintf(dato,"N%d",pinValue);
  Serial.println(dato);
}

BLYNK_WRITE(V7) // V5 is the number of Virtual Pin  
{
  int pinValue = param.asInt();
  sprintf(dato,"F%d",pinValue);
  Serial.println(dato);
}

BLYNK_WRITE(V8) // V5 is the number of Virtual Pin  
{
  int pinValue = param.asInt();
  sprintf(dato,"M%d",pinValue);
  Serial.println(dato);
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
