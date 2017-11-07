//
// Created by freddy on 11/3/17.
//

#include "Model.h"
#include <algorithm>
#include <iostream>

string SENTINEL = "halt.";

void Model::init(string model_name) {
    internal_ticks = init_internal_ticks();
    input_symbol_set = init_input_symbol_set();
    receives_external_input = init_receives_external_input();
    output_token_set = init_output_token_set();
    this->model_name = model_name;
}

void Model::add_to_input_bag(char input) {
    debug(string("adding ") + input + string(" to input bag"));
    this->input.push_back(input);
}

vector<string> Model::tick() {
    if(receives_external_input) {
        input = parse_input();
    }

    for(int i = 0; i < internal_ticks; i++) {
        output = execute_lambda();
        execute_delta_once();
    }

    return output;
}

void Model::execute_delta() {
    for(int i = 0; i < internal_ticks; i++) {
        execute_delta_once();
    }
}

vector<string> Model::execute_lambda() {
    vector<string> output;
    debug ("lambda is being executed");
    output = lambda();
    if(current_tick % internal_ticks == 0) {
        debug("state at internal tick #" + to_string(current_tick) + ": " + get_state_string());
        debug("output at internal tick#" + to_string(current_tick) + ": ");
        for(string s : output) {
            debug("\t" + s);
        }
    }

    return output;
}

void Model::execute_delta_once() {
    debug("delta is being executed");
    delta(input);
    current_tick++;
}

void Model::reset_input_and_output() {
    input.clear();
    output.clear();
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
        if(output_token_set[i].compare(output) == 0) {
            return input_symbol_set[i];
        }
    }
    return 0;
}

void Model::set_debug_mode(bool mode) {
    debug_mode = mode;
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