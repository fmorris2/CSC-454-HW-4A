//
// Created by freddy on 11/6/17.
//

#ifndef CSC_454_HW_4A_MODELBUILDER_H
#define CSC_454_HW_4A_MODELBUILDER_H

#include "../Model.h"
class ModelBuilder {
public:
    virtual Model* get_base_model() = 0;
    virtual vector<char> input_symbol_set() = 0;
    virtual vector<string> output_token_set() = 0;
    virtual bool receives_external_input() = 0;
    virtual int get_internal_ticks() = 0;
    virtual ModelFunctions* model_functions(Model* model) = 0;
    virtual string get_model_name() = 0;
};

#endif //CSC_454_HW_4A_MODELBUILDER_H
