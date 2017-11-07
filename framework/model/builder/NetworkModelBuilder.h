//
// Created by freddy on 11/6/17.
//

#ifndef CSC_454_HW_4A_NETWORKMODELBUILDER_H
#define CSC_454_HW_4A_NETWORKMODELBUILDER_H

#include <tuple>
#include "ModelBuilder.h"
#include "../NetworkModel.h"
class NetworkModelBuilder : public ModelBuilder {
public:
    virtual vector<Model*> get_sub_models() = 0;
    virtual ModelFunctions* model_functions(NetworkModel* model) = 0;
    virtual vector<tuple<Model*,Model*>> get_couplings() = 0;
};

#endif //CSC_454_HW_4A_NETWORKMODELBUILDER_H
