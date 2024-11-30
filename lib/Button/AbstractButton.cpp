#include <AbstractButton.h>

void AbstractButton::attach(Callback handler)
{
  this->cb = handler;
}

void AbstractButton::detach()
{
  this->cb = nullptr;
}

// void AbstractButton::press() {}

// void AbstractButton::release() {}

// void AbstractButton::click() {}

// void AbstractButton::action() {}

void AbstractButton::call()
{
  this->cb();
}

void AbstractButton::dispatch()
{
  this->statuses.get();
  // statuses.set(1 << 0); // set first bit, as watching
}

void AbstractButton::tick(const unsigned long &time)
{
  // if (statuses.read(1 << 0))
  // {
  //   this->call();
  // }

  // if (time - tmr >= 100)
  // {
  //   tmr = time;
  //   this->call();
  // }
}