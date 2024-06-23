#include "main.h"
#include "devices.hpp"
#include "fmt/core.h"
#include "opcontrol.hpp"
#include "autos.hpp"
#include "robodash/views/selector.hpp"

rd::Selector selector({{"AWP", &awp}, {"Close", &close}, {"Far", &far}, {"Skills", &skills}});
rd_view_t* view = rd_view_create("Odometry");

/**
 * @brief entry point of the program
 *
 */
void initialize() {
    chassis.calibrate(); // calibrate sensors
    intake.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE); // set intake to brake

    // thread to print location on brain screen
    pros::Task screenTask([&]() {
        // create a label on the brain screen to display robot location
        lv_obj_t* label = lv_label_create(rd_view_obj(view));
        lv_obj_align(label, LV_ALIGN_LEFT_MID, 0, 0);
        while (true) {
            // print robot location to the brain screen
            const std::string output = fmt::format("X: {}\nY: {}\nTheta: {}", chassis.getPose().x, chassis.getPose().y,
                                                   chassis.getPose().theta);
            lv_label_set_text(label, output.c_str());
            //  delay to save resources
            pros::delay(10);
        }
    });
}

/**
 * @brief runs when field control is set to autonomous
 *
 */
void autonomous() {
    // run the selected autonomous routine
    selector.run_auton();
    // focus on the odometry view
    rd_view_focus(view);
}

/**
 * @brief runs when field control is set to opcontrol
 *
 */
void opcontrol() {
    // focus on the odometry view
    rd_view_focus(view);
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
            // we outtake slowly if neither wing button is pressed to make it extra clear
            // that we are not possessing multiple balls
            if (leftWingButtonPressed || rightWingButtonPressed) intake.move(-OUTTAKE_FAST_SPEED);
            else intake.move(-OUTTAKE_SLOW_SPEED);
        } else intake.move(0);

        // drivetrain
        const int throttle = master.get_analog(THROTTLE_AXIS);
        const int steer = master.get_analog(STEER_AXIS);
        chassis.arcade(throttle, steer, false, DESATURATION_BIAS);

        // delay to save resources
        pros::delay(10);
    }
}
