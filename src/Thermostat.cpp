#include "Thermostat.h"

Thermostat::Thermostat():target(65), current(65), airconSetting(0){}

Thermostat::~Thermostat(){}

void Thermostat::turnDial(double input)
{
	std::cout << "Turning dial to " << input << " degrees. \n" << std::endl;
	this->target = input;
}

void Thermostat::print()
{
	std::cout << "Target: " << this->target << "\n" << "Current: " << this->current << "\n" << std::endl;
}

double Thermostat::getCurrentTarget()
{
    return this->target;
}

void Thermostat::readSensor(double airTemp)
{
    this->current = airTemp;
}

int Thermostat::getAirconSetting()
{
    return airconSetting;
}

void Thermostat::calculateAirconSetting()
{
    if (target - current > 0.0) {
        if (target - current > 30.0)
            airconSetting = 5;
        else if (target - current > 20.0)
            airconSetting = 4;
        else if (target - current > 10.0)
            airconSetting = 3;
        else if (target - current > 3.0)
            airconSetting = 2;
        else if (target - current > 0.5)
            airconSetting = 1;
        else if (target - current > 0.0)
            airconSetting = 0;
    } else if (target - current < 0.0) {
        if (target - current < -30.0)
            airconSetting = -5;
        else if (target - current < -20.0)
            airconSetting = -4;
        else if (target - current < -10.0)
            airconSetting = -3;
        else if (target - current < -3.0)
            airconSetting = -2;
        else if (target - current < -0.5)
            airconSetting = -1;
        else if (target - current < 0.0)
            airconSetting = 0;
    } else if (target - current == 0) {
            airconSetting = 0;
    }
}

void Thermostat::update()
{
    calculateAirconSetting();
}
