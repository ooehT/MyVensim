#include "SystemImpl.hpp"

SystemImpl::SystemImpl()
{
    name = "";
    value = 0;
}

SystemImpl::SystemImpl(string name, double value)
{
    this->name = name;
    this->value = value;
}

SystemImpl::SystemImpl(const SystemImpl &sys)
{
    name = sys.name;
    value = sys.value;
}

SystemImpl &SystemImpl::operator=(const SystemImpl &sys)
{
    if (this == &sys)
        return *this;

    name = sys.name;
    value = sys.value;

    return *this;
}

SystemImpl::~SystemImpl(){}

string SystemImpl::getName() const{
    return name;
}

void SystemImpl::setName(const string &value)
{
    name = value;
}

double SystemImpl::getValue() const
{
    return value;
}

void SystemImpl::setValue(double value)
{
    this->value = value;
}