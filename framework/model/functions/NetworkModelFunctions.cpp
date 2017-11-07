//
// Created by freddy on 11/6/17.
//

#include "NetworkModelFunctions.h"
#include <iostream>

NetworkModelFunctions::NetworkModelFunctions() {

}

NetworkModelFunctions::NetworkModelFunctions(NetworkModel *model) {
    this->network_model = model;
}

void NetworkModelFunctions::delta(vector<char> input) {

}

vector<string> NetworkModelFunctions::lambda() {
    vector<string> network_output;
    network_model->debug("lambda for " + network_model->get_model_name());
    for(Model* m : network_model->sub_models) {
        vector<string> model_output = route_output(m, m->execute_lambda());
        for(string token : model_output) {
            network_output.push_back(token);
        }
    }

    return network_output;
}

vector<string> NetworkModelFunctions::route_output(Model* model, vector<string> output) {
    vector<string> network_output;

    for(int i = 0; i < network_model->couplings.size(); i++) {
        tuple<Model*, Model*> coupling = network_model->couplings[i];
        if(get<0>(coupling) == model) {
            if(get<1>(coupling) == 0) { //leads to network output
                for(string token : output) {
                    network_output.push_back(token);
                }
            }
            else { //leads to input of other sub model
                network_model->debug("routing output from " + get<0>(coupling)->get_model_name() + " to " + get<1>(coupling)->get_model_name());
                for(string token : output) {
                    char input_token = get<1>(coupling)->get_input_symbol_for_output(token);
                    get<1>(coupling)->add_to_input_bag(input_token);
                }
            }
        }
    }

    return network_output;
}