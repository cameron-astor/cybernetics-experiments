#include "ThermostatSim.h"

ThermostatSim::ThermostatSim(sf::Window *window):windowPtr(window), debug(false)
{
    //ctor
}

ThermostatSim::~ThermostatSim()
{
    //dtor
}

void ThermostatSim::update()
{
    r.updateState();
}

void ThermostatSim::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::W)
        r.up = isPressed;
    else if (key == sf::Keyboard::S)
        r.down = isPressed;
    else if (key == sf::Keyboard::Up)
        r.tempCtrlUp = isPressed;
    else if (key == sf::Keyboard::Down)
        r.tempCtrlDown = isPressed;
    else if (key == sf::Keyboard::D) {
        if (!isPressed) {
            if (debug) {
                std::cout << "false" << std::endl;
                debug = false;
            } else {
                std::cout << "true" << std::endl;
                debug = true;
            }
        }
    }

}

void ThermostatSim::handleMouseInput()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        std::cout << "left click at " << sf::Mouse::getPosition(*windowPtr).x << "," << sf::Mouse::getPosition(*windowPtr).y << std::endl;
        std::cout << getDialSize().x << " " << getDialSize().y << std::endl;
        std::cout << r.getDialSprite()->getOrigin().x << " " << r.getDialSprite()->getOrigin().y << std::endl;
    }

}

sf::Vector2f ThermostatSim::getDialSize()
{
    sf::Vector2f spriteSize(
    r.getDialSprite()->getTexture()->getSize().x * r.getDialSprite()->getScale().x,
    r.getDialSprite()->getTexture()->getSize().y * r.getDialSprite()->getScale().y);

    return spriteSize;
}
