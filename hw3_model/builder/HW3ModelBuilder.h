//
// Created by freddy on 11/6/17.
//

#ifndef CSC_454_HW_4A_HW3MODELBUILDER_H
#define CSC_454_HW_4A_HW3MODELBUILDER_H

#include "../../framework/model/builder/NetworkModelBuilder.h"
class HW3ModelBuilder : public NetworkModelBuilder {
public:
    vector<char> input_symbol_set();
    vector<string> output_token_set();
    bool receives_external_input();
    int get_internal_ticks();
    ModelFunctions* model_functions(NetworkModel* model);
    string get_model_name();
    vector<Model*> get_sub_models();
    vector<tuple<Model*,Model*>> get_couplings();
};
#endif //CSC_454_HW_4A_HW3MODELBUILDER_H
