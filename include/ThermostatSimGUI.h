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

        bool up;
        bool down;

        void update(double thermostat, double roomTemp, int tempControl);
        sf::Text* getTestes() const;
        sf::Text* getDebugText() const;
        sf::CircleShape* getDialSprite() const;

    private:

        // Text GUI
        sf::Font font;
        sf::Text text; // Main GUI text
        sf::Text *textPtr;
        sf::Text debugText; // Debug text
        sf::Text *debugTextPtr;

        // Dial GUI
        sf::Texture dialTexture;
        sf::Texture *dialTexturePtr;
        sf::CircleShape dial;
        sf::CircleShape *dialPtr;

        void setupText();
        void setupDebugText();
        void setupDial();
};

#endif // THERMOSTATSIMGUI_H
