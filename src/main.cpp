#include "main.h"
#include "globals.h"
#include "objects.h"

#define DRIVE_ARCADE

auto Comp_Vals_Deadzone(int x) -> int
{
    if (x >= misc::ctrlDeadzone)
        return x;
    else
        return 0;
}

auto Drive_Ctrl() -> void
{
    while (true)
    {
#if defined DRIVE_ARCADE
        int power {Comp_Vals_Deadzone(ctrl_master.get_analog(misc::ctrlAnalog::E_CONTROLLER_ANALOG_RIGHT_Y))}, 
            turn {Comp_Vals_Deadzone(ctrl_master.get_analog(misc::ctrlAnalog::E_CONTROLLER_ANALOG_RIGHT_X))};
        Set_Powers(power + turn, power - turn);

#elif defined DRIVE_TANK
        int power_left {Comp_Vals_Deadzone(ctrl_master.get_analog(misc::ctrlAnalog::E_CONTROLLER_ANALOG_LEFT_Y))}, 
            power_right {Comp_Vals_Deadzone(ctrl_master.get_analog(misc::ctrlAnalog::E_CONTROLLER_ANALOG_RIGHT_Y))};
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
