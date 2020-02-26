#include "ThermostatSimGUI.h"

ThermostatSimGUI::ThermostatSimGUI():font(), text(), textPtr(nullptr),
                                        debugText(), debugTextPtr(nullptr)
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
}

ThermostatSimGUI::~ThermostatSimGUI()
{
    //dtor
}

void ThermostatSimGUI::update(double thermostat, double roomTemp, int tempControl)
{
    //gui updates
    std::string therm = std::to_string(thermostat);
    std::string tempS = std::to_string(roomTemp);
    std::string control = std::to_string(tempControl);

    this->text.setString("Thermostat: " + therm + "\n Room temp: " + tempS);
    this->debugText.setString("Temp control: " + control);
}

sf::Text* ThermostatSimGUI::getTestes() const
{
    return textPtr;
}

sf::Text* ThermostatSimGUI::getDebugText() const
{
    return debugTextPtr;
}
