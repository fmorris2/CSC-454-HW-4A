//
// Created by freddy on 11/3/17.
//

#ifndef CSC_454_HW_4A_MODEL_H
#define CSC_454_HW_4A_MODEL_H

#include <tuple>
#include <string>
#include <vector>
class ModelFunctions;
using namespace std;
class Model {
public:
    vector <string> tick();
    vector <string> execute_lambda();
    void add_to_input_bag(char input);
    void debug(string str);
    char get_input_symbol_for_output(string output);

    //getters
    string get_model_name();
    int get_tick();
    bool is_running = true;

    //setters
    void set_debug_mode(bool mode);
    void set_model_name(string name);
    void set_input_symbol_set(vector<char> set);
    void set_output_token_set(vector <string> set);
    void set_model_functions(ModelFunctions *functions);
    void set_receives_external_input(bool value);
    void set_internal_ticks(int ticks);

protected:
    void log(string str);

    vector<char> input_symbol_set;
    vector <string> output_token_set;
    ModelFunctions *model_functions;
    bool receives_external_input;
    int internal_ticks;
private:
    vector<char> parse_input();

    void execute_delta_once();

    string model_name;
    vector<char> input;
    bool debug_mode;
    int current_tick;
};

#endif //CSC_454_HW_4A_MODEL_H
