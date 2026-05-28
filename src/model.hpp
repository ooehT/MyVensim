#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include <string>
#include "System.hpp"
#include "flow.hpp"

using namespace std;

class Model {
    protected:
        vector<Flow*> flows;
        vector<System*> sys;
        string name;
        
    public:
        Model();
        virtual ~Model();
        Model &operator=(const Model&);
        Model(const Model &copy);
        void execute(double start, double end, double increment);
        
        void add(System* s);
        void add(Flow* f);
        
        bool remove(System*);
        bool remove(Flow*);
        
        //USAR ITERADOR v
        vector<Flow*> getFlows() const;
        vector<System*> getSystems() const;
        //USAR ITERADOR ^
        
        string getName() const;
        void setName(const string &value);
};

#endif