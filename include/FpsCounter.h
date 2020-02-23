#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H

#include <SFML/Graphics.hpp>

// Counts the FPS (duh)
class FpsCounter
{
    public:
        FpsCounter();
        virtual ~FpsCounter();
        void startCounter();
        void stopAndPost();
        sf::Text* getFpsCounter();

    private:
        sf::Time startTime;
        sf::Time endTime;
        sf::Time frameTime;
        sf::Clock clock;
        unsigned int frames;
        sf::Text text;
        sf::Font font;

};

#endif // FPSCOUNTER_H
