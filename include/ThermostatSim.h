#ifndef THERMOSTATSIM_H
#define THERMOSTATSIM_H

#include <Room.h>
#include <ThermostatSimGUI.h>

class ThermostatSim : public sf::Drawable
{
    public:
        ThermostatSim(sf::Window *window);
        ~ThermostatSim();
        void update();
        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

        // rendering (overridden from Drawable)
        void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            target.draw(*gui.getTestes());
            target.draw(*gui.getThermostatCase());
            target.draw(*gui.getDialSprite());
            target.draw(*gui.getMercury());
            target.draw(*gui.getThermometer());


            if (debug)
                target.draw(*gui.getDebugText());
        }

    private:
        sf::Window *windowPtr;
        Room r;
        ThermostatSimGUI gui;
        bool debug;

};

#endif // THERMOSTATSIM_H
