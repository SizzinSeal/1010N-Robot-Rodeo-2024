#include "main.h"
#include "devices.hpp"
#include "opcontrol.hpp"
#include "autos.hpp"
#include "robodash/views/selector.hpp"

rd::Selector selector({{"AWP", &awp}, {"Close", &close}, {"Far", &far}, {"Skills", &skills}});

/**
 * @brief entry point of the program
 *
 */
void initialize() {
    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
    intake.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE); // set intake to brake

    // thread to print location on brain screen
    pros::Task screenTask([&]() {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // delay to save resources
            pros::delay(10);
        }
    });
}

/**
 * @brief runs after #initialize, and only if connected to field control
 *
 */
void competition_initialize() {}

/**
 * @brief runs when field control is set to disabled
 *
 */
void disabled() {}

/**
 * @brief runs when field control is set to autonomous
 *
 */
void autonomous() { selector.run_auton(); }

/**
 * @brief runs when field control is set to opcontrol
 *
 */
void opcontrol() {
    // lift the tracking wheels
    trackingWheelLift.set_value(true);
    bool hangToggle = false; // hang mechanism toggle

    // loop while in driver control
    while (true) {
        // hang mechanism
        if (master.get_digital_new_press(HANG_TOGGLE_BUTTON)) hangToggle = !hangToggle;
        hang.set_value(hangToggle);

        // wings
        const bool leftWingButtonPressed = master.get_digital(LEFT_WING_BUTTON);
        const bool rightWingButtonPressed = master.get_digital(RIGHT_WING_BUTTON);
        if (leftWingButtonPressed) wingsLeft.set_value(true);
        else wingsLeft.set_value(false);
        if (rightWingButtonPressed) wingsRight.set_value(true);
        else wingsRight.set_value(false);

        // intake
        const bool intakeButtonPressed = master.get_digital(INTAKE_BUTTON);
        const bool outtakeButtonPressed = master.get_digital(OUTTAKE_BUTTON);
        if (intakeButtonPressed) intake.move_velocity(INTAKE_SPEED);
        else if (outtakeButtonPressed) {
            if (leftWingButtonPressed || rightWingButtonPressed) intake.move(-OUTTAKE_FAST_SPEED);
            else intake.move(-OUTTAKE_SLOW_SPEED);
        } else intake.move(0);

        // drivetrain
        const int throttle = master.get_analog(THROTTLE_AXIS);
        const int steer = master.get_analog(STEER_AXIS);
        chassis.arcade(throttle, steer);

        // delay to save resources
        pros::delay(10);
    }
}
