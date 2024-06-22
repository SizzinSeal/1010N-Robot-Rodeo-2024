#include "devices.hpp"
#include "opcontrol.hpp"
#include "autoTuning.hpp"

pros::Controller master(pros::E_CONTROLLER_MASTER);

pros::MotorGroup intake({LEFT_INTAKE_PORT, RIGHT_INTAKE_PORT});
pros::MotorGroup kicker({LEFT_KICKER_PORT, RIGHT_KICKER_PORT});

pros::adi::DigitalOut wingsLeft(LEFT_WING_PORT);
pros::adi::DigitalOut wingsRight(RIGHT_WING_PORT);
pros::adi::DigitalOut trackingWheelLift(TRACKING_WHEEL_LIFT_PORT);
pros::adi::DigitalOut hang(HANG_PORT);

pros::Rotation verticalEnc(VERTICAL_TRACKING_WHEEL_PORT);
lemlib::TrackingWheel vertical(&verticalEnc, VERTICAL_TRACKING_WHEEL_DIAMETER, VERTICAL_TRACKING_WHEEL_OFFSET);

pros::Rotation horizontalEnc(HORIZONTAL_TRACKING_WHEEL_PORT);
lemlib::TrackingWheel horizontal(&horizontalEnc, HORIZONTAL_TRACKING_WHEEL_DIAMETER, HORIZONTAL_TRACKING_WHEEL_OFFSET);

pros::Imu imu(IMU_PORT);

pros::MotorGroup leftMotors({LEFT_FRONT_DRIVE_PORT, LEFT_MIDDLE_DRIVE_PORT, LEFT_BACK_DRIVE_PORT}, DRIVE_GEARSET);
pros::MotorGroup rightMotors({RIGHT_FRONT_DRIVE_PORT, RIGHT_MIDDLE_DRIVE_PORT, RIGHT_BACK_DRIVE_PORT}, DRIVE_GEARSET);

lemlib::Drivetrain drivetrain(&leftMotors, // left motor group
                              &rightMotors, // right motor group
                              CHASSIS_TRACK_WIDTH, // chassis track width
                              CHASSIS_WHEEL_DIAMETER, // chassis wheel diameter
                              CHASSIS_RPM, // chassis RPM
                              CHASSIS_CHASE_POWER // scaled coefficient of friction
);

lemlib::OdomSensors sensors(&vertical, // vertical tracking wheel
                            nullptr, // vertical tracking wheel 2, we don't have a second one
                            &horizontal, // horizontal tracking wheel
                            nullptr, // horizontal tracking wheel 2, we don't have a second one
                            &imu // inertial sensor
);

// forward/backward PID
lemlib::ControllerSettings linearController(LINEAR_KP, // proportional gain (kP)
                                            LINEAR_KI, // integral gain (kI)
                                            LINEAR_KD, // derivative gain (kD)
                                            LINEAR_ANTI_WINDUP, // anti windup
                                            LINEAR_SMALL_ERROR, // small error range, in inches
                                            LINEAR_SMALL_ERROR_TIMEOUT, // small error range timeout, in milliseconds
                                            LINEAR_LARGE_ERROR, // large error range, in inches
                                            LINEAR_LARGE_ERROR_TIMEOUT, // large error range timeout, in milliseconds
                                            LINEAR_MAX_ACCEL // maximum acceleration (slew)
);

// turning PID
lemlib::ControllerSettings angularController(ANGULAR_KP, // proportional gain (kP)
                                             ANGULAR_KI, // integral gain (kI)
                                             ANGULAR_KD, // derivative gain (kD)
                                             ANGULAR_ANTI_WINDUP, // anti windup
                                             ANGULAR_SMALL_ERROR, // small error range, in degrees
                                             ANGULAR_SMALL_ERROR_TIMEOUT, // small error range timeout, in milliseconds
                                             ANGULAR_LARGE_ERROR, // large error range, in degrees
                                             ANGULAR_LARGE_ERROR_TIMEOUT, // large error range timeout, in milliseconds
                                             ANGULAR_MAX_ACCEL // maximum acceleration (slew)
);

lemlib::ExpoDriveCurve throttleCurve(THROTTLE_DEADBAND, // joystick deadband out of 127
                                     THROTTLE_MINIMUM_OUTPUT, // minimum output where drivetrain will move out of 127
                                     THROTTLE_EXPO_GAIN // expo curve gain
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steerCurve(STEER_DEADBAND, // joystick deadband out of 127
                                  STEER_MINIMUM_OUTPUT, // minimum output where drivetrain will move out of 127
                                  STEER_EXPO_GAIN // expo curve gain
);

// create the chassis
lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        linearController, // linear PID settings
                        angularController, // angular PID settings
                        sensors, // sensor settings
                        &throttleCurve, // throttle curve settings
                        &steerCurve // steer curve settings
);
