#include "flow.hpp"

Flow::Flow() {
    this->name = "Default";
    this->input = NULL;
    this->output = NULL;
}

Flow::Flow(string name, System *input, System *output) {
    this->name = name;
    this->input = input;
    this->output = output;
}

Flow::~Flow() {}

void Flow::setTarget(System *output) {
    this->output = output;
}

void Flow::setSource(System *input) {
    this->input = input;
}

string Flow::getName() const {
    return name;
}

void Flow::setName(const string &value) {
    name = value;
}

System *Flow::getSource() const {
    return input;
}

System *Flow::getTarget() const {
    return output;
}

Flow::Flow(const Flow &f) {
    this->name = f.getName();
    this->input = f.getSource();
    this->output = f.getTarget();
}

Flow &Flow::operator=(const Flow &f) {
    if (&f == this) return (*this);
    
    this->name = f.name;
    this->input = f.input;
    this->output = f.output;
    
    return *this;
}