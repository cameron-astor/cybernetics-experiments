#include "FpsCounter.h"

FpsCounter::FpsCounter()
: startTime(sf::Time::Zero), endTime(sf::Time::Zero),
    frameTime(sf::Time::Zero), clock(), frames(0), text(), font()
{
    if (font.loadFromFile("fonts/Px437_IBM_BIOS.ttf")) {
        text.setFont(font);
        text.setCharacterSize(8);
        text.setStyle(sf::Text::Regular);
        text.setString("FPS: ");
        text.setPosition(20.f, 20.f);
    }
}

FpsCounter::~FpsCounter()
{
    //dtor
}

void FpsCounter::startCounter()
{
    startTime = sf::Time::Zero; // start the timer
    clock.restart();
}

void FpsCounter::stopAndPost()
{
    endTime = clock.getElapsedTime(); // stop the timer
    frameTime = frameTime + endTime;
    ++frames;

    if (frameTime.asMilliseconds() > 100) {
        std::string f = "FPS: " + std::to_string(frames * 10);
        text.setString(f);
        frames = 0;
        frameTime = sf::Time::Zero;
    }
}

sf::Text* FpsCounter::getFpsCounter()
{
    sf::Text *textPointer = &text;
    return textPointer;
}
