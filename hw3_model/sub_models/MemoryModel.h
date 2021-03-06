//
// Created by freddy on 11/7/17.
//

#ifndef CSC_454_HW_4A_MEMORYMODEL_H
#define CSC_454_HW_4A_MEMORYMODEL_H

#include "../../framework/model/AtomicModel.h"
class MemoryModel : public AtomicModel {
    vector<char> init_input_symbol_set();
    vector <string> init_output_token_set();
    bool init_receives_external_input();
    string get_state_string();

    vector<string> lambda();
    void delta(vector<char> input);

protected:
    int queue[2] = {0,0};
};

#endif //CSC_454_HW_4A_MEMORYMODEL_H
