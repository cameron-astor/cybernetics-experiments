#include "ThermostatSim.h"

ThermostatSim::ThermostatSim()
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
}
