#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>

LED led1(LED1_PIN, LED1_ACT);
LED led2(LED2_PIN, LED2_ACT);
LED *controlledLed = &led1;

void onSingleClick();
void onDoubleClick();
void onLongPressStart();
void onLongPressStop();

OneButton button(BTN_PIN, !BTN_ACT, true);

void setup()
{
    led1.off();
    led2.off();

    button.setPressMs(800);
    button.attachClick(onSingleClick);
    button.attachDoubleClick(onDoubleClick);
    button.attachLongPressStart(onLongPressStart);
    button.attachLongPressStop(onLongPressStop);
}

void loop()
{
    button.tick();
    led1.loop();
    led2.loop();
}

void onSingleClick()
{
    controlledLed->flip();
}

void onDoubleClick()
{
    controlledLed = (controlledLed == &led1) ? &led2 : &led1;
}

void onLongPressStart()
{
    controlledLed->blink(200);
}

void onLongPressStop()
{
    controlledLed->stopBlink();
}
