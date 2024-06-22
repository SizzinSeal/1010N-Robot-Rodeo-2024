#pragma once

constexpr float CHASSIS_CHASE_POWER = 2.0; // scaled coefficient of friction

constexpr float LINEAR_KP = 6.0; // proportional gain (kP)
constexpr float LINEAR_KI = 0.0; // integral gain (kI)
constexpr float LINEAR_KD = 2.0; // derivative gain (kD)
constexpr float LINEAR_ANTI_WINDUP = 3.0; // anti windup
constexpr float LINEAR_SMALL_ERROR = 1.0; // small error range, in inches
constexpr int LINEAR_SMALL_ERROR_TIMEOUT = 100; // small error range timeout, in milliseconds
constexpr float LINEAR_LARGE_ERROR = 3.0; // large error range, in inches
constexpr int LINEAR_LARGE_ERROR_TIMEOUT = 500; // large error range timeout, in milliseconds
constexpr float LINEAR_MAX_ACCEL = 20.0; // maximum acceleration (slew)

constexpr float ANGULAR_KP = 1.5; // proportional gain (kP)
constexpr float ANGULAR_KI = 0.0; // integral gain (kI)
constexpr float ANGULAR_KD = 10.5; // derivative gain (kD)
constexpr float ANGULAR_ANTI_WINDUP = 3.0; // anti windup
constexpr float ANGULAR_SMALL_ERROR = 1.0; // small error range, in degrees
constexpr int ANGULAR_SMALL_ERROR_TIMEOUT = 100; // small error range timeout, in milliseconds
constexpr float ANGULAR_LARGE_ERROR = 3.0; // large error range, in degrees
constexpr int ANGULAR_LARGE_ERROR_TIMEOUT = 500; // large error range timeout, in milliseconds
constexpr float ANGULAR_MAX_ACCEL = 0.0; // maximum acceleration (slew)
