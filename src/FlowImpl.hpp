#ifndef FLOWIMPL_HPP
#define FLOWIMPL_HPP

#include "Flow.hpp"
#include "System.hpp"

class FlowImpl : public Flow {
protected:
    std::string name;
    System* source;
    System* target;

public:
    FlowImpl();
    FlowImpl(std::string, System*, System*);

    FlowImpl(const FlowImpl&);
    FlowImpl& operator=(const FlowImpl&);

    virtual ~FlowImpl();

    void setSource(System*);
    System* getSource() const;

    void setTarget(System*);
    System* getTarget() const;

    std::string getName() const;
    void setName(const std::string&);

    void removeSource();
    void removeTarget();
};

#endif