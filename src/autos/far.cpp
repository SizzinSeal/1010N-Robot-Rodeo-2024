#include "autos.hpp"
#include "devices.hpp"

// Video of this routine:
// https://media.discordapp.net/attachments/709813494899277855/1244361717983739954/IMG_4729.mov?ex=6679bfa8&is=66786e28&hm=ce9e3add4ebe267eadb13b2b47506a137ab88b929870f3c6b6d2282d18f697c0&

void far() {
    deployIntake(); // deploy the intake
    chassis.setPose(37, -54, 180); // set the starting position of he robot

    // rush to the center, knock the first ball towards the goal
    chassis.moveToPose(28, -12, 180, 1500, {.forwards = false, .minSpeed = 100});
    chassis.turnToPoint(13, -8, 800, {.minSpeed = 127});
    wingsRight.set_value(true);

    // acquire the second ball at the middle of the field
    intake.move(127);
    chassis.moveToPoint(13, -10, 800, {.minSpeed = 100});
    wingsRight.set_value(false); // retract the wing that was deployed to knock the first ball

    // back up and roll the second ball towards the goal
    chassis.moveToPoint(22, -20, 1000, {.forwards = false, .minSpeed = 90});
    chassis.turnToHeading(60, 400);
    intake.move(-70);

    // move towards the starting position and turn to face the ball in the alley
    chassis.turnToPoint(38, -55, 400, {.forwards = false, .minSpeed = 1});
    chassis.moveToPose(38, -55, 0, 1000, {.forwards = false, .minSpeed = 90});
    chassis.turnToHeading(-90, 700);

    // retrieve the ball in the alley
    chassis.moveToPoint(19, -59, 1000, {.minSpeed = 90}); // go get ball under matchloader
    intake.move(127);

    // go to the matchloader while pushing the preload, and knock the ball out of the matchload zone
    chassis.moveToPose(61, -44, 225, 2300, {.forwards = false, .minSpeed = 90});
    chassis.waitUntil(30);
    wingsLeft.set_value(true);
    intake.brake();
    chassis.waitUntil(47);
    wingsLeft.set_value(false);
    chassis.turnToHeading(205, 400);

    // push the 2 balls into the goal with the back of the robot and back up
    chassis.moveToPoint(68, -25, 800, {.forwards = false, .minSpeed = 127});
    chassis.moveToPoint(68, -30, 600, {.minSpeed = 127});

    // turn around and push the ball in the intake into the goal, then back up
    chassis.turnToHeading(100, 200, {.minSpeed = 127});
    chassis.turnToPoint(64, -25, 500);
    chassis.moveToPoint(64, -25, 800, {.minSpeed = 127});
    intake.move(-127);
    chassis.moveToPoint(62, -31, 700, {.forwards = false, .minSpeed = 100});

    // retrieve the last remaining ball
    chassis.turnToPoint(25, -30, 600);
    chassis.moveToPoint(25, -28, 1000, {.minSpeed = 110});
    intake.move(127);

    // push the 2 balls we knocked towards the goal at the start into the goal
    chassis.turnToHeading(230, 500);
    wingsLeft.set_value(true);
    wingsRight.set_value(true);
    chassis.moveToPose(47, -5, 90, 800, {.forwards = false, .minSpeed = 127});

    // back up, turn around, and push the ball in the intake into the goal
    chassis.moveToPoint(37, -5, 500, {.minSpeed = 127});
    wingsLeft.set_value(false);
    wingsRight.set_value(false);
    chassis.turnToHeading(90, 600);
    chassis.moveToPoint(55, -8, 700, {.minSpeed = 127});
    intake.move(-127);

    // back up so we aren't touching any balls when the autonomous period ends
    chassis.moveToPoint(37, -8, 500, {.forwards = false, .minSpeed = 127});
}