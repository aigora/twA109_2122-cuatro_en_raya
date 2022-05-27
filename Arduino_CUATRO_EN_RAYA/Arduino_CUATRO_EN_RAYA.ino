#include <FastLED.h>
#define LED_PIN 6
#define NUM_LEDS 36
CRGB leds[NUM_LEDS];

int mensaje_recibido; 

void setup() {
 Serial.begin(9600);
 FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
 pinMode(LED_PIN, OUTPUT);
}

void loop() {

 if(Serial.available()>0){
  mensaje_recibido=Serial.readStringUntil('\n');
  switch(mensaje_recibido)
  {
    case 0:
    if(leds[0]=CRGB(255,0,0)||leds[0]=CRGB(255,255,0))
    {
      leds[1]=CRGB(255,0,0);
      FastLED.show();
    }else{
      leds[0]=CRGB(255,0,0);
    FastLED.show();
    delay(200);
    }
    break;

    case 1:
    if(leds[6]=CRGB(255,0,0)||leds[6]=CRGB(255,255,0))
    {
      leds[7]=CRGB(255,0,0);
      FastLED.show();
    }else{
      leds[6]=CRGB(255,0,0);
    FastLED.show();
    delay(200);
    }
    break;

    case 2:
    if(leds[12]=CRGB(255,0,0)||leds[12]=CRGB(255,255,0))
    {
      leds[13]=CRGB(255,0,0);
      FastLED.show();
    }else{
      leds[12]=CRGB(255,0,0);
    FastLED.show();
    delay(200);
    }
    break;

    case 3:
    if(leds[18]=CRGB(255,0,0)||leds[18]=CRGB(255,255,0))
    {
      leds[19]=CRGB(255,0,0);
      FastLED.show();
    }else{
      leds[18]=CRGB(255,0,0);
    FastLED.show();
    delay(200);
    }
    break;

    case 4:
    if(leds[24]=CRGB(255,0,0)||leds[24]=CRGB(255,255,0))
    {
      leds[25]=CRGB(255,0,0);
      FastLED.show();
    }else{
      leds[24]=CRGB(255,0,0);
    FastLED.show();
    delay(200);
    }
    break;

    case 5:
    if(leds[30]=CRGB(255,0,0)||leds[30]=CRGB(255,255,0))
    {
      leds[31]=CRGB(255,0,0);
      FastLED.show();
    }else{
      leds[30]=CRGB(255,0,0);
    FastLED.show();
    delay(200);
    }
    break;

  }
 
 }
 
}
