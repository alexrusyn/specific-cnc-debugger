// -- Resistive keyboard
//
// An: Analog input
// BTN-1 to BTN-7: Buttons (switches)
// Resistors: pull-up resistor (2kΩ or 10kΩ) ((depends on the number of buttons, a larger
// one is used with a larger number of buttons))) and current-limiting resistors (1kΩ or 2.2kΩ, ..., 4.7kΩ)
// GND: Ground
//
// --- Serial connection
//
// +5V --- [2kΩ] --- + --- An
//                    |
//                    + --- [1kΩ]---[1kΩ]---[1kΩ]---[1kΩ]
//                    |       |       |       |       |
//                  BTN-1   BTN-2   BTN-3   BTN-4   BTN-5
//                    |       |       |       |       |
// GND ------------------------------------------------
//
// --- Parallel connection
//
// +5V --- [10kΩ] --- +  ---  +  ---  +  ---  +  ---  + --- An
//                    |       |       |       |       |
//                    |     [1kΩ]  [2.2kΩ] [3.3kΩ] [4.7kΩ]
//                    |       |       |       |       |
//                  BTN-1   BTN-2   BTN-3   BTN-4   BTN-5
//                    |       |       |       |       |
// GND ------------------------------------------------
//

enum KEYBOARD_CONNECTION
{
    SERIAL,
    // PARALLEL
};