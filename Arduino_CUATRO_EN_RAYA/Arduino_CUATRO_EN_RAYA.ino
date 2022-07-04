#include <FastLED.h>

#define DEBUG(a) Serial.println(a);

#define LED_PIN 6
#define NUM_LEDS 35
CRGB leds[NUM_LEDS];

mensaje_recibido=Serial.readStringUntil('\n');

String mensaje_recibido; 

void setup() 
{
 Serial.begin(9600);
 FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
 pinMode(LED_PIN, OUTPUT);

   Serial.begin(9600);
   long value;
   value = mensaje_recibido.toInt();
   DEBUG(value);
}

void loop() 
{
  int i;
  int j=0;

 if(Serial.available()>0)
 {

  for(j=0;j<30;j++)

  {
      switch(mensaje_recibido) 
      {
        case 0:

        if(j%2==0)
        {
              for(i=0;i<6;i++)
              {
                if(leds[i]==CRGB(0,0,0))
                {
                  leds[i]==CRGB(255,0,0);
                  FastLED.show();
                  delay(200);
                }
              }
        }

        else
        {
           for(i=0;i<6;i++)
              {
                if(leds[i]==CRGB(0,0,0))
                {
                  leds[i]==CRGB(255,255,0);
                  FastLED.show();
                  delay(200);
                }
              }
        }
    
        break;
    
        case 1:
        
       if(j%2==0)
        {
              for(i=6;i<12;i++)
              {
                if(leds[i]==CRGB(0,0,0))
                {
                  leds[i]==CRGB(255,0,0);
                  FastLED.show();
                  delay(200);
                }
              }
        }

        else
        {
           for(i=6;i<12;i++)
              {
                if(leds[i]==CRGB(0,0,0))
                {
                  leds[i]==CRGB(255,255,0);
                  FastLED.show();
                  delay(200);
                }
              }
        }
        
        break;
    
        case 2:
        
       if(j%2==0)
        {
              for(i=12;i<24;i++)
              {
                if(leds[i]==CRGB(0,0,0))
                {
                  leds[i]==CRGB(255,0,0);
                  FastLED.show();
                  delay(200);
                }
              }
        }

        else
        {
           for(i=12;i<18;i++)
              {
                if(leds[i]==CRGB(0,0,0))
                {
                  leds[i]==CRGB(255,255,0);
                  FastLED.show();
                  delay(200);
                }
              }
        }
        break;
    
        case 3:
             if(j%2==0)
        {
              for(i=18;i<24;i++)
              {
                if(leds[i]==CRGB(0,0,0))
                {
                  leds[i]==CRGB(255,0,0);
                  FastLED.show();
                  delay(200);
                }
              }
        }

        else
        {
           for(i=18;i<24;i++)
              {
                if(leds[i]==CRGB(0,0,0))
                {
                  leds[i]==CRGB(255,255,0);
                  FastLED.show();
                  delay(200);
                }
              }
        }
        break;
    
        case 4:
        if(j%2==0)
        {
              for(i=24;i<30;i++)
              {
                if(leds[i]==CRGB(0,0,0))
                {
                  leds[i]==CRGB(255,0,0);
                  FastLED.show();
                  delay(200);
                }
              }
        }

        else
        {
           for(i=18;i<30;i++)
              {
                if(leds[i]==CRGB(0,0,0))
                {
                  leds[i]==CRGB(255,255,0);
                  FastLED.show();
                  delay(200);
                }
              }
        }
        break;
    
        case 5:
       if(j%2==0)
        {
              for(i=30;i<36;i++)
              {
                if(leds[i]==CRGB(0,0,0))
                {
                  leds[i]==CRGB(255,0,0);
                  FastLED.show();
                  delay(200);
                }
              }
        }

        else
        {
           for(i=30;i<36;i++)
              {
                if(leds[i]==CRGB(0,0,0))
                {
                  leds[i]==CRGB(255,255,0);
                  FastLED.show();
                  delay(200);
                }
              }
        }
        break;
    
      }
  }
 }

}
