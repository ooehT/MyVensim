#ifndef FLOW_HPP
#define FLOW_HPP

#include <string>
#include "System.hpp"

class Flow {
    protected:
        string name;
        System* source;
        System* target;

    public:
        Flow();
        Flow(string name, System* source, System* target);
        Flow(const Flow &f);
        Flow &operator=(const Flow &f); 
        virtual ~Flow();
        virtual double execute() = 0;
        void setSource(System* source);
        System* getSource() const;
        void setTarget(System* target);
        System* getTarget() const;
        string getName() const;
        void setName(const string &value);
        void removeSource();
        void removeTarget();

};

#endif