#ifndef EXPONENTIAL_HPP
#define EXPONENTIAL_HPP

#include "FlowImpl.hpp"
#include "System.hpp"
#include <string>

using namespace std;

class Exponential : public FlowImpl
{
public:
    Exponential();
    Exponential(string name, System* source, System* target);

    Exponential(const Exponential&);
    Exponential& operator=(const Exponential&);

    virtual ~Exponential();

    virtual double equation();
};

#endif