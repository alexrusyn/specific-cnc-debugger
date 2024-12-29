#include <Arduino.h>

enum ENCODER_DIRECTION {CW = 1, CCW = 0};

class Encoder
{
private:
  // ENCODER_DIRECTION direction = CW;
  // uint16_t tick = 0;
  // uint8_t angle = 0;

public:
  volatile ENCODER_DIRECTION direction = CW;
  volatile uint8_t tick = 0;
  uint8_t angle = 0;

  Encoder();

  void init();
  void update();
  uint8_t read();
};
