#include <Arduino.h>

#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

#include "utils/Debounce.h"
// #include "utils/Time.h"

#include <Encoder.h>

Encoder enc;

void setup()
{
    lcd.begin(16, 2);

    enc.init();

    // Limit button
    DDRC &= ~(1 << PC6) | ~(1 << PC4); // input
    PORTC &= ~(1 << PORTC6) | ~(1 << PORTC4); // left and right limit button

    // Motor init
    /// Motor X
    // DDRL |= (1 << PL1) | (1 << PL3) | (1 << PL5);
    // Enable x motor
    // PORTL |= (1 << PORTL5) | (1 << PORTL3);

    /// Motor Z
    DDRL |= (1 << PL0) | (1 << PL4) | (1 << PL7);
    // Enable x motor and set CCW
    PORTL |= (1 << PORTL4) | (1 << PORT7);

    // Tachometer
    // DDRL |= (1 << PL6);

    // encoder init
    // DDRD |= B00000000;
    // PORTD |= (1 << PORTD0) | (1 << PORTD1) | (1 << PORTD2) | (1 << PORTD3);

    // reset
    // TCCR0A = 0;
    // TCCR0B = 0;
    // TCNT0 = 0; // timer start value

    // OCR0A = 62500; // 1000 ms time delay; prescaler 256
    // OCR0B = 255;   // 4.08 ms time delay; prescaler 256

    // TCCR0A |= (1 << WGM01); // turn on CTC mode
    // TCCR0A = B10100010; // turn on comparing

    // TCCR0B |= (1 << CS00); // prescaler 0
    // TCCR0B |= (1 << CS12); // prescaler 256
    // TCCR0B |= (1 << CS12) | (1 << CS10); // prescaler 1024
    // TCCR0B |= (1 << CS02) | (1 << CS01) | (1 << CS00); // external interup

    // TIMSK0 |= (1 << TOIE0);
    // TIMSK0 |= (1 << OCIE0A) | (1 << OCIE0B); // enable timer compare interrupt

    // DDRC &= ~(1 << PC0);     // input A0
    // PORTC &= ~(1 << PORTC0); // low A0

    cli();

    // use INT 0 and INT 1
    EICRA |= (1 << ISC10) | (1 << ISC00); // CHANGE
    EIMSK |= (1 << INT0); // | (1 << INT1)


    sei();
}

// volatile uint16_t angle = 0;

// volatile uint8_t direction = 0;
volatile uint16_t encoderTicks = 0;
// volatile uint16_t[3]

// void callWithTimeout(void (*cb)(), const unsigned int period)
// {
//     if (millis() - tmr >= period)
//     {
//         tmr = millis();
//         cb();
//     }
// }

// volatile uint16_t pd0Count = 0;
// volatile uint16_t pd1Count = 0;

// void MotorXEnable () {
//     PORTL |= (1 << PORTL5);
// }

// void MotorXCCW () {
//     PORTL |= (1 << PORTL3);
// }

// void MotorXCW () {
//     PORTL &= ~(1 << PORTL3);
// }

void TachoPulse () {
    PORTL |= (1 << PORTL6);
}

void TachoRemovePulse () {
    PORTL &= ~(1 << PORTL6);
}

// ---

void MotorZRemovePulse () {
    PORTL |= (1 << PORTL0);
}

void MotorZPulse () {
    PORTL &= ~(1 << PORTL0);
}

void MotorZInvertedPulse () {
    PORTL ^= ~(1 << PORTL0);
}


void loop()
{
    // if (!(PINC & B00010000)) {
    //     PORTL &= ~(1 << PORTL4);
    // } else {
    //     PORTL |= (1 << PORTL4); 
    // }

    // if (!(PINC & B01000000)) {
    //     lcd.clear();
    //     angle = 0;
    //     pd0Count = 0;
    //     pd1Count = 0;
    // }

    
    // debounce(millis(), [](){
    //     lcd.setCursor(12, 0);
    //     lcd.print("    ");
    // });
    // lcd.setCursor(12, 0);
    // lcd.print(enc.angle);

    // lcd.setCursor(8, 1);
    // lcd.print("     ");
    // lcd.setCursor(8, 1);
    // if (enc.direction) {
    //     lcd.print("CW");
    // } else {
    //     lcd.print("CCW");
    // }
    

    // lcd.setCursor(0, 0);
    // lcd.print("PD0");
    // lcd.setCursor(4, 0);
    // lcd.print(pd0Count);

    lcd.setCursor(0, 0);
    // lcd.print(enc.tick);

    lcd.setCursor(8, 0);
    lcd.print(encoderTicks);

    
    lcd.setCursor(0, 1);
    lcd.print(PIND & (1 << 0));


    // lcd.setCursor(0, 1);
    // lcd.print("PD1");
    // lcd.setCursor(4, 1);
    // lcd.print(pd1Count);


    // lcd.setCursor(8, 1);
    // lcd.print("   ");
    // lcd.setCursor(8, 1);
    // if (PIND & B00000010) {
    //     lcd.print();
    // } else {

    // }


    // lcd.setCursor(2, 1);
    // lcd.print("PD1");
    // lcd.setCursor(5, 1);
    // lcd.print(PIND & B00000010);

    // lcd.setCursor(8, 1);
    // lcd.print("PL2");
    // lcd.setCursor(11, 1);
    // lcd.print(PINL & B00000100);

    // lcd.setCursor(8, 0);
    // lcd.print(millis());

    // debounce(millis(), [](){
    //     lcd.setCursor(2, 1);
    //     lcd.print("   ");
    //     lcd.setCursor(2, 1);
    //     if (PIND & B00000010) {
    //         lcd.print("CCW");
    //     } else {
    //         lcd.print("CW");
    //     }
    // }, 100);



    // 1. need button class with press, click and hold implementation
    // 2. need write custom class for controll a servo
    //  - set absolute angle (move to the position, e.x. set 180 = move to virtual pos 180deg)
    //  - set relative angle (move on set angle, e.x. set 180 = move on 180deg right side)
}

// 675

ISR(INT0_vect)
{
    // MotorZRemovePulse();
    // TachoRemovePulse();

    // if (++encoderTicks == 675) {
    //     encoderTicks = 0;
    //     TachoPulse();
    // }

    encoderTicks++;
    // enc.update();

    // if (PIND & B00000010) {
    //     direction = 1;
    //     PORTL &= ~(1 << PORTL7); // motor direction
    // } else {
    //     direction = 0;
    //     PORTL |= (1 << PORTL7); // motor direction
    // }

    // pd0Count += direction ? 1 : -1;
    // if (pd0Count < 0) {
    //     pd0Count = 2700;
    // }

    // if (pd0Count > 2700) {
    //     pd0Count = 0;
    // }

    // angle = pd0Count % 2700;

    // MotorZPulse();
}

// ISR(INT1_vect)
// {
//     pd1Count++;
// }

// ISR(TIMER1_COMPB_vect)
// {
//     isr_debounce(millis(), []()
//                  { testNumber2++; });
// }

// /*
// -   1. Encoder driver
//         - init
//         - read
// +   2. Configurate two timer (isr)
//         - external when encoder read
//         - with time
// -   3. Motor driver
//         - init
//         - pulse value
// -   4. Screen
//         - log info
//         - set mode
