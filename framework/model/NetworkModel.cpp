//
// Created by freddy on 11/6/17.
//

#include "NetworkModel.h"

void NetworkModel::init(string model_name) {
    Model::init(model_name);
    sub_models = init_sub_models();
    couplings = init_couplings();
}

void NetworkModel::delta(vector<char> input) {
    //route network input to necessary submodules
    route_network_input(input);

    //call everybodies delta
    for(Model* sub_model : sub_models) {
        sub_model->execute_delta();
        sub_model->reset_input_and_output();
    }
}

void NetworkModel::route_network_input(vector<char> input) {
    for(Coupling c : couplings) {
        if(c.first == 0) {
            debug("Network input being routed to " + c.second->get_model_name());
            for(char token : input) {
                c.second->add_to_input_bag(token);
            }
        }
    }
}

vector<string> NetworkModel::lambda() {
    vector<string> network_output;
    debug("lambda for " + get_model_name());
    for(Model* m : sub_models) {
        vector<string> model_output = route_output(m, m->execute_lambda());
        for(string token : model_output) {
            network_output.push_back(token);
        }
    }

    return network_output;
}

vector<string> NetworkModel::route_output(Model* model, vector<string> output) {
    vector<string> network_output;

    for(int i = 0; i < couplings.size(); i++) {
        Coupling coupling = couplings[i];
        if(coupling.first == model) {
            if(coupling.second == 0) { //leads to network output
                for(string token : output) {
                    network_output.push_back(token);
                }
            }
            else { //leads to input of other sub model
                debug("routing output from " + coupling.first->get_model_name() + " to " + coupling.second->get_model_name());
                for(string token : output) {
                    char input_token = coupling.first->get_input_symbol_for_output(token);
                    debug(string("adding ") + input_token + string(" to input bag for ") + coupling.second->get_model_name());
                    coupling.second->add_to_input_bag(input_token);
                }
            }
        }
    }

    return network_output;
}

void NetworkModel::set_debug_mode(bool mode) {
    Model::set_debug_mode(mode);
    for(Model* m : sub_models) {
        m->set_debug_mode(mode);
    }
}

