// // ***** Encoder *****
// #define ENC_TICK (ENC_LINE_PER_REV * 2) // Рабочее кол-во импульсов
// // #define EncoderPort                  PORTD                    // Порт "D", сконфигурирован как вход
// #define Encoder_Init() \
//   DDRD = B00000000;    \
//   PORTD = B00001111 // подтяжка PIN_21, 20, 19, 18 // желательна внешняя подтяжка к +5 через 1К резисторы
// #define Enc_Read (PIND & B00000010)

#include <Arduino.h>

#ifdef ARDUINO_AVR_MEGA2560
#define DIRECTION_PORT DDRD;
#define MODE_PORT PORTD;
#define READ_PIN PIND;

#define INT_0_PORT PORTD0;
#endif

#ifdef ARDUINO_AVR_NANO
#define DIRECTION_PORT DDRD;
#define MODE_PORT PORTD;
#define READ_PIN PIND;

#define INT_0_PORT PORTD2;
#endif

class Encoder
{
private:
  uint32_t encTick = 0;

public:
  Encoder(uint32_t);
  uint8_t read(uint8_t);
};

Encoder::Encoder(uint32_t encTick) : encTick{encTick} {
                                       // DIRECTION_PORT = 0;
                                       // MODE_PORT = B00001111;
                                     };

uint8_t Encoder::read(uint8_t offset)
{
  uint8_t mask = (1 << offset);

  return (PIND & mask);
};
