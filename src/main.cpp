#include <Arduino.h>

#ifdef ARDUINO_AVR_MEGA2560
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
#endif

#ifdef ARDUINO_AVR_NANO
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#endif

void setup()
{
    lcd.init();
    lcd.backlight();

    lcd.setCursor(0, 0);
    lcd.print("Hello world");
}

void loop()
{
}

/*
    1. Encoder driver
        - init
        - read
    2. Configurate two timer (isr)
        - external when encoder read
        - with time
    3. Motor driver
        - init
        - pulse value
    4. Screen
        - log info
        - set mode
    5. Settup debuger mode
        - wait external interrapt
        - on timer with prescaler

 */

// DDRD - Data Direction Register For Port D
// Using for set PORT MODE (OUTPUT or INPUT)

// PORTD - Data Register For Port D
// Using for control whether pin is HIGH or LOW

// PIND - Input Pins Register
// Using for read value
