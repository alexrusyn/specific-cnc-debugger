#ifndef BIT_MATH_H
#define BIT_MATH_H

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)

#define bitSet(value, bit) ((value) |= (1UL << (bit)))

#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))

#define bitToggle(value, bit) ((value) ^= (1UL << (bit)))

#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))

#endif