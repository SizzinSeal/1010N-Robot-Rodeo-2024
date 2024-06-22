#pragma once

#include "lemlib/chassis/chassis.hpp"
#include "pros/adi.hpp"
#include "pros/misc.hpp"

/////////////////////////////////////////////////
// Device Configuration
///////////////////////////

constexpr int LEFT_KICKER_PORT = -2;
constexpr int RIGHT_KICKER_PORT = 9;

constexpr int LEFT_INTAKE_PORT = 15;
constexpr int RIGHT_INTAKE_PORT = -19;

#define DRIVE_GEARSET pros::MotorGears::blue
constexpr int LEFT_FRONT_DRIVE_PORT = -13;
constexpr int LEFT_MIDDLE_DRIVE_PORT = 12;
constexpr int LEFT_BACK_DRIVE_PORT = -14;
constexpr int RIGHT_FRONT_DRIVE_PORT = 18;
constexpr int RIGHT_MIDDLE_DRIVE_PORT = -16;
constexpr int RIGHT_BACK_DRIVE_PORT = 17;

constexpr int VERTICAL_TRACKING_WHEEL_PORT = -11;
constexpr float VERTICAL_TRACKING_WHEEL_DIAMETER = 2.75;
constexpr float VERTICAL_TRACKING_WHEEL_OFFSET = -2.5;

constexpr int HORIZONTAL_TRACKING_WHEEL_PORT = 20;
constexpr float HORIZONTAL_TRACKING_WHEEL_DIAMETER = 2.75;
constexpr float HORIZONTAL_TRACKING_WHEEL_OFFSET = -5.75;

constexpr int IMU_PORT = 10;

constexpr char LEFT_WING_PORT = 'h';
constexpr char RIGHT_WING_PORT = 'g';
constexpr char TRACKING_WHEEL_LIFT_PORT = 'a';
constexpr char HANG_PORT = 'b';

constexpr float CHASSIS_TRACK_WIDTH = 10.0;
constexpr float CHASSIS_WHEEL_DIAMETER = 4.0;
constexpr float CHASSIS_RPM = 343.0;

/////////////////////////////////////////////////
// Global Device Objects
///////////////////////////

extern pros::Controller master;
extern pros::MotorGroup intake;
extern pros::MotorGroup kicker;
extern pros::adi::DigitalOut wingsLeft;
extern pros::adi::DigitalOut wingsRight;
extern pros::adi::DigitalOut trackingWheelLift;
extern pros::adi::DigitalOut hang;
extern lemlib::Chassis chassis;
