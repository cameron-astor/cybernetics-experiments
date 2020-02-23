#ifndef THERMOSTATSIM_H
#define THERMOSTATSIM_H

#include "SFML/Graphics.hpp"
#include <Room.h>

class ThermostatSim : public sf::Drawable
{
    public:
        ThermostatSim();
        ~ThermostatSim();
        void update();
        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

        // rendering (overridden from Drawable)
        void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            target.draw(*r.getTestes());
        }

    private:
        Room r;

};

#endif // THERMOSTATSIM_H
