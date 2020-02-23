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
        void updateState();
        void setThermostat(double input);
        double readThermostat();
        sf::Text* getTestes() const;

    private:
        double temp;
        int tempControlSetting; // air conditioner, heater
        Thermostat t;

        // GUI
        sf::Font font;
        sf::Text text;
        sf::Text *textPtr;
};

#endif // ROOM_H
