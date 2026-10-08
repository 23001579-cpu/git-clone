#pragma once
#include <Arduino.h>

class LED
{
public:
    LED(const byte pin, const bool active);
    void on();
    void off();
    void flip();
    void blink(unsigned int duration);
    void stopBlink();
    void loop();

private:
    const byte _pin;
    const bool _active;

    unsigned long _timer = 0;
    unsigned int _duration = 0;

    enum States
    {
        OFF,
        ON,
        BLINK,
    } state = OFF;
};

inline LED::LED(const byte pin, const bool active) : _pin(pin), _active(active)
{
    pinMode(_pin, OUTPUT);
    off();
}

inline void LED::on()
{
    digitalWrite(_pin, _active);
    state = ON;
}

inline void LED::off()
{
    digitalWrite(_pin, !_active);
    state = OFF;
}

inline void LED::flip()
{
    if (state == OFF)
        on();
    else
        off();
}

inline void LED::blink(unsigned int duration)
{
    _duration = duration;
    _timer = millis();
    state = BLINK;
}

inline void LED::stopBlink()
{
    if (state == BLINK)
        state = digitalRead(_pin) == _active ? ON : OFF;
}

inline void LED::loop()
{
    if (state == BLINK && millis() - _timer >= _duration)
    {
        digitalWrite(_pin, !digitalRead(_pin));
        _timer = millis();
    }
}
