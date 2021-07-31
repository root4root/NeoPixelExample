#include "main.h"

void gradientChangePresenter(void)
{
    for (uint16_t i = 0; i < LEDS_COUNT * 3; ++i) {

        if (randPixels[i] < neoPixelsBuffer[i]) {
            --neoPixelsBuffer[i];
        }

        if (randPixels[i] > neoPixelsBuffer[i]) {
            ++neoPixelsBuffer[i];
        }
    }

    pixels.show();

}

void plainChangePresenter(void)
{
    for (uint16_t i = 0; i < LEDS_COUNT * 3; ++i) {
        neoPixelsBuffer[i] = randPixels[i];
    }

    pixels.show();
}
