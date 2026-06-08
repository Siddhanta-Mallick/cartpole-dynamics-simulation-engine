#pragma once

namespace Config
{
    namespace Constants
    {
        const double M = 1.0;   // Mass of the cart (kg)
        const double m = 0.1;   // Mass of the pole (kg)
        const double l_M = 1.0; // Length of the pole (meters)
        const double g = 9.81;  // Gravity (m/s^2)
        const double targetFPS = 60.0;
        const double dt = 1.0 / targetFPS;
        const double F = 10.0; // Force magnitude with which the cart is pushed
        const float pixelsPerMeter = 100;
    }
    namespace Dimensions
    {
        // These are magic numbers except pendulumLength
        const unsigned int winHeight_P = 800;
        const unsigned int winWidth_P = 800;
        const float pendulumLength_P = Constants::l_M;
        const float pendulumWidth_P = 5;
        const float cartHeight_P = 20.0;
        const float cartWidth_P = 40.0;
        const float cartBoundaryRight_M = winWidth_P / Constants::pixelsPerMeter;
        const float cartBoundaryMiddle_M = cartBoundaryRight_M / 2;
    }
    namespace InitialState
    {
        const float x_M = Dimensions::cartBoundaryMiddle_M;
        const float x_P = x_M * Constants::pixelsPerMeter;

        // theta from positive vertial y axis
        const float theta = 0.2;
    }
    namespace RLLimits
    {
        const float limitDistance_M = Dimensions::cartBoundaryRight_M / 2;
        const float limitLeft_M = Dimensions::cartBoundaryMiddle_M - limitDistance_M;
        const float limitRight_M = Dimensions::cartBoundaryMiddle_M + limitDistance_M;
        const float limitAngle_R = M_PI / 15; // 12 degrees
    }
}