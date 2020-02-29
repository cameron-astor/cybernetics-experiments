#include "Room.h"

Room::Room():up(false), down(false), temp(65), tempControlSetting(0), t()
{

}

Room::~Room()
{
    //dtor
}

double Room::getTemp()
{
    return this->temp;
}

void Room::update()
{
    // logic updates

    // update thermostat
    this->t.update();

    // aircon/heater affects air temp
    this->temp = this->temp + ((double)(0.005 * this->tempControlSetting));
    // thermostat senses air temp
    this->t.readSensor(this->temp);
    // aircon/heater updated based on new thermostat reading
    tempControlSetting = this->t.getAirconSetting();

    // thermostat user controls
    if (this->up) {
        if (readThermostat() < 100.0) {
            this->setThermostat(readThermostat() + 0.25);
        }
    } else if (this->down) {
        if (readThermostat() > 30.0) {
            this->setThermostat(readThermostat() - 0.25);
        }
    }
}

void Room::setThermostat(double input)
{
    this->t.turnDial(input);
}

double Room::readThermostat()
{
    return this->t.getCurrentTarget();
}

int Room::getTempControl()
{
    return this->tempControlSetting;
}

