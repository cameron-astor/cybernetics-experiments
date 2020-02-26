#ifndef ROOM_H
#define ROOM_H

#include "Thermostat.h"
#include <SFML/Graphics.hpp>
#include <string>

class Room
{
    public:
        Room();
        ~Room();

        bool up;
        bool down;
        bool tempCtrlUp;
        bool tempCtrlDown;

        double getTemp();
        void updateState(bool debug);
        void setThermostat(double input);
        double readThermostat();

        // GUI
        sf::Text* getTestes() const;
        sf::Text* getDebugText() const;
        sf::CircleShape* getDialSprite() const;

    private:
        double temp;
        int tempControlSetting; // air conditioner, heater
        Thermostat t;

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
};

#endif // ROOM_H
