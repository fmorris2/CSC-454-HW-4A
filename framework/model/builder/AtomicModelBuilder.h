//
// Created by freddy on 11/6/17.
//

#ifndef CSC_454_HW_4A_ATOMICMODELBUILDER_H
#define CSC_454_HW_4A_ATOMICMODELBUILDER_H

#include "ModelBuilder.h"
#include "../AtomicModel.h"
class AtomicModelBuilder : public ModelBuilder {
    virtual ModelFunctions* model_functions(AtomicModel* model) = 0;
};
#endif //CSC_454_HW_4A_ATOMICMODELBUILDER_H
