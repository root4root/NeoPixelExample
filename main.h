#ifndef MAIN_H_
#define MAIN_H_

#include <Arduino.h>
//#include <avr/power.h>

#include <Adafruit_NeoPixel.h>

//SOME CONFIG//
#define OUTPUT_PIN 9
#define LEDS_COUNT 30

#define BRILLIANT_CHANGE_SPEED 30
#define GRADIENT_CHANGE_SPEED 50
#define SPARKY_CHANGE_SPEED 250

#define MODE_CHANGE_SPEED 60000

#define MAX_RED_BRIGHTNESS   128
#define MAX_GREEN_BRIGHTNESS 96
#define MAX_BLUE_BRIGHTNESS  96

//GLOBAL VARS//
extern Adafruit_NeoPixel pixels;
extern uint8_t randPixels[LEDS_COUNT * 3];
extern uint8_t *neoPixelsBuffer;


//GENERATORS//
void fillStripWithRandomColorsGenerator(void);
void randomColorByLedNumberGenerator(const uint16_t);
void fillWholeStripWithOneRandomBasicColorGenerator(void);

//PRESENTERS//
void gradientChangePresenter(void);
void plainChangePresenter(void);

//MODES//
void brilliantMode(void);
void sparkyMode(void);
void gradientMode(void);



#endif /* MAIN_H_ */
