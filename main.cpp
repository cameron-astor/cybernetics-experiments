#include <SFML/Graphics.hpp>
#include <Simulation.h>

// TODO

// Separate air-conditioner and heater units

// Electricity consumption therefrom

// Refactor: Make a SimEntity class with an update()
// for other shit to inherit from

// Figure out more elegant ways to handle GUI,
// particularly sprites whose positions are dependent on one another.
// Perhaps the GUI manager is too much, and it would make more sense
// to have each object handle its own GUI shit

// Figure out how to get sprites to scale properly without fucking up their arrangement
// (looking at you, thermometer)

// Model room dimensions

// Model outside weather

int main() {

    Simulation sim;
    sim.run();

}
