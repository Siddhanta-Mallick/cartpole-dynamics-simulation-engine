#pragma once

namespace Config
{
    namespace Constants
    {
        const double M = 1.0;  // Mass of the cart (kg)
        const double m = 0.1;  // Mass of the pole (kg)
        const double l = 1.0;  // Length of the pole (meters)
        const double g = 9.81; // Gravity (m/s^2)
        const double targetFPS = 60.0;
        const double dt = 1.0 / targetFPS;
        const double F = 10.0; // Force magnitude with which the cart is pushed
        const float pixelsPerMeter = 100;
    }
    namespace Dimensions
    {
        // These are magic numbers except pendulumLength
        const unsigned int winHeight = 800;
        const unsigned int winWidth = 800;
        const float pendulumLength = Constants::l;
        const float pendulumWidth = 5;
        const float cartHeight = 20.0;
        const float cartWidth = 40.0;
    }
    namespace InitialState
    {
        const float x = (Dimensions::winWidth / 2) / Constants::pixelsPerMeter;

        // theta from positive vertial y axis
        const float theta = 0.2;
    }
}