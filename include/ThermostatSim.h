#ifndef THERMOSTATSIM_H
#define THERMOSTATSIM_H

#include <Room.h>

class ThermostatSim : public sf::Drawable
{
    public:
        ThermostatSim(sf::Window *window);
        ~ThermostatSim();
        void update();
        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
        void handleMouseInput();

        // rendering (overridden from Drawable)
        void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            target.draw(*r.getTestes());
            target.draw(*r.getDialSprite());
            if (debug)
                target.draw(*r.getDebugText());
        }

    private:
        sf::Window *windowPtr;
        Room r;
        sf::Vector2f getDialSize();
        bool debug;

};

#endif // THERMOSTATSIM_H
