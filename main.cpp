#include <SFML/Graphics.hpp>
#include <Simulation.h>

// TODO
// Separate air-conditioner and heater units
// Electricity consumption therefrom
// Figure out more elegant ways to handle GUI,
// particularly sprites whose positions are dependent on one another.
// Model room dimensions
// Model outside weather

int main() {

    Simulation sim;
    sim.run();

}
