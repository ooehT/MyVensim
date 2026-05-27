/**
 * @file model.hpp
 * @brief Declaração da classe Model, responsável por gerenciar e executar a simulação.
 */

#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include <string>
#include "System.hpp"
#include "flow.hpp"

using namespace std;

/**
 * @class Model
 * @brief Classe container que gerencia múltiplos sistemas e fluxos, executando o cenário de simulação.
 */
class Model {
    protected:
        vector<Flow*> flows;  /**< Vetor contendo os fluxos pertencentes ao modelo. */
        vector<System*> sys;  /**< Vetor contendo os sistemas pertencentes ao modelo. */
        string name;          /**< Nome identificador do modelo. */
        
    public:
        /** @brief Construtor padrão. */
        Model();
        /** @brief Destrutor virtual responsável por liberar a estrutura (se aplicável). */
        virtual ~Model();
        /** @brief Operador de atribuição para cópia profunda de modelos. */
        Model &operator=(Model&);
        /** @brief Construtor de cópia. */
        Model(const Model &copy);
        
        /**
         * @brief Executa a simulação do modelo em um intervalo de tempo determinado.
         * @param start Tempo inicial da simulação.
         * @param end Tempo final da simulação.
         * @param increment O passo de tempo executado a cada iteração.
         */
        void execute(double start, double end, double increment);
        
        /**
         * @brief Adiciona um novo sistema ao ecossistema do modelo.
         * @param s Ponteiro do objeto do tipo System.
         */
        void add(System* s);
        
        /**
         * @brief Adiciona um novo fluxo ao ecossistema do modelo.
         * @param f Ponteiro do objeto do tipo Flow.
         */
        void add(Flow* f);
        
        /**
         * @brief Remove um sistema específico do modelo.
         * @return true se removido com sucesso, false caso contrário.
         */
        bool remove(System*);
        
        /**
         * @brief Remove um fluxo específico do modelo.
         * @return true se removido com sucesso, false caso contrário.
         */
        bool remove(Flow*);
        
        /** @brief Recupera o vetor de fluxos do modelo. */
        vector<Flow*> getFlows() const;
        /** @brief Recupera o vetor de sistemas do modelo. */
        vector<System*> getSystems() const;
        
        /** @brief Getter do nome do modelo. */
        string getName() const;
        /** @brief Setter do nome do modelo. */
        void setName(const string &value);
};

#endif