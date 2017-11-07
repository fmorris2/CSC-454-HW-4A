//
// Created by freddy on 11/6/17.
//

#ifndef CSC_454_HW_4A_MODELFUNCTIONS_H
#define CSC_454_HW_4A_MODELFUNCTIONS_H

#include <vector>
#include <string>
#include "../Model.h"
using namespace std;
class ModelFunctions {
public:
    ModelFunctions();
    virtual vector<string> lambda() = 0;
    virtual void delta(vector<char> input) = 0;
    virtual string get_state_string() = 0;
protected:
};

#endif //CSC_454_HW_4A_MODELFUNCTIONS_H
