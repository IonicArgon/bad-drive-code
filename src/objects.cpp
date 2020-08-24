#include "objects.h"
#include "globals.h"

// Create necessary objects //
// -- Motors -- //

pros::Motor drvLB {motors::drvLB, motors::cart::E_MOTOR_GEARSET_18, false, motors::enc::E_MOTOR_ENCODER_COUNTS};
pros::Motor drvLM {motors::drvLM, motors::cart::E_MOTOR_GEARSET_18, false, motors::enc::E_MOTOR_ENCODER_COUNTS};
pros::Motor drvLF {motors::drvLF, motors::cart::E_MOTOR_GEARSET_18, false, motors::enc::E_MOTOR_ENCODER_COUNTS};
pros::Motor drvRB {motors::drvRB, motors::cart::E_MOTOR_GEARSET_18, true, motors::enc::E_MOTOR_ENCODER_COUNTS};
pros::Motor drvRM {motors::drvRM, motors::cart::E_MOTOR_GEARSET_18, true, motors::enc::E_MOTOR_ENCODER_COUNTS};
pros::Motor drvRF {motors::drvRF, motors::cart::E_MOTOR_GEARSET_18, true, motors::enc::E_MOTOR_ENCODER_COUNTS};

// -- Others -- //

pros::Motor convyMot    {motors::convyPort, motors::cart::E_MOTOR_GEARSET_06, false, motors::enc::E_MOTOR_ENCODER_COUNTS};
pros::Motor intkMot     {motors::intkPort, motors::cart::E_MOTOR_GEARSET_36, false, motors::enc::E_MOTOR_ENCODER_COUNTS};
pros::Controller ctrl_master {pros::controller_id_e_t::E_CONTROLLER_MASTER};

/*  This helper function is for assigning motor powers because
 *  I can't be damned to copy and paste motor.move() 6 times over.
 *  \param left
 *      Sets the power to the left side motors.
 *  \param right
 *      Sets the power to the right side motors.
 */
auto Set_Powers(int left, int right) -> void
{
    drvLB = left;
    drvLM = left;
    drvLF = left;
    drvRB = right;
    drvRM = right;
    drvRF = right;
}