#ifndef THERMOSTATSIMGUI_H
#define THERMOSTATSIMGUI_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class ThermostatSimGUI
{
    public:
        ThermostatSimGUI();
        ~ThermostatSimGUI();

        void update(double thermostat, double roomTemp, int tempControl);
        sf::Text* getTestes() const;
        sf::Text* getDebugText() const;

    private:

        // Text GUI
        sf::Font font;
        sf::Text text; // Main GUI text
        sf::Text *textPtr;
        sf::Text debugText; // Debug text
        sf::Text *debugTextPtr;
};

#endif // THERMOSTATSIMGUI_H
