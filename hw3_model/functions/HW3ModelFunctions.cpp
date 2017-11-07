//
// Created by freddy on 11/6/17.
//

#include "HW3ModelFunctions.h"

HW3ModelFunctions::HW3ModelFunctions(NetworkModel *model) {
    this->network_model = model;
}

string HW3ModelFunctions::get_state_string() {
    return "test";
}