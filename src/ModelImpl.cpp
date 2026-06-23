#include "ModelImpl.hpp"
#include <algorithm>

using namespace std;

ModelImpl::ModelImpl() {}

ModelImpl::~ModelImpl() {}

void ModelImpl::execute(double start, double end, double increment)
{
    std::vector<double> values;
    System *source;
    System *target;
    int j = 0;

    for (double time = start; time < end; time += increment)
    {
        values.clear();
        j = 0;

        for (std::vector<Flow *>::iterator it = flows.begin();
             it != flows.end();
             ++it)
        {
            values.push_back((*it)->equation());
        }

        for (std::vector<Flow *>::iterator it = flows.begin();
             it != flows.end();
             ++it)
        {
            source = (*it)->getSource();
            target = (*it)->getTarget();

            if (source != nullptr)
                source->setValue(source->getValue() - values[j]);

            if (target != nullptr)
                target->setValue(target->getValue() + values[j]);

            j++;
        }
    }
}


std::string ModelImpl::getName() const
{
    return name;
}

void ModelImpl::setName(const std::string &value)
{
    name = value;
}

void ModelImpl::add(System *system)
{
    systems.push_back(system);
}

void ModelImpl::add(Flow *flow)
{
    flows.push_back(flow);
}

bool ModelImpl::remove(System *system)
{
    if (system != nullptr)
    {
        std::vector<System *>::iterator itSystem;
        itSystem = std::find(systems.begin(), systems.end(), system);

        if (itSystem != systems.end())
        {
            systems.erase(itSystem);
            return true;
        }
    }

    return false;
}

bool ModelImpl::remove(Flow *flow)
{
    if (flow != nullptr)
    {
        std::vector<Flow *>::iterator itFlow;
        itFlow = std::find(flows.begin(), flows.end(), flow);

        if (itFlow != flows.end())
        {
            flows.erase(itFlow);
            return true;
        }
    }

    return false;
}

ModelImpl::ModelImpl(const ModelImpl &copy)
{
    name = copy.name;
    systems = copy.systems;
    flows = copy.flows;
}

ModelImpl &ModelImpl::operator=(const ModelImpl &copy)
{
    if (this == &copy)
        return *this;

    name = copy.name;
    systems = copy.systems;
    flows = copy.flows;

    return *this;
}
std::vector<System*>::iterator ModelImpl::beginSystems()
{
    return systems.begin();
}

std::vector<System*>::iterator ModelImpl::endSystems()
{
    return systems.end();
}

std::vector<Flow*>::iterator ModelImpl::beginFlows()
{
    return flows.begin();
}

std::vector<Flow*>::iterator ModelImpl::endFlows()
{
    return flows.end();
}