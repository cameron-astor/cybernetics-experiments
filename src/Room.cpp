#include "Room.h"

Room::Room():up(false), down(false), tempCtrlUp(false), tempCtrlDown(false), temp(65), tempControlSetting(0), t(), font(), text(), textPtr(nullptr)
{
    if (font.loadFromFile("fonts/Px437_IBM_BIOS.ttf")) {
        text.setFont(font);
        text.setCharacterSize(12);
        text.setStyle(sf::Text::Regular);
        text.setString("Thermostat: \n Room temp: \n Temp control: ");
        text.setPosition(50.f, 50.f);
    }
    this->textPtr = &this->text;
}

Room::~Room()
{
    //dtor
}

double Room::getTemp()
{
    return this->temp;
}

void Room::updateState()
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
        if (readThermostat() < 100.0)
            this->setThermostat(readThermostat() + 0.25);
    } else if (this->down) {
        if (readThermostat() > 40.0)
            this->setThermostat(readThermostat() - 0.25);
    }

    // aircon/heater user setting (DEBUG)
    if (this->tempCtrlUp) {
        if (tempControlSetting < 5)
            tempControlSetting++;
    } else if (this->tempCtrlDown) {
        if (tempControlSetting > -5)
            tempControlSetting--;
    }

    //gui updates
    std::string therm = std::to_string(this->readThermostat());
    std::string tempS = std::to_string(this->temp);
    std::string control = std::to_string(this->tempControlSetting);
    this->text.setString("Thermostat: " + therm + "\n Room temp: " + tempS + "\n Temp control: " + control);
}

void Room::setThermostat(double input)
{
    this->t.turnDial(input);
}

double Room::readThermostat()
{
    return this->t.getCurrentTarget();
}

sf::Text* Room::getTestes() const
{
    return this->textPtr;
}
