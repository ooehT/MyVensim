#include "flow.hpp"

Flow::Flow() {
    this->name = "Default";
    this->source = NULL;
    this->target = NULL;
}

Flow::Flow(string name, System *source, System *target) {
    this->name = name;
    this->source = source;
    this->target = target;
}

Flow::~Flow() {}

void Flow::setTarget(System *target) {
    this->target = target;
}

void Flow::setSource(System *source) {
    this->source = source;
}

string Flow::getName() const {
    return name;
}

void Flow::setName(const string &value) {
    name = value;
}

System *Flow::getSource() const {
    return source;
}

System *Flow::getTarget() const {
    return target;
}

Flow::Flow(const Flow &f) {
    this->name = f.getName();
    this->source = f.getSource();
    this->target = f.getTarget();
}

Flow &Flow::operator=(const Flow &f) {
    if (&f == this) return (*this);
    
    this->name = f.name;
    this->source = f.source;
    this->target = f.target;
    
    return *this;
}