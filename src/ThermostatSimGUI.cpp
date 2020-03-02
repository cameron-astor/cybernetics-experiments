#include "ThermostatSimGUI.h"

ThermostatSimGUI::ThermostatSimGUI():up(false), down(false), font(), text(), textPtr(nullptr), debugText(), debugTextPtr(nullptr),
                                     dialTexture(), dialTexturePtr(&dialTexture), dial(150, 50), dialPtr(&dial), caseTexture(),
                                     caseTexturePtr(&caseTexture), thermostatCase(), thermostatCasePtr(&thermostatCase)
{
    setupText();
    setupDebugText();
    setupDial();
}

ThermostatSimGUI::~ThermostatSimGUI()
{
    //dtor
}

void ThermostatSimGUI::update(double thermostat, double roomTemp, int tempControl)
{
    // text updates
    std::string therm = std::to_string(thermostat);
    std::string tempS = std::to_string(roomTemp);
    std::string control = std::to_string(tempControl);

    this->text.setString("Thermostat: " + therm + "\n Room temp: " + tempS);
    this->debugText.setString("Temp control: " + control);

    // dial updates (user controls)
    if (this->up) {
        if (thermostat < 100.0) {
            dial.rotate(1.f);
        }
    } else if (this->down) {
        if (thermostat > 30.0) {
            dial.rotate(-1.f);
        }
    }
}

sf::Text* ThermostatSimGUI::getTestes() const
{
    return textPtr;
}

sf::Text* ThermostatSimGUI::getDebugText() const
{
    return debugTextPtr;
}

sf::Sprite* ThermostatSimGUI::getThermostatCase() const
{
    return thermostatCasePtr;
}

sf::CircleShape* ThermostatSimGUI::getDialSprite() const {
    return dialPtr;
}

void ThermostatSimGUI::setupText()
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
}

void ThermostatSimGUI::setupDebugText()
{
    // setup debug text
    debugText.setFont(font);
    debugText.setCharacterSize(12);
    debugText.setStyle(sf::Text::Regular);
    debugText.setString("Temp control: ");
    debugText.setPosition(400.f, 100.f);
    this->debugTextPtr = &this->debugText;

}

void ThermostatSimGUI::setupDial()
{
    // Load texture and setup sprite

    caseTexture.loadFromFile("sprites/ThermostatCasing.png");
    caseTexture.setSmooth(true);
    thermostatCase.setTexture(*caseTexturePtr, false);
    thermostatCase.setPosition(sf::Vector2<float>(150.f, 150.f));


    dialTexture.loadFromFile("sprites/dial.png");
    dialTexture.setSmooth(true);
    dial.setTexture(dialTexturePtr, false);
    dial.setScale(sf::Vector2<float>(0.34f, 0.34f));
    dial.setPosition(sf::Vector2<float>(243.f, 225.f));
    dial.setOrigin(dial.getRadius(), dial.getRadius());
}
