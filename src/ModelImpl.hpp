/**
 * @file ModelImpl.hpp
 * @brief Implementação concreta da interface Model.
 */
#ifndef MODELIMPL_HPP
#define MODELIMPL_HPP

#include "Model.hpp"


#include <vector>


#include <string>
/**
 * @class ModelImpl
 * @brief Implementação concreta de um modelo de simulação.
 *
 * Gerencia conjuntos de sistemas e fluxos e executa
 * a evolução do modelo ao longo do tempo.
 *
 * Implementa todos os métodos definidos pela interface Model.
 */
class ModelImpl : public Model
{
private:
    /**
     * @brief Lista de fluxos pertencentes ao modelo.
     */
    std::vector<Flow *> flows;
    /**
     * @brief Lista de sistemas pertencentes ao modelo.
     */
    std::vector<System *> systems;
    /**
     * @brief Nome identificador do modelo.
     */

    std::string name;

public:
    /**
     * @brief Construtor padrão.
     */
    ModelImpl();
    /**
     * @brief Construtor de cópia.
     *
     * @param copy Modelo que será copiado.
     */
    ModelImpl(const ModelImpl &);
    /**
     * @brief Operador de atribuição.
     *
     * @param copy Modelo que será atribuído.
     *
     * @return Referência para o próprio objeto.
     */
    ModelImpl &operator=(const ModelImpl &);
    /**
     * @brief Destrutor.
     */
    virtual ~ModelImpl();

    /**
     * @brief Executa a simulação.
     *
     * @param start Tempo inicial.
     * @param end Tempo final.
     * @param increment Passo de tempo.
     */
    void execute(double start,
                 double end,
                 double increment);

    /**
     * @brief Adiciona um sistema ao modelo.
     *
     * @param system Sistema adicionado.
     */
    void add(System *s);
    /**
     * @brief Adiciona um fluxo ao modelo.
     *
     * @param flow Fluxo adicionado.
     */
    void add(Flow *f);
    /**
     * @brief Remove um sistema.
     *
     * @param system Sistema removido.
     *
     * @return true se removido.
     */
    bool remove(System *s);

    /**
     * @brief Remove um fluxo.
     *
     * @param flow Fluxo removido.
     *
     * @return true se removido.
     */
    bool remove(Flow *f);
        /**
        * @brief Obtém o nome do modelo.
        *
        * @return Nome do modelo.
        */
    std::string getName() const;
    /**
     * @brief Define o nome do modelo.
     *
     * @param name Novo nome.
     */
    void setName(const std::string &);
};

#endif