#include "ModelImpl.hpp"
#include "SystemImpl.hpp"

using namespace std;

std::vector<Model*> ModelImpl::models;

ModelImpl::ModelImpl() {}

ModelImpl::~ModelImpl() {}

Model* Model::createModel(std::string name)
{
    return ModelImpl::createModel(name);
}

Model* ModelImpl::createModel(const std::string& name)
{
    Model* model = new ModelImpl();

    model->setName(name);

    models.push_back(model);

    return model;
}

System* ModelImpl::createSystem(
    std::string name,
    double value
)
{
    System* system = new SystemImpl(
        name,
        value
    );

    add(system);

    return system;
}
bool Model::deleteModel(std::string name)
{
    for(auto it = ModelImpl::models.begin();
        it != ModelImpl::models.end();
        ++it)
    {
        if((*it)->getName() == name)
        {
            delete *it;

            ModelImpl::models.erase(it);

            return true;
        }
    }

    return false;
}

void ModelImpl::execute(double start,
                        double end,
                        double increment)
{
    std::vector<double> values;
    System* source;
    System* target;
    int j = 0;

    for(double time = start;
        time < end;
        time += increment)
    {
        values.clear();
        j = 0;

        for(std::vector<Flow*>::iterator it =
                flows.begin();
            it != flows.end();
            ++it)
        {
            values.push_back(
                (*it)->equation()
            );
        }

        for(std::vector<Flow*>::iterator it =
                flows.begin();
            it != flows.end();
            ++it)
        {
            source = (*it)->getSource();
            target = (*it)->getTarget();

            if(source != nullptr)
            {
                source->setValue(
                    source->getValue()
                    - values[j]
                );
            }

            if(target != nullptr)
            {
                target->setValue(
                    target->getValue()
                    + values[j]
                );
            }

            j++;
        }
    }
}
std::string ModelImpl::getName() const
{
    return name;
}

void ModelImpl::setName(
    const std::string& value
)
{
    name = value;
}

void ModelImpl::add(System* system)
{
    systems.push_back(system);
}

void ModelImpl::add(Flow* flow)
{
    flows.push_back(flow);
}
bool ModelImpl::deleteFlow(Flow* flow)
{
    if(flow != nullptr)
    {
        for(auto it = flows.begin();
            it != flows.end();
            ++it)
        {
            if(*it == flow)
            {
                flows.erase(it);
                return true;
            }
        }
    }

    return false;
}
bool ModelImpl::deleteSystem(System* system)
{
    if(system != nullptr)
    {
        for(auto it = systems.begin();
            it != systems.end();
            ++it)
        {
            if(*it == system)
            {
                systems.erase(it);
                return true;
            }
        }
    }

    return false;
}

ModelImpl::ModelImpl(
    const ModelImpl& copy
)
{
    name = copy.name;
    systems = copy.systems;
    flows = copy.flows;
}
ModelImpl& ModelImpl::operator=(
    const ModelImpl& copy
)
{
    if(this == &copy)
        return *this;

    name = copy.name;
    systems = copy.systems;
    flows = copy.flows;

    return *this;
}
std::vector<System*>::iterator
ModelImpl::beginSystems()
{
    return systems.begin();
}

std::vector<System*>::iterator
ModelImpl::endSystems()
{
    return systems.end();
}

std::vector<Flow*>::iterator
ModelImpl::beginFlows()
{
    return flows.begin();
}

std::vector<Flow*>::iterator
ModelImpl::endFlows()
{
    return flows.end();
}