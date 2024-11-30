#include <Arduino.h>

// #ifdef ARDUINO_AVR_MEGA2560
// #include <LiquidCrystal.h>
// LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
// #endif

#ifdef ARDUINO_AVR_NANO
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#endif

#include "utils/Debounce.h"
// #include "utils/Time.h"

#include <AbstractButton.h>
// #include <Flags.h>

// --- test
// #include <Servo.h>
// Servo myservo;

AbstractButton button1;

void setup()
{
    lcd.init();
    lcd.backlight();

    button1.attach([]()
                   {
        lcd.setCursor(0, 1);
        lcd.print("            ");
        lcd.setCursor(0, 1);
        lcd.print("Abstract btn"); });

    // myservo.attach(9, 600, 2300);

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

    DDRC &= ~(1 << PC0);     // input A0
    PORTC &= ~(1 << PORTC0); // low A0

    DDRB |= (1 << PB1); // output D9

    cli();

    // use INT 1
    EICRA = (EICRA & ~((1 << ISC10) | (1 << ISC11))) | (3 << ISC10); // CHANGE = 1; FALLING = 2; RISING = 3
    EIMSK |= (1 << INT1);

    sei();
}

volatile uint16_t testNumber1 = 0;
volatile uint16_t testNumber2 = 0;

// --- test
void digitalWriteFast(uint8_t pin, uint8_t x)
{
    if (pin / 8)
    {
        PORTB ^= (-x ^ PORTB) & (1 << (pin % 8));
    }
    else
    {
        PORTD ^= (-x ^ PORTD) & (1 << (pin % 8));
    }
}
// --- test

unsigned int tickCount = 0;
unsigned int lastTickCount = 0;

unsigned int counter = 0;

unsigned long tmr = 0;

// void callWithTimeout(void (*cb)(), const unsigned int period)
// {
//     if (millis() - tmr >= period)
//     {
//         tmr = millis();
//         cb();
//     }
// }

void loop()
{
    button1.tick(millis());

    if (analogRead(0) == LOW)
    {
        button1.dispatch();
    }

    // callWithTimeout([]()
    //                 {
    //     lcd.setCursor(8, 0);
    //     lcd.print("    ");
    //     lcd.setCursor(8, 0);
    //     lcd.print(counter++); }, 1000);

    // lcd.setCursor(8, 1);
    // lcd.print("        ");
    // lcd.setCursor(8, 1);

    // 1. need button class with press, click and hold implementation
    // 2. need write custom class for controll a servo
    //  - set absolute angle (move to the position, e.x. set 180 = move to virtual pos 180deg)
    //  - set relative angle (move on set angle, e.x. set 180 = move on 180deg right side)

    // if (analogRead(0) < 50)
    // {
    //     lcd.print("BTN 1");

    //     counter = 0;

    //     // digitalWriteFast(9, 1);
    //     // delay(1000);
    //     // digitalWriteFast(9, 0);
    //     // delayMicroseconds(1000 - 900);
    // }
    // else if (analogRead(0) <= 360)
    // {
    //     lcd.print("BTN 2");
    // }
    // else if (analogRead(0) <= 538)
    // {
    //     lcd.print("BTN 3");
    // }
    // else if (analogRead(0) <= 646)
    // {
    //     lcd.print("BTN 4");
    // }
    // else if (analogRead(0) <= 717)
    // {
    //     lcd.print("BTN 5");
    // }

    // lcd.setCursor(0, 0);
    // lcd.print("      ");
    // lcd.setCursor(0, 0);
    // lcd.print(testNumber1);

    // lcd.setCursor(0, 1);
    // lcd.print("      ");
    // lcd.setCursor(0, 0);
    // lcd.print(PINB & B00000010);
}

ISR(INT1_vect)
{
    isr_debounce(millis(), []()
                 { testNumber1++; });
}

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

//  */

// // DDRD - Data Direction Register For Port D
// // Using for set PORT MODE (OUTPUT or INPUT)
// // 0 = INPUT | 1 = OUTPUT

// // PORTD - Data Register For Port D
// // Using for control whether pin is HIGH or LOW
// // 0 = LOW | 1 = HIGH

// // PIND - Input Pins Register
// // Using for read value

// --- use default function just for check if interrup work

// volatile int counter = 0;

// void btnIsr()
// {
//     isr_debounce(millis(), []()
//                  { counter++; }, 100);
// }

// void setup()
// {
//     lcd.init();
//     lcd.backlight();

//     pinMode(2, INPUT);
//     digitalWrite(2, LOW);
//     attachInterrupt(0, btnIsr, RISING);
// }

// void loop()
// {
//     lcd.setCursor(0, 0);
//     lcd.print("      ");
//     lcd.setCursor(0, 0);
//     lcd.print(counter);

//     lcd.setCursor(0, 1);
//     lcd.print("      ");
//     lcd.setCursor(0, 1);
//     lcd.print(digitalRead(2));

//     lcd.setCursor(8, 0);
//     lcd.print("      ");
//     lcd.setCursor(8, 0);
//     lcd.print(millis());
// }