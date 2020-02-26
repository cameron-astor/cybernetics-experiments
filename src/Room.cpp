#include "Room.h"

Room::Room():up(false), down(false), tempCtrlUp(false), tempCtrlDown(false), temp(65), tempControlSetting(0), t(), font(), text(), textPtr(nullptr),
            debugText(), debugTextPtr(nullptr), dialTexture(), dialTexturePtr(&dialTexture), dial(150, 50), dialPtr(&dial)
{
    // Load font and setup main text
    if (font.loadFromFile("fonts/Px437_IBM_BIOS.ttf")) {
        text.setFont(font);
        text.setCharacterSize(12);
        text.setStyle(sf::Text::Regular);
        text.setString("Thermostat: \n Room temp: ");
        text.setPosition(50.f, 50.f);
    }
    this->textPtr = &this->text;

    // setup debug text
    debugText.setFont(font);
    debugText.setCharacterSize(12);
    debugText.setStyle(sf::Text::Regular);
    debugText.setString("Temp control: ");
    debugText.setPosition(50.f, 300.f);
    this->debugTextPtr = &this->debugText;

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

void Room::updateState(bool debug)
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

    //gui updates
    std::string therm = std::to_string(this->readThermostat());
    std::string tempS = std::to_string(this->temp);
    std::string control = std::to_string(this->tempControlSetting);
    this->text.setString("Thermostat: " + therm + "\n Room temp: " + tempS);
    this->debugText.setString("Temp control: " + control);
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

sf::Text* Room::getDebugText() const
{
    return this->debugTextPtr;
}

sf::CircleShape* Room::getDialSprite() const
{
    return this->dialPtr;
}
