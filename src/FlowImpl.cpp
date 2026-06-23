#include "FlowImpl.hpp"

FlowImpl::FlowImpl()
{
    name = "";
    source = nullptr;
    target = nullptr;
}

FlowImpl::FlowImpl(std::string name,
                   System* source,
                   System* target)
{
    this->name = name;
    this->source = source;
    this->target = target;
}

FlowImpl::FlowImpl(const FlowImpl& f)
{
    name = f.name;
    source = f.source;
    target = f.target;
}

FlowImpl& FlowImpl::operator=(const FlowImpl& f)
{
    if(this == &f)
        return *this;

    name = f.name;
    source = f.source;
    target = f.target;

    return *this;
}

FlowImpl::~FlowImpl()
{
}

void FlowImpl::setSource(System* source)
{
    this->source = source;
}

System* FlowImpl::getSource() const
{
    return source;
}

void FlowImpl::setTarget(System* target)
{
    this->target = target;
}

System* FlowImpl::getTarget() const
{
    return target;
}

std::string FlowImpl::getName() const
{
    return name;
}

void FlowImpl::setName(const std::string& value)
{
    name = value;
}

void FlowImpl::removeSource()
{
    source = nullptr;
}

void FlowImpl::removeTarget()
{
    target = nullptr;
}