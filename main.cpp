#include "main.h"

Adafruit_NeoPixel pixels(LEDS_COUNT, OUTPUT_PIN, NEO_GRB + NEO_KHZ800);

uint8_t randPixels[LEDS_COUNT * 3]{};
uint8_t *neoPixelsBuffer{};

static unsigned long previuosChangeTime = 0;
static uint8_t mode = 0;

void setup() {
    //clock_prescale_set(clock_div_2); //avr/power.h

    pixels.begin();
    neoPixelsBuffer = pixels.getPixels();
    fillStripWithRandomColorsGenerator();

}

void loop() {

    if ((millis() - previuosChangeTime) > MODE_CHANGE_SPEED) {

        ++mode;

        if (mode > 3) { mode = 0; }

        previuosChangeTime = millis();
    }

    switch(mode) {
        case 0 :
            sparkyMode();
            break;
        case 1 :
            brilliantMode();
            break;
        case 2 :
            gradientMode();
            break;
        case 3 :
            brilliantMode();
            break;
    }


}
