//
// Created by freddy on 11/5/17.
//

#include "Simulation.h"

#include <iostream>
#include <stdio.h>
#include <vector>

Simulation::Simulation(Model *model) {
    this->model = model;
}

void Simulation::run() {
    while(model->is_running) {
        cout << "[Simulation] Executing tick #" << tick << endl;
        vector<string> output = model->tick();
        cout << model->get_model_name() << " output at simulation tick #" << tick << ": " << endl;
        for(string token : output) {
            cout << "\t" << token << endl;
        }
    }
}

void Simulation::set_debug_mode(bool debug) {
    model->set_debug_mode(debug);
}

void Simulation::cleanup() {

}