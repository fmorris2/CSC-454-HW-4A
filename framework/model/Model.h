//
// Created by freddy on 11/3/17.
//

#ifndef CSC_454_HW_4A_MODEL_H
#define CSC_454_HW_4A_MODEL_H

#include <iostream>
#include <string>
#include <vector>
class ModelFunctions;
using namespace std;
class Model {
public:
    vector <string> tick();
    vector <string> execute_lambda();
    void add_to_input_bag(char input);
    void execute_delta();
    void debug(string str);
    char get_input_symbol_for_output(string output);
    void reset_input_and_output();

    //setters
    virtual void set_debug_mode(bool mode);

    //getters
    string get_model_name();
    int get_tick();
    bool is_running = true;

    //factory method
    template<typename T>
    static Model* create(string model_name) {
        T* t = new T();
        Model* m = dynamic_cast<Model*>(t);
        m->init(model_name);
        return t;
    }

    virtual void init(string model_name);

protected:
    void log(string str);

    vector<char> input_symbol_set;
    vector <string> output_token_set;
    ModelFunctions *model_functions;
    bool receives_external_input;
    int internal_ticks;

    //abstract methods
    virtual vector<char> init_input_symbol_set() = 0;
    virtual vector <string> init_output_token_set() = 0;
    virtual bool init_receives_external_input() = 0;
    virtual int init_internal_ticks() = 0;

    //functions
    virtual vector<string> lambda() = 0;
    virtual void delta(vector<char> input) = 0;
    virtual string get_state_string() = 0;

    vector<char> input;
    vector<string> output;
private:
    vector<char> parse_input();
    void execute_delta_once();

    string model_name;
    bool debug_mode;
    int current_tick = 1;
};

#endif //CSC_454_HW_4A_MODEL_H
