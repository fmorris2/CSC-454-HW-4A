//
// Created by freddy on 11/5/17.
//

#include "../model/Model.h"
using namespace std;

#ifndef CSC_454_HW_4A_SIMULATION_H
#define CSC_454_HW_4A_SIMULATION_H

class Simulation {
public:
    Simulation(Model *model);
    void run();
    void set_debug_mode(bool debug);
    void cleanup();
private:
    int tick = 1;
    Model *model;
};

#endif //CSC_454_HW_4A_SIMULATION_H
