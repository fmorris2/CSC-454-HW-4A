//
// Created by freddy on 11/6/17.
//

#include "NetworkModel.h"

NetworkModel::NetworkModel() {

}

void NetworkModel::set_debug_mode(bool mode) {
    Model::set_debug_mode(mode);
    for(Model* m : sub_models) {
        m->set_debug_mode(mode);
    }
}