#ifndef MODELIMPL_HPP
#define MODELIMPL_HPP

#include "Model.hpp"
#include "System.hpp"
#include "Flow.hpp"

#include <vector>
#include <string>

using namespace std;

class ModelImpl : public Model {
private:
    vector<Flow*> flows;
    vector<System*> systems;
    string name;

public:
    ModelImpl();
    ModelImpl(const ModelImpl&);
    ModelImpl& operator=(const ModelImpl&);
    virtual ~ModelImpl();

    void execute(double start,
                 double end,
                 double increment);

    void add(System* s);
    void add(Flow* f);

    bool remove(System* s);
    bool remove(Flow* f);

    vector<System*> getSystems() const;
    vector<Flow*> getFlows() const;

    string getName() const;
    void setName(const string&);
};

#endif