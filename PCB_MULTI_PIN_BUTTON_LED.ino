
/*************************************************

 * Public Constants

 *************************************************/

#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#include <ArduinoJson.h>
int LEDPINs[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
int BTNPINs[] = { A0, A1, A2, A3, A4, A5, A6, A7 };
int countOfLeds = 6;

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(countOfLeds, LEDPINs[0], NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(countOfLeds, LEDPINs[1], NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(countOfLeds, LEDPINs[2], NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(countOfLeds, LEDPINs[3], NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel strip5 = Adafruit_NeoPixel(countOfLeds, LEDPINs[4], NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel strip6 = Adafruit_NeoPixel(countOfLeds, LEDPINs[5], NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel strip7 = Adafruit_NeoPixel(countOfLeds, LEDPINs[6], NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel strip8 = Adafruit_NeoPixel(countOfLeds, LEDPINs[7], NEO_GRBW + NEO_KHZ800);

Adafruit_NeoPixel stripPanel = Adafruit_NeoPixel(25, 11, NEO_GRBW + NEO_KHZ800);
int btnTest = A1;
int Brightness = 50;
void setup() {
  Serial.begin(9600);



  tone(10, 1500);
  delay(100);
  noTone(10);
// This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined(__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code


  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);


  strip1.begin();
  strip1.setBrightness(Brightness);
  strip1.show();

  strip2.begin();
  strip2.setBrightness(Brightness);
  strip2.show();

  strip3.begin();
  strip3.setBrightness(Brightness);
  strip3.show();

  strip4.begin();
  strip4.setBrightness(Brightness);
  strip4.show();

  strip5.begin();
  strip5.setBrightness(Brightness);
  strip5.show();

  strip6.begin();
  strip6.setBrightness(Brightness);
  strip6.show();

  strip7.begin();
  strip7.setBrightness(Brightness);
  strip7.show();

  strip8.begin();
  strip8.setBrightness(Brightness);
  strip8.show();

  stripPanel.begin();
  stripPanel.setBrightness(Brightness);
  stripPanel.show();
}

void TurnOnLed(Adafruit_NeoPixel strip, uint32_t c) {
  strip.fill(c, 0, 6);
  strip.show();
  tone(10, 2000);
  delay(150);
  noTone(10);
  TurnPanelOn(strip2.Color(0, 255, 0));

  delay(1500);
  TurnOffLed(strip1);
}
void TurnOffLed(Adafruit_NeoPixel strip) {
  /*
  strip.fill(strip.Color(0, 0, 0), 0, 6);
  strip.show();
  */
  TurnPanelOff();
}

void TurnPanelOn(uint32_t c) {
  /*
  for (uint16_t i = 0; i < stripPanel.numPixels(); i++) {
    stripPanel.setPixelColor(i, c);
    stripPanel.show();
    delay(10);
  }
  */
  stripPanel.fill(c, 0, 25);
  stripPanel.show();
}

void TurnPanelOff() {
  stripPanel.fill(strip1.Color(0, 0, 0), 0, 25);
  stripPanel.show();
}
StaticJsonDocument<200> doc;

int melody[] = {

  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {

  4, 8, 8, 4, 4, 4, 4, 4
};

int beep_pin = 10;

void zap1()
{
    for (float f=3000;f>40;f=f*0.93){
    tone(beep_pin,f);
    delay(10);
  }
}

void zap2()
{
    for (float f=3000;f>10;f=f*0.85){
    tone(beep_pin,2*f);
    delay(5);
    tone(beep_pin,f);
    delay(5); 
  }
}

void risefall()
{
  float rise_fall_time=180;
  int steps=50;
  float f_max=2600;
  float f_min=1000;
  float delay_time=rise_fall_time/steps;
  float step_size=(f_max-f_min)/steps;
  for (float f =f_min;f<f_max;f+=step_size){
    tone(beep_pin,f);
    delay(delay_time);
  }
   for (float f =f_max;f>f_min;f-=step_size){
    tone(beep_pin,f);
    delay(delay_time);
  }
}

void fall(float rise_fall_time)
{
  int steps=50;
  float f_max=2000;
  float f_min=500;
  float delay_time=rise_fall_time/steps;
  float step_size=0.97;
  for (float f =f_max;f>f_min;f*=step_size){
    tone(beep_pin,f);
    delay(delay_time);
  }
}

void rise()
{
  float rise_fall_time=2000;
  int steps=100;
  float f_max=1500;
  float f_min=500;
  float delay_time=rise_fall_time/steps;
  float step_size=1.012;
  for (float f =f_min;f<f_max;f*=step_size){
    tone(beep_pin,f);
    delay(delay_time);
  }
  noTone(beep_pin);
  delay(100);
  
}

void twotone()
{
  float f_max=1500;
  float f_min=1000;
  float delay_time=800;
  tone(beep_pin,f_max);
  delay(delay_time);
  tone(beep_pin,f_min);
  delay(delay_time);
  
}

void runTone(int btn) {
  switch (btn) {
    case 14:

 twotone();

      //tone(10, 1500);
      break;
    case 15:

      zap1();

      // tone(10, 1700);
      break;
    case 16:
   zap2();
    //  tone(10, 1900);
      break;
    case 17:
   risefall();
      break;
    case 18:
fall(300);
      break;
      break;
    case 19:
 rise();
      break;
    default:
      tone(10, 2700);
  }
  JsonArray data = doc.createNestedArray("data");
  data.add(btn);
  serializeJson(doc, Serial);
  Serial.println();
  delay(150);
  noTone(10);
}
void offAllLed() {
  stripPanel.fill(strip1.Color(0, 0, 0), 0, 25);
  stripPanel.show();

  strip1.fill(strip1.Color(0, 0, 0), 0, 6);
  strip1.show();

  strip2.fill(strip1.Color(0, 0, 0), 0, 6);
  strip2.show();

  strip3.fill(strip1.Color(0, 0, 0), 0, 6);
  strip3.show();

  strip4.fill(strip1.Color(0, 0, 0), 0, 6);
  strip4.show();

  strip5.fill(strip1.Color(0, 0, 0), 0, 6);
  strip5.show();

  strip6.fill(strip1.Color(0, 0, 0), 0, 6);
  strip6.show();
}
int a = 0;

void loop_json() {
  JsonArray data = doc.createNestedArray("data");
  if (digitalRead(14) == LOW) {
    offAllLed();


    data.add(14);
    serializeJson(doc, Serial);
    Serial.println();
  }

  if (digitalRead(15) == LOW) {
    offAllLed();


    data.add(15);
    serializeJson(doc, Serial);
    Serial.println();
  }
}

int btn1 = 14, btn2 = 15, btn3 = 16, btn4 = 17, btn5 = 18, btn6 = 19;

void loop() {


  if (digitalRead(btn1) == LOW) {
    offAllLed();

    strip1.fill(strip1.Color(0, 255, 0), 0, 6);
    strip1.show();
    runTone(btn1);
    TurnPanelOn(strip1.Color(0, 255, 0));
    delay(1500);
  } else {
    strip1.fill(strip1.Color(0, 0, 0), 0, 6);
    strip1.show();
    TurnPanelOff();
  }



  if (digitalRead(btn2) == LOW) {
    offAllLed();
    strip2.fill(strip2.Color(255, 0, 0), 0, 6);
    strip2.show();
    runTone(btn2);
    TurnPanelOn(strip2.Color(255, 0, 0));
    delay(1500);

  } else {
    strip2.fill(strip2.Color(0, 0, 0), 0, 6);
    strip2.show();
    TurnPanelOff();
  }


  if (digitalRead(btn3) == LOW) {
    offAllLed();
    strip3.fill(strip3.Color(0, 0, 255), 0, 6);
    strip3.show();
    runTone(btn3);
    TurnPanelOn(strip3.Color(0, 0, 255));
    delay(1500);

  } else {
    strip3.fill(strip3.Color(0, 0, 0), 0, 6);
    strip3.show();
    TurnPanelOff();
  }



  if (digitalRead(btn4) == LOW) {
    offAllLed();
    strip4.fill(strip4.Color(0, 255, 255), 0, 6);
    strip4.show();
    runTone(btn4);
    TurnPanelOn(strip4.Color(0, 255, 255));
    delay(1500);

  } else {
    strip4.fill(strip4.Color(0, 0, 0), 0, 6);
    strip4.show();
    TurnPanelOff();
  }

  if (digitalRead(btn5) == LOW) {
    offAllLed();
    strip5.fill(strip5.Color(255, 0, 255), 0, 6);
    strip5.show();
    runTone(btn5);
    TurnPanelOn(strip5.Color(255, 0, 255));
    delay(1500);

  } else {
    strip5.fill(strip5.Color(0, 0, 0), 0, 6);
    strip5.show();
    TurnPanelOff();
  }

  if (digitalRead(btn6) == LOW) {
    offAllLed();
    strip6.fill(strip6.Color(255, 255, 255), 0, 6);
    strip6.show();
    runTone(btn6);
    TurnPanelOn(strip6.Color(255, 255, 255));
    delay(1500);

  } else {
    strip6.fill(strip6.Color(0, 0, 0), 0, 6);
    strip6.show();
    TurnPanelOff();
  }

  /*
  // Some example procedures showing how to display to the pixels:
  colorWipe(strip1, strip1.Color(255, 0, 0), 10); // Red
  colorWipe(strip2, strip2.Color(0, 255, 0), 25); // Green
  colorWipe(strip3, strip3.Color(0, 0, 255), 10); // Blue
  colorWipe(strip4, strip4.Color(0, 0, 0, 255), 20); // White RGBW

    colorWipe(strip5, strip5.Color(255, 0, 0), 10); // Red
  colorWipe(strip6 ,strip6.Color(0, 255, 0), 25); // Green
  colorWipe(strip7, strip7.Color(0, 0, 255), 10); // Blue
  colorWipe(strip8, strip8.Color(0, 0, 0, 255), 20); // White RGBW
*/
  // Send a theater pixel chase in...
  /*
  theaterChase(strip.Color(127, 127, 127), 50); // White
  theaterChase(strip.Color(127, 0, 0), 50); // Red
  theaterChase(strip.Color(0, 0, 127), 50); // Blue

  rainbow(20);
  rainbowCycle(20);
  theaterChaseRainbow(50);
  */
}

// Fill the dots one after the other with a color
void colorWipe(Adafruit_NeoPixel strip, uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
