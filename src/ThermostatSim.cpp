#include "ThermostatSim.h"

ThermostatSim::ThermostatSim(sf::Window *window):windowPtr(window), r(), gui(), debug(false)
{
    //ctor
}

ThermostatSim::~ThermostatSim()
{
    //dtor
}

void ThermostatSim::update()
{
    r.update();
    gui.update(r.readThermostat(), r.getTemp(), r.getTempControl());
}

void ThermostatSim::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::W) {
        r.up = isPressed;
        gui.up = isPressed;
    } else if (key == sf::Keyboard::S) {
        r.down = isPressed;
        gui.down = isPressed;
    } else if (key == sf::Keyboard::D) {
        if (!isPressed) {
            if (debug) {
                debug = false;
            } else {
                debug = true;
            }
        }
    }

}

