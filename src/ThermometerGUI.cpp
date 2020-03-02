#include "ThermometerGUI.h"

ThermometerGUI::ThermometerGUI():mercury(sf::Vector2f(30.f, 30.f)), mercuryPtr(&mercury), thermometerTexture(),
                                 thermometerTexturePtr(&thermometerTexture), thermometerSprite(),
                                 thermometerSpritePtr(&thermometerSprite)
{
    mercury.setFillColor(sf::Color::Red);
    mercury.setPosition(sf::Vector2f(620.f, 340.f));

    thermometerTexture.loadFromFile("sprites/Thermometer.png");
    thermometerTexture.setSmooth(true);
    thermometerSprite.setTexture(*thermometerTexturePtr, false);
    thermometerSprite.setPosition(sf::Vector2f(mercury.getPosition().x - 20.f, mercury.getPosition().y - 240.f));
}

ThermometerGUI::~ThermometerGUI()
{
    //dtor
}

sf::Sprite* ThermometerGUI::getThermometer() const
{
    return thermometerSpritePtr;
}

sf::RectangleShape* ThermometerGUI::getMercury() const
{
    return mercuryPtr;
}

void ThermometerGUI::update(double roomTemp)
{
    mercury.setSize(sf::Vector2f(30.f, -30.f - (roomTemp * 1.8)));
    std::cout << roomTemp * 1.8 << std::endl;
}
