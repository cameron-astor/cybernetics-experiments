#include "Simulation.h"

Simulation::Simulation()
: mWindow(sf::VideoMode(640, 480), "Window!"), TimePerFrame(sf::seconds(1.f/60.f)),
    counter(), thermSim(&mWindow), rs()
{

}

Simulation::~Simulation()
{
    //dtor
}

void Simulation::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mWindow.isOpen()) {

        counter.startCounter();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }

        render();

        counter.stopAndPost();
    }
}

void Simulation::processEvents()
{
    sf::Event event;

    while (mWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                thermSim.handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                thermSim.handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}

// game logic update
void Simulation::update(sf::Time deltaTime)
{
    thermSim.update();
}

void Simulation::render()
{
    mWindow.clear();
    mWindow.draw(*counter.getFpsCounter());
    thermSim.draw(mWindow, rs);
    mWindow.display();
}

