#include <numbers>
#include <optional>

#include "SFMLRenderer.hpp"
#include "Config.hpp"

SFMLRenderer::SFMLRenderer(unsigned int width, unsigned int height) : width(width), height(height)
{
    window = nullptr;

    cart = sf::RectangleShape({Config::Dimensions::cartWidth, Config::Dimensions::cartHeight});
    cart.setOrigin({Config::Dimensions::cartWidth / 2, Config::Dimensions::cartHeight / 2});
    cart.setPosition({Config::InitialState::x, Config::Dimensions::winHeight / 2});

    pendulum = sf::RectangleShape({Config::Dimensions::pendulumLength * Config::Constants::pixelsPerMeter, Config::Dimensions::pendulumWidth});
    pendulum.setOrigin({0, Config::Dimensions::pendulumWidth / 2});
    pendulum.setPosition({Config::InitialState::x, Config::Dimensions::winHeight / 2});
    pendulum.setRotation(sf::radians(Config::InitialState::theta - (std::numbers::pi / 2)));

    pendulum.setFillColor(sf::Color::Red);
    cart.setFillColor(sf::Color::Green);
}

void SFMLRenderer::createWindow()
{
    window = new sf::RenderWindow(sf::VideoMode({width, height}), "Pendulum Cart Simulation", sf::Style::Default, sf::State::Windowed);
}

void SFMLRenderer::closeWindow()
{
    window->close();
}

void SFMLRenderer::pollEvents()
{
    while (const std::optional event = window->pollEvent())
        if (event->is<sf::Event::Closed>())
            closeWindow();
}

bool SFMLRenderer::isOpen()
{
    return window->isOpen();
}

void SFMLRenderer::renderCurrentState(double position, double theta)
{
    float thetaEnv = static_cast<float>(theta) - (std::numbers::pi / 2);
    float xEnv = static_cast<float>(position * Config::Constants::pixelsPerMeter);

    cart.setPosition({xEnv, Config::Dimensions::winHeight / 2});
    pendulum.setPosition({xEnv, Config::Dimensions::winHeight / 2});
    pendulum.setRotation(sf::radians(thetaEnv));

    window->clear(sf::Color::Black);

    window->draw(cart);
    window->draw(pendulum);

    window->display();
}