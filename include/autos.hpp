#pragma once

/////////////////////////////////////////
// Utility Functions
///////////////////////////

/**
 * @brief deploy the intake of the robot
 *
 * This works by deploying the left wing and retracting it shortly afterwards, releasing tension
 * on a rubber band that holds the intake in place. This is non-blocking and will return immediately.
 */
extern void deployIntake();

/////////////////////////////////////////
// Autonomous Routines
///////////////////////////

/**
 * @brief autonomous-win-point routine
 *
 */
extern void awp();

/**
 * @brief close side routine
 *
 */
extern void close();

/**
 * @brief far side match autonomous routine
 *
 * Scores 6 balls in the far goal. This is typically only used when we have supreme confidence in our
 * alliance partner, or in elimination matches where the Autonomous Win Point is irrelevant.
 *
 * 1. Deploy intake
 * 2. Rush to the middle of the field
 * 3. Knock the middle 2 balls towards the goal
 * 4. Collect ball at the alley
 * 5. Knock ball out of the matchloader
 * 6. Score 3 balls into the goal
 * 7. Collect the remaining ball
 * 8. Push the balls knocked in step 2 into the goal
 * 9. Turn around and score the last ball
 * 10. Reverse at max speed for the remaining time
 */
extern void far();

/**
 * @brief skills routine
 *
 */
extern void skills();