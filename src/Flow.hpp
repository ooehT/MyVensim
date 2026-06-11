#ifndef FLOW_HPP
#define FLOW_HPP

#include <string>

class System;

class Flow {
public:
    virtual ~Flow() {}

    virtual double equation() = 0;

    virtual void setSource(System*) = 0;
    virtual System* getSource() const = 0;

    virtual void setTarget(System*) = 0;
    virtual System* getTarget() const = 0;

    virtual std::string getName() const = 0;
    virtual void setName(const std::string&) = 0;

    virtual void removeSource() = 0;
    virtual void removeTarget() = 0;
};

#endif