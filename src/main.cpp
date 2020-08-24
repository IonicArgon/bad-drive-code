#include "main.h"
#include "globals.h"
#include "objects.h"

#define DRIVE_ARCADE

auto Compare_Vals(int x, int y) -> int
{
    if (x >= y)
        return x;
    else
        return 0;
}

auto Drive_Ctrl() -> void
{
    while (true)
    {
#if defined DRIVE_ARCADE
        int power {Compare_Vals(ctrl_master.get_analog(misc::ctrlAnalog::E_CONTROLLER_ANALOG_RIGHT_Y))}, 
            turn {Compare_Vals(ctrl_master.get_analog(misc::ctrlAnalog::E_CONTROLLER_ANALOG_RIGHT_X))};
        Set_Powers(power + turn, power - turn);

#elif defined DRIVE_TANK
        int power_left {Compare_Vals(ctrl_master.get_analog(misc::ctrlAnalog::E_CONTROLLER_ANALOG_LEFT_Y))}, 
            power_right {Compare_Vals(ctrl_master.get_analog(misc::ctrlAnalog::E_CONTROLLER_ANALOG_RIGHT_Y))};
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
