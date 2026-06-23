#ifndef MODEL_HPP
#define MODEL_HPP

#include <string>
#include <vector>

class System;
class Flow;

class Model
{
public:
    virtual ~Model() {}

    /*
     * Factory de modelos
     */
    static Model *createModel(std::string name);
    static bool deleteModel(std::string name);
    /*
     * Execução
     */
    virtual void execute(double start,double end, double increment) = 0;

    /*
     * Factory de fluxos
     */
    template <typename T_FLOW_IMPL>
    Flow *createFlow(
        std::string name,
        System *source = nullptr,
        System *target = nullptr)
    {
        Flow *flow = new T_FLOW_IMPL(
            name,
            source,
            target);

        add(flow);

        return flow;
    }

    /*
     * Factory de sistemas
     */
    virtual System *createSystem(
        std::string name,
        double value) = 0;

    /*
     * Remoções
     */
    virtual bool deleteFlow(
        Flow *) = 0;

    virtual bool deleteSystem(
        System *) = 0;

    /*
     * Nome do modelo
     */
    virtual std::string getName() const = 0;

    virtual void setName(
        const std::string &name) = 0;

    /*
     * Iteradores de sistemas
     */
    virtual std::vector<System *>::iterator
    beginSystems() = 0;

    virtual std::vector<System *>::iterator
    endSystems() = 0;

    /*
     * Iteradores de fluxos
     */
    virtual std::vector<Flow *>::iterator
    beginFlows() = 0;

    virtual std::vector<Flow *>::iterator
    endFlows() = 0;

protected:
    /*
     * Registro interno
     */
    virtual void add(Flow *) = 0;

    virtual void add(System*) = 0;

    
    friend class ModelImpl;
};

#endif