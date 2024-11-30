#include <Flags.h>

#ifndef ABSTRACT_BUTTON_H
#define ABSTRACT_BUTTON_H

typedef void (*Callback)();

class AbstractButton
{
public:
    void attach(Callback handler);
    void detach();

    // bool press();
    // bool release();

    // bool click();

    void dispatch();

    void call();

    void tick(const unsigned long &);

protected:
    Flags<unsigned short> statuses;
    unsigned short tmr = 0;
    Callback cb;
};

#endif