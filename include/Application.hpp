#pragma once

#include "SFMLRenderer.hpp"
#include "CartPole.hpp"

class Application
{
public:
    void runBasicSimulation();
    void runRLSimulation();

private:
    CartPoleEnv env;
    SFMLRenderer renderer;
};