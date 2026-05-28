#include <SFML/System.hpp>

#include "Application.hpp"
#include "SFMLRenderer.hpp"
#include "Config.hpp"

void Application::runBasicSimulation()
{
    renderer.createWindow();

    sf::Clock clock;
    float accumulator = 0.0f;

    while (renderer.isOpen())
    {
        float frameTime = clock.restart().asSeconds();

        if (frameTime > 0.25f)
            frameTime = 0.25f;

        accumulator += frameTime;

        renderer.pollEvents();

        while (accumulator >= Config::Constants::dt)
        {
            int action = -1;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
                action = 0;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
                action = 1;

            env.updateState(action);
            accumulator -= Config::Constants::dt;
        }

        auto [x, x_dot, theta, theta_dot] = env.getCurrentState();

        renderer.renderCurrentState(x, theta);
    }
}