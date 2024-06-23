#include "autos.hpp"
#include "devices.hpp"

void far() {
    wingsLeft.set_value(true);
    chassis.setPose(37, -54, 180);

    chassis.moveToPose(27, -12, 180, 1500, {.forwards = false, .minSpeed = 100});
    chassis.waitUntil(1);
    wingsLeft.set_value(false);
    chassis.waitUntilDone();
    wingsRight.set_value(true);
    chassis.turnToPoint(13, -8, 800, {.minSpeed = 127});
    intake.move(127);
    chassis.moveToPoint(13, -8, 800, {.minSpeed = 100});
    wingsRight.set_value(false);
    chassis.moveToPoint(22, -20, 1000, {.forwards = false, .minSpeed = 90});
    chassis.turnToHeading(60, 400);
    intake.move(-70);
    chassis.turnToPoint(38, -55, 400, {.forwards = false, .minSpeed = 1});
    chassis.moveToPose(38, -55, 0, 1000, {.forwards = false, .minSpeed = 90});
    chassis.turnToHeading(-90, 700);
    chassis.moveToPoint(19, -59, 1000, {.minSpeed = 90}); // go get ball under matchloader
    intake.move(127);
    chassis.moveToPose(61, -44, 225, 2300, {.forwards = false, .minSpeed = 90});

    chassis.waitUntil(30);
    wingsLeft.set_value(true);
    intake.move(0);
    chassis.turnToHeading(205, 400);
    wingsLeft.set_value(false);
    chassis.moveToPoint(68, -25, 800, {.forwards = false, .minSpeed = 127});
    chassis.moveToPoint(68, -35, 600, {.minSpeed = 127}); // back up
    chassis.turnToHeading(100, 200, {.minSpeed = 127});
    chassis.turnToPoint(64, -25, 500);
    chassis.moveToPoint(64, -25, 800, {.minSpeed = 127});
    intake.move(-127);
    chassis.moveToPoint(62, -31, 700, {.forwards = false, .minSpeed = 100});
    chassis.turnToPoint(25, -30, 600);
    chassis.moveToPoint(25, -28, 1000, {.minSpeed = 110});
    intake.move(127);
    chassis.turnToHeading(230, 500);
    wingsLeft.set_value(true);
    chassis.moveToPose(47, -5, 90, 800, {.forwards = false, .minSpeed = 127});
    chassis.moveToPoint(37, -5, 500, {.minSpeed = 127});
    wingsLeft.set_value(false);
    wingsRight.set_value(false);
    chassis.turnToHeading(90, 600);
    chassis.moveToPoint(55, -8, 700, {.minSpeed = 127});
    intake.move(-127);
    chassis.moveToPoint(37, -8, 500, {.forwards = false, .minSpeed = 127});
}