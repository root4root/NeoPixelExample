#include "main.h"

unsigned long previuosChangeTime = 0;

void brilliantMode(void)
{
    if ((millis() - previuosChangeTime) < BRILLIANT_CHANGE_SPEED) {
        return;
    }

    gradientChangePresenter();

    for (uint16_t i = 0; i < LEDS_COUNT * 3; i += 3) {
        if (randPixels[i] == neoPixelsBuffer[i] && randPixels[i+1] == neoPixelsBuffer[i+1] && randPixels[i+2] == neoPixelsBuffer[i+2]) {
            randomColorByLedNumberGenerator(i/3);
        }
    }

    previuosChangeTime = millis();
}

void sparkyMode(void)
{
    if ((millis() - previuosChangeTime) < SPARKY_CHANGE_SPEED) {
        return;
    }

    plainChangePresenter();

    fillStripWithRandomColorsGenerator();

    previuosChangeTime = millis();
}

void gradientMode(void)
{
    if ((millis() - previuosChangeTime) < GRADIENT_CHANGE_SPEED) {
        return;
    }

    gradientChangePresenter();

    if (randPixels[0] == neoPixelsBuffer[0] && randPixels[1] == neoPixelsBuffer[1] && randPixels[2] == neoPixelsBuffer[2]) {
        fillWholeStripWithOneRandomBasicColorGenerator();
    }

    previuosChangeTime = millis();
}
