#include <Encoder.h>

Encoder::Encoder () {};

void Encoder::init()
{
    DDRD |= (1 << PD0);
    PORTD |= (1 << PORTD0) | (1 << PORTD1) | (1 << PORTD2) | (1 << PORTD3);
};

void Encoder::update ()
{
    tick++;
    // direction = static_cast<ENCODER_DIRECTION>(this->read() ? CW : CCW);
};

uint8_t Encoder::read ()
{
    return PIND & (1 << 1);
};
