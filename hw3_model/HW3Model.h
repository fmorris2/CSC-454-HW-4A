//
// Created by freddy on 11/7/17.
//

#ifndef CSC_454_HW_4A_HW3MODEL_H
#define CSC_454_HW_4A_HW3MODEL_H

#include "../framework/model/NetworkModel.h"
#include "sub_models/MemoryModel.h"
#include "sub_models/XORModel.h"
class HW3Model : public NetworkModel {
public:
    HW3Model(){}
protected:
    vector<char> init_input_symbol_set();
    vector <string> init_output_token_set();
    bool init_receives_external_input();
    int init_internal_ticks();
    string get_state_string();

    vector<Model*> init_sub_models();
    vector<Coupling> init_couplings();
private:
    Model* XOR_1 = Model::create<XORModel> ("XOR1");
    Model* XOR_2 = Model::create<XORModel> ("XOR2");
    Model* MEM_MODEL = Model::create<MemoryModel> ("M");

};

#endif //CSC_454_HW_4A_HW3MODEL_H
