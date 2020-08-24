#include "main.h"

#ifndef OBJECTS_H
#define OBJECTS_H

    auto Set_Powers(int left, int right) -> void;

    extern pros::Motor drvLB;
    extern pros::Motor drvLM;
    extern pros::Motor drvLF;
    extern pros::Motor drvRB;
    extern pros::Motor drvRM;
    extern pros::Motor drvRF;
    extern pros::Motor convyMot;
    extern pros::Motor intkMot;
    extern pros::Controller ctrl_master;

#endif