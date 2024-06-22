#include "autos.hpp"
#include "devices.hpp"

ASSET(awp1_txt);

void awp() {
    wingsLeft.set_value(true);
    chassis.setPose(-28.4, -55, 0);

    chassis.turnToPoint(-23, -10, 500, {.minSpeed = 40});
    intake.move(127);
    chassis.waitUntilDone();
    pros::delay(250);
    chassis.moveToPose(-23, -10, 0, 1700, {.minSpeed = 100});
    chassis.waitUntil(16);
    wingsLeft.set_value(false);

    chassis.turnToHeading(0, 800);

    // chassis.moveToPoint(-33, -28, 3000, {.forwards = false});
    chassis.follow(awp1_txt, 10, 4500, false);
    chassis.turnToPoint(-48, -56, 700, {.forwards = false});
    intake.move(0);
    chassis.moveToPose(-46, -56, -45, 2500, {.forwards = false, .minSpeed = 100});
    wingsLeft.set_value(true);

    chassis.turnToHeading(-90, 800, {.minSpeed = 60});
    chassis.waitUntilDone();
    wingsLeft.set_value(false);
    chassis.turnToPoint(-5, -75, 1000);
    intake.move(-127);
    chassis.moveToPoint(-7, -59, 1200);
    chassis.turnToHeading(90, 1000, {.minSpeed = 20});
}
