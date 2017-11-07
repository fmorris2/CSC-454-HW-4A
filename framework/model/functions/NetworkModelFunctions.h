//
// Created by freddy on 11/6/17.
//

#ifndef CSC_454_HW_4A_NETWORKMODELFUNTIONS_H
#define CSC_454_HW_4A_NETWORKMODELFUNTIONS_H

#include "ModelFunctions.h"
#include "../NetworkModel.h"
class NetworkModelFunctions : public ModelFunctions {
public:
    NetworkModelFunctions();
    NetworkModelFunctions(NetworkModel* model);
    vector<string> lambda();
    void delta(vector<char> input);

    NetworkModel* network_model;
private:
    vector<string> route_output(Model* model, vector<string> output);
};

#endif //CSC_454_HW_4A_NETWORKMODELFUNTIONS_H
