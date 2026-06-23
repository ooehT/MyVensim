#include "Complex.hpp"

ComplexFlow::ComplexFlow()
    : FlowImpl()
{
}

ComplexFlow::ComplexFlow(std::string name,
                         System* source,
                         System* target)
    : FlowImpl(name, source, target)
{
}

ComplexFlow::ComplexFlow(const ComplexFlow& flow)
    : FlowImpl(flow)
{
}

ComplexFlow& ComplexFlow::operator=(const ComplexFlow& flow)
{
    if(this != &flow)
    {
        FlowImpl::operator=(flow);
    }

    return *this;
}

ComplexFlow::~ComplexFlow()
{
}

double ComplexFlow::equation()
{
    if(getSource() != nullptr)
    {
        return 0.01 * getSource()->getValue();
    }

    return 0.0;
}