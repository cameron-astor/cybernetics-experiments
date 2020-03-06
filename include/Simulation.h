#ifndef SIMULATION_H
#define SIMULATION_H

#include <FpsCounter.h>
#include <ThermostatSim.h>

// The main game loop

class Simulation
{
    public:
        Simulation();
        virtual ~Simulation();
        void run();

    private:
        void processEvents();
        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
        void update(sf::Time deltaTime);
        void render();

    private:
        sf::RenderWindow mWindow; // Display window
        sf::Time TimePerFrame; // Game logic timing cap
        FpsCounter counter; // FPS counter
        ThermostatSim thermSim;
        sf::RenderStates rs;
        sf::View view;
};

#endif // SIMULATION_H
