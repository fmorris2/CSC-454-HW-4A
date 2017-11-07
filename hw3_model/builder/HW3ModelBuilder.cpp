//
// Created by freddy on 11/6/17.
//

#include "HW3ModelBuilder.h"
#include "../functions/HW3ModelFunctions.h"

HW3ModelData data;

bool HW3ModelBuilder::receives_external_input() {
    return true;
}

vector<string> HW3ModelBuilder::output_token_set() {
    return {"0", "1"};
}

int HW3ModelBuilder::get_internal_ticks() {
    return 3;
}

ModelFunctions* HW3ModelBuilder::model_functions(NetworkModel* model) {
    return new HW3ModelFunctions(model);
}

vector<char> HW3ModelBuilder::input_symbol_set() {
    vector<char> set = {'0', '1'};
    return set;
}

vector<tuple<Model*,Model*>> HW3ModelBuilder::get_couplings() {
    return {};
}

vector<Model*> HW3ModelBuilder::get_sub_models() {
    return {};
}

string HW3ModelBuilder::get_model_name() {
    return "HW3 Model";
}

class HW3ModelData {
public:
};