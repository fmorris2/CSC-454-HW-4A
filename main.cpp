//
// Created by freddy on 11/5/17.
//
#include <stdlib.h>
#include "framework/model/builder/BuilderDirector.h"
#include "framework/simulation/Simulation.h"
#include "hw3_model/builder/HW3ModelBuilder.h"
int main() {
    BuilderDirector director;
    director.set_builder(new HW3ModelBuilder());
    Simulation simulation = Simulation(director.get_model());
    simulation.set_debug_mode(true);

    simulation.run();

    director.cleanup();
    simulation.cleanup();
    return EXIT_SUCCESS;
}

