#include "model.hpp"
#include <algorithm>

Model::Model() {}

Model::~Model() {}

void Model::execute(double start, double end, double increment) {
    vector<double> values;
    System* input;
    System* output;
    int j = 0;
    
    for (double time = start; time < end; time += increment) {
        for (vector<Flow*>::iterator it = flows.begin(); it != flows.end(); ++it) {
            values.push_back((*it)->execute());
        }
        
        for (vector<Flow*>::iterator it = flows.begin(); it != flows.end(); ++it) {
            input = (*it)->getSource();
            input->setValue(input->getValue() - values[j]);
            output = (*it)->getTarget();
            output->setValue(output->getValue() + values[j]);
            j++;
        }
    }
}

vector<Flow*> Model::getFlows() const {
    return flows;
}

vector<System*> Model::getSystems() const {
    return sys;
}

string Model::getName() const {
    return name;
}

void Model::setName(const string &value) {
    name = value;
}

void Model::add(System* system) {
    sys.push_back(system);
}

void Model::add(Flow* flow) {
    flows.push_back(flow);
}

bool Model::remove(System* system) {
    if (system != NULL) {
        vector<System*>::iterator itSystem;
        itSystem = find(sys.begin(), sys.end(), system);
        sys.erase(itSystem);
        return true;
    }
    return false;
}

bool Model::remove(Flow* flow) {
    if (flow != nullptr) {
        vector<Flow*>::iterator itFlow;
        itFlow = find(flows.begin(), flows.end(), flow);
        flows.erase(itFlow);
        return true;
    }
    return false;
}

Model &Model::operator=(Model &copy) {
    if (&copy == this) return (*this);
    
    System* saux;
    for (vector<System*>::iterator it = copy.getSystems().begin(); it != copy.getSystems().end(); ++it) {
        saux = (*it);
        this->add(saux);
    }
    
    Flow* faux;
    for (vector<Flow*>::iterator it = copy.getFlows().begin(); it != copy.getFlows().end(); ++it) {
        faux = (*it);
        this->add(faux);
    }
    
    return (*this);
}

Model::Model(const Model &copy) {
    this->setName(copy.getName());
    
    System* saux;
    for (vector<System*>::iterator it = copy.getSystems().begin(); it != copy.getSystems().end(); ++it) {
        saux = (*it);
        this->add(saux);
    }
    
    Flow* faux;
    for (vector<Flow*>::iterator it = copy.getFlows().begin(); it != copy.getFlows().end(); ++it) {
        faux = (*it);
        this->add(faux);
    }
}