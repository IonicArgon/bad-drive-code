#include "main.h"
#include "globals.h"
#include "objects.h"

#define DRIVE_ARCADE

auto Comp_Vals_Deadzone(int x) -> int
{
   return ((std::abs(x) >= misc::ctrlDeadzone) ? x : 0);
}

#if defined DRIVE_ARCADE
auto Drive_Ctrl() -> void
{
    while (true)
    {
        int power {Comp_Vals_Deadzone(ctrl_master.get_analog(misc::ctrlAnalog::E_CONTROLLER_ANALOG_RIGHT_Y))}, 
            turn {Comp_Vals_Deadzone(ctrl_master.get_analog(misc::ctrlAnalog::E_CONTROLLER_ANALOG_RIGHT_X))};
        Set_Powers(power + turn, power - turn);
        pros::delay(5);
    }
}

auto Intk_Convy_Ctrl() -> void
{
    while (true)
    {
        int intake_pow{};
        int convy_pow{};

        if (ctrl_master.get_digital(misc::ctrlDigital::E_CONTROLLER_DIGITAL_R2))
            intake_pow = 100;
        else if (ctrl_master.get_analog(misc::ctrlAnalog::E_CONTROLLER_ANALOG_LEFT_Y))
            intake_pow = -100;
        else if (ctrl_master.get_digital(misc::ctrlDigital::E_CONTROLLER_DIGITAL_UP))
            convy_pow = 600;
        else if (ctrl_master.get_digital(misc::ctrlDigital::E_CONTROLLER_DIGITAL_DOWN))
            convy_pow = -600;
        else if (ctrl_master.get_digital(misc::ctrlDigital::E_CONTROLLER_DIGITAL_R1))
        {
            intake_pow = 100;
            convy_pow = 600;
        }
        else if (ctrl_master.get_digital(misc::ctrlDigital::E_CONTROLLER_DIGITAL_LEFT))
        {
            intake_pow = -100;
            convy_pow = -600;
        }
        else
        {
            intake_pow = 0;
            convy_pow = 0;
        }
        Set_Intk_Convy(intake_pow, convy_pow);
    }
}

#elif defined DRIVE_TANK
auto Drive_Ctrl() -> void
{
    while (true)
    {
        int power_left {Comp_Vals_Deadzone(ctrl_master.get_analog(misc::ctrlAnalog::E_CONTROLLER_ANALOG_LEFT_Y))}, 
            power_right {Comp_Vals_Deadzone(ctrl_master.get_analog(misc::ctrlAnalog::E_CONTROLLER_ANALOG_RIGHT_Y))};
        Set_Powers(power_left, power_right);
        pros::delay(5);
    }
}
#endif

void initialize() 
{
    intkMot.set_brake_mode(motors::brk::E_MOTOR_BRAKE_HOLD);
    convyMot.set_brake_mode(motors::brk::E_MOTOR_BRAKE_HOLD);
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
    pros::Task drive_task(Drive_Ctrl, "Drive task");
    pros::Task macro_task(Intk_Convy_Ctrl, "Intake/Convy task");
    // TODO: add conveyor and intake functions and macros.
}
