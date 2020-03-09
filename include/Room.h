#ifndef ROOM_H
#define ROOM_H

#include <Thermostat.h>
#include <Heater.h>
#include <string>
#include <Entity.h>

class Room : public Entity
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
        Heater h; // the room's heater
};

#endif // ROOM_H
