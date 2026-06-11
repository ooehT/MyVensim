#ifndef SYSTEMIMPL_HPP
#define SYSTEMIMPL_HPP

#include "System.hpp"

class SystemImpl : public System {
private:
    double value;
    string name;

public:
    SystemImpl();
    SystemImpl(string name, double value);

    SystemImpl(const SystemImpl&);
    SystemImpl& operator=(const SystemImpl&);

    virtual ~SystemImpl();

    string getName() const;
    void setName(const string&);

    double getValue() const;
    void setValue(double);
};

#endif