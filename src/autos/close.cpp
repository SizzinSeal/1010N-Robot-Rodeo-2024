#include "autos.hpp"
#include "devices.hpp"

ASSET(closeSide1_txt);

void close() {
    wingsLeft.set_value(true);
    chassis.setPose(-28.4, -55, 0);

    chassis.turnToPoint(-24, -12, 500, {.minSpeed = 80});
    intake.move(127);
    chassis.waitUntilDone();
    pros::delay(250);
    chassis.moveToPose(-24, -11, 0, 1500, {.minSpeed = 100});
    chassis.waitUntil(16);
    wingsLeft.set_value(false);

    chassis.turnToHeading(10, 800);
    chassis.moveToPoint(-42, -45, 2000, {.forwards = false, .minSpeed = 100});
    chassis.turnToHeading(90, 700);
    intake.move(-127);
    chassis.turnToPoint(-15, -22, 800);
    chassis.moveToPoint(-13, -20, 2000, {.minSpeed = 100});
    intake.move(127);
    chassis.swingToHeading(0, lemlib::DriveSide::LEFT, 800);
    chassis.moveToPoint(-10, -20, 800, {.forwards = false});
    chassis.turnToPoint(-43, -38, 700, {.forwards = false});
    chassis.moveToPoint(-43, -38, 2000, {.forwards = false, .minSpeed = 100});
    chassis.turnToPoint(-50, -59, 700, {.forwards = false}); // turn to descore
    intake.move(0);

    chassis.moveToPoint(-50, -59, 1000, {.forwards = false, .minSpeed = 60});
    chassis.waitUntil(2);
    wingsLeft.set_value(true);
    chassis.turnToHeading(-87, 800);
    chassis.moveToPose(-3, -56, -90, 1300, {.forwards = false, .minSpeed = 90});
    chassis.moveToPoint(-17, -58, 1000);

    wingsLeft.set_value(false);
    chassis.turnToHeading(90, 1000);

    chassis.waitUntilDone();
    intake.move(-127);
    pros::delay(500);
    chassis.moveToPoint(-39, -64, 1000, {.forwards = false});
    chassis.turnToHeading(90, 1000, {.minSpeed = 60});
    //   chassis.follow(closeSide1_txt, 15, 3000, false);
}