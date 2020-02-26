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
        double getTemp();
        double readThermostat();
        int getTempControl();

        void update(bool debug);
        void setThermostat(double input);

        // Rendering
        sf::CircleShape* getDialSprite() const;

    private:
        double temp; // air temperature
        int tempControlSetting; // air conditioner, heater
        Thermostat t; // the room's thermostat

        // Dial GUI
        sf::Texture dialTexture;
        sf::Texture *dialTexturePtr;
        sf::CircleShape dial;
        sf::CircleShape *dialPtr;
};

#endif // ROOM_H
