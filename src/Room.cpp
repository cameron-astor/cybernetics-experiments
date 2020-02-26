#include "Room.h"

Room::Room():up(false), down(false), temp(65), tempControlSetting(0), t(),
                        dialTexture(), dialTexturePtr(&dialTexture), dial(150, 50), dialPtr(&dial)
{

    // Load texture and setup sprite
    dialTexture.loadFromFile("sprites/dial.png");
    dialTexture.setSmooth(true);
    dial.setTexture(dialTexturePtr, false);
    dial.setScale(sf::Vector2<float>(0.3f, 0.3f));
    dial.setPosition(sf::Vector2<float>(150.f, 150.f));
    dial.setOrigin(getDialSprite()->getRadius(), getDialSprite()->getRadius());
}

Room::~Room()
{
    //dtor
}

double Room::getTemp()
{
    return this->temp;
}

void Room::update(bool debug)
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
            dial.rotate(1.f);
        }
    } else if (this->down) {
        if (readThermostat() > 30.0) {
            this->setThermostat(readThermostat() - 0.25);
            dial.rotate(-1.f);
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


sf::CircleShape* Room::getDialSprite() const
{
    return this->dialPtr;
}
