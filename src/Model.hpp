#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include <string>

class System;
class Flow;

class Model {
public:
    virtual ~Model() {}

    virtual void execute(double start,
                         double end,
                         double increment) = 0;

    virtual void add(System* s) = 0;
    virtual void add(Flow* f) = 0;

    virtual bool remove(System* s) = 0;
    virtual bool remove(Flow* f) = 0;

    virtual std::vector<System*> getSystems() const = 0;
    virtual std::vector<Flow*> getFlows() const = 0;

    virtual std::string getName() const = 0;
    virtual void setName(const std::string&) = 0;
};

#endif