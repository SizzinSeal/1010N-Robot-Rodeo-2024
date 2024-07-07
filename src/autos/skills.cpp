#include "autos.hpp"
#include "devices.hpp"

ASSET(skills1_txt);

void skills() {
    chassis.setPose(-43.4, -55, 90);

    chassis.moveToPoint(-55, -14, 1000, {.forwards = false, .minSpeed = 127}); // score first ba;;
    chassis.waitUntil(1);
    wingsRight.set_value(true);
    pros::delay(200);
    wingsRight.set_value(false);
    // line up to matchload
    chassis.moveToPoint(-60.3, -44, 1000, {.minSpeed = 1}); // move to shooting pos
    // chassis.turnToHeading(72, 800, {}); // turn to shoot
    chassis.turnToPoint(50, -3, 800);
    chassis.moveToPoint(-61, -42, 700, {.forwards = false, .minSpeed = 30});
    chassis.turnToPoint(50, -3, 300);
    chassis.waitUntilDone();
    auto pose = chassis.getPose();
    wingsRight.set_value(true);
    // TODO: uncomment this
    // kicker.move(95);
    // pros::delay(23500);
    kicker.move(0);
    chassis.setPose(pose);
    //   descore
    chassis.turnToPoint(-55, -49, 800, {.forwards = false}); // turn to descore
    wingsRight.set_value(false);
    chassis.moveToPoint(-55, -49, 800, {.forwards = false, .minSpeed = 60}); // descore
    wingsLeft.set_value(true);
    chassis.waitUntil(12);

    // get to the other matchload bar
    chassis.swingToHeading(-80, lemlib::DriveSide::RIGHT, 1000, {.maxSpeed = 70, .minSpeed = 60}); // turn to middle
    chassis.waitUntil(3);
    wingsLeft.set_value(false);
    chassis.moveToPoint(-11, -54, 2000, {.forwards = false, .minSpeed = 117, .earlyExitRange = 20}); // move to middle
    chassis.moveToPose(5, -51.5, -90, 1400, {.forwards = false, .minSpeed = 100}); // move to far side matchloader
    chassis.waitUntil(23);
    wingsRight.set_value(true);
    chassis.moveToPose(53, -42, -125, 1100,
                       {.forwards = false, .minSpeed = 80, .earlyExitRange = 5}); // move to descore
    chassis.waitUntil(25);
    wingsLeft.set_value(true);
    pros::delay(600);
    wingsLeft.set_value(false);

    chassis.moveToPoint(57, -26, 1000, {.forwards = false, .minSpeed = 100});
    chassis.moveToPoint(57, -32, 500, {.minSpeed = 90}); // back up
    chassis.moveToPoint(57, -25, 800, {.forwards = false, .minSpeed = 127});
    wingsRight.set_value(false);
    chassis.moveToPoint(57, -34, 1000, {.minSpeed = 50}); // back up

    chassis.turnToHeading(110, 800, {.minSpeed = 60});
    chassis.follow(skills1_txt, 15, 2500, false);
    wingsLeft.set_value(true);
    wingsRight.set_value(true);
    chassis.waitUntilDone();
    wingsRight.set_value(false);
    chassis.moveToPoint(30, -12, 400, {.forwards = false});
    chassis.turnToPoint(50, -5, 500, {.forwards = false});
    chassis.moveToPoint(50, -5, 1000, {.forwards = false, .minSpeed = 100});

    chassis.swingToPoint(15.8, -33, lemlib::DriveSide::RIGHT, 400, {.forwards = false, .minSpeed = 127}); //-33
    chassis.waitUntilDone();
    wingsLeft.set_value(false);
    chassis.moveToPose(14, -20, 90, 1000, {.forwards = false, .minSpeed = 90});
    wingsRight.set_value(true);
    chassis.swingToHeading(180, lemlib::DriveSide::LEFT, 400, {.minSpeed = 1});
    chassis.moveToPoint(11, -12, 1000, {.forwards = false, .minSpeed = 100});

    chassis.turnToPoint(41, 3, 700, {.forwards = false});

    wingsLeft.set_value(true);
    chassis.waitUntil(15);
    chassis.waitUntilDone();

    chassis.moveToPoint(
        45, 3, 1200, {.forwards = false, .maxSpeed = 127}); // push middle 1 //used to be 1200 when it was one movement
    chassis.swingToHeading(0, lemlib::DriveSide::RIGHT, 400, {.minSpeed = 1}); // back up
    wingsLeft.set_value(false);
    wingsRight.set_value(false);
    chassis.turnToPoint(22, -3, 300, {.forwards = false, .minSpeed = 90}); // back up
    chassis.moveToPoint(22, -3, 1200, {.forwards = false, .minSpeed = 90}); // back up
    chassis.turnToHeading(180, 600);
    chassis.moveToPoint(7, 7, 800, {.forwards = false, .minSpeed = 60});
    chassis.turnToHeading(-90, 700, {.minSpeed = 1});
    chassis.waitUntil(5);
    wingsLeft.set_value(true);
    chassis.moveToPoint(50, 15, 1000, {.forwards = false, .minSpeed = 127}); // push middle 2
    chassis.swingToHeading(0, lemlib::DriveSide::LEFT, 400, {.minSpeed = 1});

    chassis.turnToPoint(10, 5, 800, {.forwards = false});
    wingsLeft.set_value(false);

    chassis.moveToPoint(10, 5, 400, {.forwards = false, .minSpeed = 100});
    chassis.turnToHeading(180, 700);
    chassis.moveToPoint(12, 32, 900, {.forwards = false, .minSpeed = 40});
    wingsRight.set_value(true);
    chassis.swingToHeading(-90, lemlib::DriveSide::LEFT, 300);
    chassis.turnToHeading(325, 600, {.minSpeed = 1});
    chassis.waitUntilDone();
    wingsRight.set_value(true);
    wingsLeft.set_value(true);
    chassis.moveToPoint(45.5, 17.6, 1400, {.forwards = false, .minSpeed = 115});
    chassis.waitUntilDone();
    wingsRight.set_value(false);
    wingsLeft.set_value(false);
    chassis.moveToPoint(34, 20, 600, {.maxSpeed = 65, .minSpeed = 45});
    chassis.turnToPoint(36, 57, 500, {.forwards = false});
    wingsLeft.set_value(true);
    chassis.moveToPoint(36, 58, 2500, {.forwards = false, .maxSpeed = 100, .minSpeed = 90});

    chassis.turnToHeading(270, 600);
    wingsLeft.set_value(true);
    chassis.moveToPose(49, 50, 340, 900, {.forwards = false, .minSpeed = 100}); // descore + get momentum for pushes
    chassis.waitUntil(3);
    wingsRight.set_value(true);
    pros::delay(450);
    wingsRight.set_value(false);
    chassis.turnToHeading(330, 500, {.minSpeed = 1});
    chassis.moveToPoint(55, 40, 900, {.forwards = false, .minSpeed = 127}); // push side
    chassis.moveToPoint(35, 65, 800, {.maxSpeed = 80, .minSpeed = 60});
    chassis.moveToPoint(55, 30, 1000, {.forwards = false, .minSpeed = 127});
    chassis.moveToPose(28, 68, 270, 1500, {.maxSpeed = 100, .minSpeed = 80});
    wingsLeft.set_value(false);
    chassis.turnToHeading(270, 700);
    hang.set_value(true);
    chassis.moveToPose(-20, 70, 270, 1200, {.maxSpeed = 80, .minSpeed = 70});
    chassis.waitUntilDone();
    hang.set_value(false);
}