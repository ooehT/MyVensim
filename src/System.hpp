#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <string>

using namespace std;

class System
{
protected:
    double value;
    string name;

public:
    System();
    System(string name, double value);
    virtual ~System();
    System &operator=(const System &);
    System(const System &sys);
    string getName() const;
    void setName(const string &value);
    double getValue() const;
    void setValue(double value);
    friend ostream &operator<<(ostream &out, const System &s);
};

#endif