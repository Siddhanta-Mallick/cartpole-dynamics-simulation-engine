#pragma once

#include "Config.hpp"

struct State
{
    double x;
    double x_dot;
    double theta;
    double theta_dot;
};

class CartPoleEnv
{
public:
    struct StepResult
    {
        State nextState;
        double reward;
        bool done;
    };

    CartPoleEnv();
    void reset();
    StepResult updateState(int action);
    State getCurrentState() const;

private:
    State currentState;
    const double M = Config::Constants::M;
    const double m = Config::Constants::m;
    const double l = Config::Constants::l_M;
    const double g = Config::Constants::g;
    const double dt = Config::Constants::dt;
    const double F = Config::Constants::F;
};