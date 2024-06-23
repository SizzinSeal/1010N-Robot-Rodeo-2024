#include "autos.hpp"
#include "devices.hpp"
#include "pros/rtos.hpp"

void deployIntake() {
    pros::Task([&] {
        wingsLeft.set_value(true);
        pros::delay(400);
        wingsLeft.set_value(false);
    });
}