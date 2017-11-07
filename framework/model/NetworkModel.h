//
// Created by freddy on 11/6/17.
//

#ifndef CSC_454_HW_4A_NETWORKMODEL_H
#define CSC_454_HW_4A_NETWORKMODEL_H

#include <vector>
#include "Model.h"
class NetworkModel : public Model {
public:
    NetworkModel();

    vector<Model*> sub_models;
    vector<tuple<Model*, Model*>> couplings;

    //setters
    void set_debug_mode(bool mode);

private:
};

#endif //CSC_454_HW_4A_NETWORKMODEL_H
