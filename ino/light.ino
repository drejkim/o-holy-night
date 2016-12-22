#include "neopixel.h" // use for local build

// IMPORTANT: Set pixel PIN, COUNT, and TYPE
// Supported pixel types: WS2812, WS2812B, WS2812B2, WS2811, TM1803, TM1829, SK6812RGBW
#define PIXEL_PIN D2
#define PIXEL_COUNT 7
#define PIXEL_TYPE SK6812RGBW

#define BRIGHTNESS 255 // 0 - 255

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

uint16_t mangerPixel = 3;
uint16_t starPixel = 5;

uint16_t skyPixels[] = {0, 1, 2};
int numSkyPixels = 3;

// All colors are in GRBW format
uint32_t colorBlue = strip.Color(0, 0, 255, 0);
uint32_t colorOrange = strip.Color(147, 255, 41, 0);
uint32_t colorHalogen = strip.Color(241, 255, 224, 0);
uint32_t colorNone = strip.Color(0, 0, 0, 0);

void setup() {
  Serial.begin(9600);

  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  Particle.function("manger", funcManger);
  Particle.function("star", funcStar);
  Particle.function("sky", funcSky);
}

int funcManger(String state) {
  return setLightState(mangerPixel, colorOrange, state);
}

int funcStar(String state) {
  return setLightState(starPixel, colorHalogen, state);
}

int funcSky(String state) {
  return setLightsState(skyPixels, numSkyPixels, colorBlue, state);
}

int setLightState(uint16_t pixel, uint32_t color, String state) {
  if(state == "on") {
    strip.setPixelColor(pixel, color);
    strip.show();

    return 1;
  }
  else if(state == "off") {
    strip.setPixelColor(pixel, colorNone);
    strip.show();

    return 0;
  }
  else if(state == "pulse") {
    pulseLight(pixel, color);

    return 2;
  }
  else {
    return -1;
  }
}

int setLightsState(uint16_t pixels[], int numPixels, uint32_t color, String state) {
  if(state == "on") {
    setLights(pixels, numPixels, color);
    strip.show();

    return 1;
  }
  else if(state == "off") {
    setLights(pixels, numPixels, colorNone);
    strip.show();

    return 0;
  }
  else if(state == "pulse") {
    pulseLights(pixels, numPixels, color);

    return 2;
  }
  else {
    return -1;
  }
}

void setLights(uint16_t pixels[], int numPixels, uint32_t color) {
  for(int i = 0; i < numPixels; i++) {
    strip.setPixelColor(pixels[i], color);
  }
}

void pulseLight(uint16_t pixel, uint32_t color) {
  setPixelBrightness(pixel, color, 150);
  strip.show();

  delay(300);

  setPixelBrightness(pixel, color, BRIGHTNESS);
  strip.show();
}

void pulseLights(uint16_t pixels[], int numPixels, uint32_t color) {
  for(int i = 0; i < numPixels; i++) {
    setPixelBrightness(pixels[i], color, 150);
  }
  strip.show();

  delay(300);

  for(int i = 0; i < numPixels; i++) {
    setPixelBrightness(pixels[i], color, BRIGHTNESS);
  }
  strip.show();
}

void setPixelBrightness(uint16_t pixel, uint32_t color, int brightness) {
  uint8_t r = Red(color);
  uint8_t g = Green(color);
  uint8_t b = Blue(color);
  uint8_t w = White(color);

  // GRBW
  strip.setPixelColor(pixel, strip.Color(
    (g * brightness / 255),
    (r * brightness / 255),
    (b * brightness / 255),
    (w * brightness / 255)
  ));
}

/* Helper functions for returning the RGBW components of a 32-bit color
 * Note: It appears the order of bytes is WGRB in packed 32-bit form....
 *
 */

uint8_t Red(uint32_t color) {
  return (color >> 8) & 0xFF;
}

uint8_t Green(uint32_t color) {
  return (color >> 16) & 0xFF;
}

uint8_t Blue(uint32_t color) {
  return color & 0xFF;
}

uint8_t White(uint32_t color) {
  return (color >> 24) & 0xFF;
}
