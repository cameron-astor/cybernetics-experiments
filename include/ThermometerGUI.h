#ifndef THERMOMETERGUI_H
#define THERMOMETERGUI_H

#include <SFML/Graphics.hpp>

class ThermometerGUI
{
    public:
        ThermometerGUI();
        ~ThermometerGUI();

        sf::Sprite* getThermometer() const;
        sf::RectangleShape* getMercury() const;
        void update(double roomTemp);

    private:
        sf::RectangleShape mercury;
        sf::RectangleShape *mercuryPtr;
        sf::Texture thermometerTexture;
        sf::Texture *thermometerTexturePtr;
        sf::Sprite thermometerSprite;
        sf::Sprite *thermometerSpritePtr;
};

#endif // THERMOMETERGUI_H
