#include "model.hpp"
#include <algorithm>

Model::Model() {}

Model::~Model() {}

void Model::execute(double start, double end, double increment)
{
    vector<double> values;
    System *source;
    System *target;
    int j = 0;

    for (double time = start; time < end; time += increment)
    {
        for (vector<Flow *>::iterator it = flows.begin(); it != flows.end(); ++it)
        {
            values.push_back((*it)->equation());
        }

        for (vector<Flow *>::iterator it = flows.begin(); it != flows.end(); ++it)
        {
            source = (*it)->getSource();
            source->setValue(source->getValue() - values[j]);
            target = (*it)->getTarget();
            target->setValue(target->getValue() + values[j]);
            j++;
        }
    }
}

vector<Flow *> Model::getFlows() const
{
    return flows;
}

vector<System *> Model::getSystems() const
{
    return sys;
}

string Model::getName() const
{
    return name;
}

void Model::setName(const string &value)
{
    name = value;
}

void Model::add(System *system)
{
    sys.push_back(system);
}

void Model::add(Flow *flow)
{
    flows.push_back(flow);
}

bool Model::remove(System *system)
{
    if (system != NULL)
    {
        vector<System *>::iterator itSystem;
        itSystem = find(sys.begin(), sys.end(), system);
        sys.erase(itSystem);
        return true;
    }
    return false;
}

bool Model::remove(Flow *flow)
{
    if (flow != nullptr)
    {
        vector<Flow *>::iterator itFlow;
        itFlow = find(flows.begin(), flows.end(), flow);
        flows.erase(itFlow);
        return true;
    }
    return false;
}

Model& Model::operator=(const Model& copy)
{
    if (this == &copy)
        return *this;

    name = copy.name;
    sys = copy.sys;
    flows = copy.flows;

    return *this;
}
Model::Model(const Model& copy)
{
    name = copy.name;
    sys = copy.sys;
    flows = copy.flows;
}