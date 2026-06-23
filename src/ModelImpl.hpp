#ifndef MODELIMPL_HPP
#define MODELIMPL_HPP

#include "Model.hpp"
#include "System.hpp"
#include "Flow.hpp"

#include <vector>
#include <string>

class ModelImpl : public Model
{
protected:
    /*
     * Identificador do modelo
     */
    std::string name;

    /*
     * Estruturas internas
     */
    std::vector<System *> systems;

    std::vector<Flow *> flows;
    /*
     * Registro global de modelos
     */
    static std::vector<Model *> models;

public:
    /*
     * Construtores
     */
    ModelImpl();

    ModelImpl(const std::string &name);

    ModelImpl(const ModelImpl &rhs);

    /*
     * Operador de atribuição
     */
    ModelImpl &operator=(const ModelImpl &rhs);

    /*
     * Destrutor
     */
    virtual ~ModelImpl();

    /*
     * Factory de modelos
     */
    static Model *createModel(const std::string &name);

    /*
     * Factory de sistemas
     */
    System *createSystem(std::string name,double value) override;

    /*
     * Execução
     */
    void execute(double start,double end,double increment) override;

    /*
     * Remoções
     */
    bool deleteSystem(System*);

    bool deleteFlow(Flow*);

    /*
     * Nome
     */
    std::string getName() const override;

    void setName(const std::string &name) override;

    /*
     * Iteradores de sistemas
     */
    std::vector<System *>::iterator
    beginSystems() override;

    std::vector<System *>::iterator
    endSystems() override;

    /*
     * Iteradores de fluxos
     */
    std::vector<Flow *>::iterator
    beginFlows() override;

    std::vector<Flow *>::iterator
    endFlows() override;

protected:
    /*
     * Registro interno
     */

    void add(System *system);

    void add(Flow *flow);

public:
    friend class Model;
    friend class Unit_Model;
};

#endif
