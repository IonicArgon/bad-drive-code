#include "main.h"

#ifndef GLOBALS_H
#define GLOBALS_H

namespace misc
{
    // Type alias for analog controller button enums.
    using ctrlAnalog = pros::controller_analog_e_t;
    // Type alias for digital controller button enums.
    using ctrlDigital = pros::controller_digital_e_t;

    // Controller deadzone constant.
    inline constexpr int ctrlDeadzone{2};

    // TODO: Add other constants that might be needed later.
}

namespace motors
{
    // Type alias for motor encoder enums.
    using enc = pros::motor_encoder_units_e;
    // Type alias for motor cartridge enums.
    using cart = pros::motor_gearset_e;

    // Drive motor, left side, rear.
    inline constexpr int drvLB{18};
    // Drive motor, left side, middle.
    inline constexpr int drvLM{19};
    // Drive motor, left side, front.
    inline constexpr int drvLF{20};
    // Drive motor, right side, rear.
    inline constexpr int drvRB{8};
    // Drive motor, right side, middle.
    inline constexpr int drvRM{9};
    // Drive motor, right side, front.
    inline constexpr int drvRF{10};

    // Conveyor motor
    inline constexpr int convyPort{2};
    // Intake motor
    inline constexpr int intkPort{1};
}

#endif