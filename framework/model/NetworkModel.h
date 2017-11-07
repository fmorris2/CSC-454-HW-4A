//
// Created by freddy on 11/6/17.
//

#ifndef CSC_454_HW_4A_NETWORKMODEL_H
#define CSC_454_HW_4A_NETWORKMODEL_H

#include <vector>
#include "Model.h"
#include "Coupling.h"
class NetworkModel : public Model {
public:
    vector<string> lambda();
    void delta(vector<char> input);

    //abstract methods
    virtual vector<Model*> init_sub_models() = 0;
    virtual vector<Coupling> init_couplings() = 0;

    void init(string model_name);

    //setters
    void set_debug_mode(bool mode);
protected:
    vector<Model*> sub_models;
    vector<Coupling> couplings;

private:
    vector<string> route_output(Model* model, vector<string> output);
    void route_network_input(vector<char> input);
};

#endif //CSC_454_HW_4A_NETWORKMODEL_H
