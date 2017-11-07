//
// Created by freddy on 11/6/17.
//

#ifndef CSC_454_HW_4A_ATOMICMODELFUNCTIONS_H
#define CSC_454_HW_4A_ATOMICMODELFUNCTIONS_H

#include "ModelFunctions.h"
class AtomicModelFunctions : public ModelFunctions {
public:
    AtomicModelFunctions();
    AtomicModelFunctions(Model* model);
protected:
    Model* model;
};

#endif //CSC_454_HW_4A_ATOMICMODELFUNCTIONS_H
