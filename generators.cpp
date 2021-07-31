#include "main.h"

static void filler(uint16_t channel, const uint8_t intensity)
{
    for ( ; channel < LEDS_COUNT * 3; channel += 3) {
        randPixels[channel] = intensity;
    }
}

void fillWholeStripWithOneRandomBasicColorGenerator(void)
{
    uint8_t colorCode = random(1, 7); //001, 010, 011, 100, 101, 110, 111 //GRB

    if (colorCode & 0b001) {
        filler(0, MAX_GREEN_BRIGHTNESS);
    } else {
        filler(0, 0);
    }

    if (colorCode & 0b010) {
        filler(1, MAX_RED_BRIGHTNESS);
    } else {
        filler(1, 0);
    }

    if (colorCode & 0b100) {
        filler(2, MAX_BLUE_BRIGHTNESS);
    } else {
        filler(2, 0);
    }

}

void fillStripWithRandomColorsGenerator(void)
{
    for (uint16_t i = 0; i < LEDS_COUNT; ++i) {
        randomColorByLedNumberGenerator(i);
    }
}

void randomColorByLedNumberGenerator(const uint16_t ledNumber)
{
    uint16_t currentLedColor = ledNumber * 3; //GREEN color

    randPixels[currentLedColor]  =  random(0, MAX_GREEN_BRIGHTNESS) & 0b11100000; //Same as 224, like network mask.
    randPixels[currentLedColor+1] = random(0, MAX_RED_BRIGHTNESS)   & 0b11100000;
    randPixels[currentLedColor+2] = random(0, MAX_BLUE_BRIGHTNESS)  & 0b11100000;

    //avoiding black pixels
    if (randPixels[currentLedColor] == 0 && randPixels[currentLedColor+1] == 0 && randPixels[currentLedColor+2] == 0) {
        randPixels[currentLedColor+1] = MAX_RED_BRIGHTNESS;
    }

    //avoiding "white" pixels
    if (randPixels[currentLedColor] == MAX_RED_BRIGHTNESS && randPixels[currentLedColor+1] == MAX_GREEN_BRIGHTNESS && randPixels[currentLedColor+2] == MAX_BLUE_BRIGHTNESS) {
        randPixels[random(currentLedColor, currentLedColor+2)] = 0;
    }
}
