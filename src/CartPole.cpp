#include <algorithm>
#include <cmath>

#include "CartPole.hpp"
#include "Config.hpp"

CartPoleEnv::CartPoleEnv()
{
    currentState.x = 0;
    currentState.x_dot = 0;
    currentState.theta = Config::InitialState::theta;
    currentState.theta_dot = 0;
}

State CartPoleEnv::getCurrentState() const
{
    return {currentState.x, currentState.x_dot, currentState.theta, currentState.theta_dot};
}

CartPoleEnv::StepResult CartPoleEnv::updateState(int action)
{
    // action 0 - left, action 1 - right, else do noting force is zero
    double force = 0;
    if (action == 0)
        force = -F;
    else if (action == 1)
        force = F;

    double sin_t = std::sin(currentState.theta);
    double cos_t = std::cos(currentState.theta);

    // Common denominator for circular and linear acceleration
    double denom = M + m * (sin_t * sin_t);

    double x_ddot = (force + m * sin_t * (l * currentState.theta_dot * currentState.theta_dot - g * cos_t)) / denom;

    double theta_ddot = (g * sin_t * (M + m) - cos_t * (force + m * l * currentState.theta_dot * currentState.theta_dot * sin_t)) / (l * denom);

    currentState.x_dot += x_ddot * dt;
    currentState.theta_dot += theta_ddot * dt;

    currentState.x += currentState.x_dot * dt;
    currentState.theta += currentState.theta_dot * dt;

    return {NULL, NULL, NULL};
}