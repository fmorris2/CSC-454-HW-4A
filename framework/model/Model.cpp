//
// Created by freddy on 11/3/17.
//

#include "Model.h"
#include <algorithm>
#include <iostream>
#include "functions/ModelFunctions.h"

string SENTINEL = "halt.";

void Model::add_to_input_bag(char input) {
    this->input.push_back(input);
}

vector<string> Model::tick() {
    vector<string> output;

    if(receives_external_input) {
        input = parse_input();
    }

    for(int i = 0; i < internal_ticks; i++) {
        execute_lambda();
        execute_delta_once();
    }

    return output;
}

vector<string> Model::execute_lambda() {
    vector<string> output;
    debug ("lambda is being executed");
    output = model_functions->lambda();
    if(current_tick % internal_ticks == 0) {
        debug("state at internal tick #" + to_string(current_tick) + ": " + model_functions->get_state_string());
    }

    return output;
}

void Model::execute_delta_once() {
    debug("delta is being executed");
    model_functions->delta(input);
    current_tick++;
}

vector<char> Model::parse_input() {
    vector<char> input;
    string input_string;
    cin >> input_string;

    if(input_string.compare(SENTINEL) == 0) {
        debug(model_name + " halted.");
        is_running = false;
        return input;
    }

    for(char symbol : input_string) {
        if(std::find(input_symbol_set.begin(), input_symbol_set.end(), symbol) != input_symbol_set.end()) {
            input.push_back(symbol);
        }
    }

    return input;
}

char Model::get_input_symbol_for_output(string output) {
    for(int i = 0; i < output_token_set.size(); i++) {
        if(output_token_set[i].compare(output_token_set[i]) == 0) {
            return input_symbol_set[i];
        }
    }
    return 0;
}

void Model::log(string str) {
    cout << "[" << model_name << "] - " << str << endl;
}

void Model::debug(string str) {
    if(debug_mode) {
        log(str);
    }
}

int Model::get_tick() {
    return current_tick;
}

string Model::get_model_name() {
    return model_name;
}

//setters
void Model::set_debug_mode(bool mode) {
    this->debug_mode = mode;
}

void Model::set_receives_external_input(bool value) {
    this->receives_external_input = value;
}

void Model::set_input_symbol_set(vector<char> set) {
    this->input_symbol_set = set;
}

void Model::set_output_token_set(vector <string> set) {
    this->output_token_set = set;
}

void Model::set_internal_ticks(int ticks) {
    this->internal_ticks = ticks;
}

void Model::set_model_functions(ModelFunctions *functions) {
    this->model_functions = functions;
}

void Model::set_model_name(string name) {
    this->model_name = name;
}