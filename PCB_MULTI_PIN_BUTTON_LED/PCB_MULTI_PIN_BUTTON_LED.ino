#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

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
int btnTest = A0;
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


  pinMode(btnTest, INPUT_PULLUP);


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
}

int a = 0;
void loop() {




  a = analogRead(btnTest);
  Serial.println(a);

  if (a <= 50) {

    strip1.fill(strip1.Color(0, 255, 0), 0, 6);
    strip1.show();
    tone(10, 2000);
    delay(150);
    noTone(10);
    delay(1500);

    //  colorWipe(strip1, strip1.Color(0, 255, 0), 10);  // Red

  } else if (a >= 100) {
    strip1.fill(strip1.Color(0, 0, 0), 0, 6);
    strip1.show();
    // colorWipe(strip1, strip1.Color(255, 0, 0), 10);
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
