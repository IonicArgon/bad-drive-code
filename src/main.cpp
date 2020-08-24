#include "main.h"
#include "globals.h"
#include "objects.h"

#define DRIVE_ARCADE

auto Drive_Ctrl() -> void
{
    while (true)
    {
#if defined DRIVE_ARCADE
        int power {
            [](int i)
            {
                if (i >= misc::ctrlDeadzone)
                    return i;
                else
                    return 0;
            }(ctrl_master.get_analog(misc::ctrlAnalog::E_CONTROLLER_ANALOG_RIGHT_Y))
        };

        int turn {
            [](int i)
            {
                if (i >= misc::ctrlDeadzone)
                    return i;
                else
                    return 0;
            }(ctrl_master.get_analog(misc::ctrlAnalog::E_CONTROLLER_ANALOG_RIGHT_X))
        };

        Set_Powers(power + turn, power - turn);

#elif defined DRIVE_TANK
        int power_left {
            [](int i)
            {
                if (i >= misc::ctrlDeadzone)
                    return i;
                else
                    return 0;
            }(ctrl_master.get_analog(misc::ctrlAnalog::E_CONTROLLER_ANALOG_LEFT_Y))
        };

        int power_right {
            [](int i)
            {
                if (i >= misc::ctrlDeadzone)
                    return i;
                else
                    return 0;
            }(ctrl_master.get_analog(misc::ctrlAnalog::E_CONTROLLER_ANALOG_RIGHT_Y))
        };

        Set_Powers(power_left, power_right);
#endif
        pros::delay(5);
    }
}

void initialize() {}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
    pros::Task drive_task(Drive_Ctrl, "Drive task.");
    // TODO: add conveyor and intake functions and macros.
}
