#pragma once

#include <SFML/Graphics.hpp>

#include "Config.hpp"

class SFMLRenderer
{
public:
    SFMLRenderer(unsigned int width = Config::Dimensions::winWidth_P, unsigned int height = Config::Dimensions::winHeight_P);
    void createWindow();
    void closeWindow();
    void pollEvents(); // to check and close window upon clicking the exit button
    bool isOpen();
    void renderCurrentState(double position, double theta);

private:
    const unsigned int width;
    const unsigned int height;
    double cartx;
    double carty;
    double theta;
    sf::RenderWindow *window;
    sf::RectangleShape cart;
    sf::RectangleShape pendulum;
};