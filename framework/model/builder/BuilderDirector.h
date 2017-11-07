//
// Created by freddy on 11/6/17.
//

#ifndef CSC_454_HW_4A_BUILDERDIRECTOR_H
#define CSC_454_HW_4A_BUILDERDIRECTOR_H

#include "ModelBuilder.h"
#include "../Model.h"
class BuilderDirector {
    ModelBuilder* builder;

    public:
        void set_builder(ModelBuilder* builder);
        Model* get_model();
        void cleanup();
};

#endif //CSC_454_HW_4A_BUILDERDIRECTOR_H
