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
    r.updateState(debug);
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
                debug = false;
            } else {
                debug = true;
            }
        }
    }

}

sf::Vector2f ThermostatSim::getDialSize()
{
    sf::Vector2f spriteSize(
    r.getDialSprite()->getTexture()->getSize().x * r.getDialSprite()->getScale().x,
    r.getDialSprite()->getTexture()->getSize().y * r.getDialSprite()->getScale().y);

    return spriteSize;
}
