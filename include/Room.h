#ifndef ROOM_H
#define ROOM_H

#include "Thermostat.h"
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

        void update();
        void setThermostat(double input);


    private:
        double temp; // air temperature
        int tempControlSetting; // air conditioner, heater
        Thermostat t; // the room's thermostat
};

#endif // ROOM_H
