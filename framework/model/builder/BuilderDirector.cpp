//
// Created by freddy on 11/6/17.
//

#include "BuilderDirector.h"

void BuilderDirector::set_builder(ModelBuilder *builder) {
    this->builder = builder;
}

Model* BuilderDirector::get_model() {
    //TODO CLEAR MEMORY
    Model* model = builder->get_base_model();

    model->set_model_functions(builder->model_functions(model));
    model->set_internal_ticks(builder->get_internal_ticks());
    model->set_output_token_set(builder->output_token_set());
    model->set_receives_external_input(builder->receives_external_input());
    model->set_model_name(builder->get_model_name());

    return model;
}
void BuilderDirector::cleanup() {

}