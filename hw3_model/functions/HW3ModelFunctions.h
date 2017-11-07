//
// Created by freddy on 11/6/17.
//

#ifndef CSC_454_HW_4A_HW3MODELFUNCTIONS_H
#define CSC_454_HW_4A_HW3MODELFUNCTIONS_H

#include "../../framework/model/functions/NetworkModelFunctions.h"
class HW3ModelFunctions : public NetworkModelFunctions {
public:
    HW3ModelFunctions(NetworkModel* model);
    string get_state_string();
};
#endif //CSC_454_HW_4A_HW3MODELFUNCTIONS_H
