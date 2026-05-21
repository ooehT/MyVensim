#ifndef FLOW_HPP
#define FLOW_HPP

#include <string>
#include "System.hpp"

class Flow {
    protected:
        string name;
        System* input;
        System* output;

    public:
        Flow();
        Flow(string name, System* input, System* output);
        Flow(const Flow &f);
        Flow &operator=(const Flow &f); 
        virtual ~Flow();
        virtual double execute() = 0;
        void setSource(System* input);
        System* getSource() const;
        void setTarget(System* output);
        System* getTarget() const;
        string getName() const;
        void setName(const string &value);
        void removeSource();
        void removeTarget();

};

#endif