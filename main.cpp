//
// Created by freddy on 11/5/17.
//
#include <stdlib.h>
#include "framework/simulation/Simulation.h"
#include "hw3_model/HW3Model.h"
int main() {
    Model* model = Model::create<HW3Model> ("HW3 Model");
    Simulation simulation = Simulation(model);
    simulation.set_debug_mode(true);

    simulation.run();

    simulation.cleanup();
    return EXIT_SUCCESS;
}

