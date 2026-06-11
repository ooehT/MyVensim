/**
 * @file Model.hpp
 * @brief Interface abstrata responsável pelo gerenciamento da simulação.
 */

#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include <string>

class System;
class Flow;
/**
 * @class Model
 * @brief Interface que define um modelo de simulação.
 *
 * A classe Model representa a estrutura responsável por armazenar
 * sistemas e fluxos, além de controlar a execução da simulação.
 *
 * É uma interface abstrata que deve ser implementada por classes concretas.
 */

class Model
{
public:
    /**
     * @brief Destrutor virtual.
     *
     * Permite a destruição correta de objetos derivados.
     */
    virtual ~Model() {}
    /**
     * @brief Executa a simulação do modelo.
     *
     * Percorre o intervalo de tempo informado aplicando
     * os fluxos existentes entre os sistemas.
     *
     * @param start Tempo inicial da simulação.
     * @param end Tempo final da simulação.
     * @param increment Intervalo entre cada passo da simulação.
     */
    virtual void execute(double start,
                         double end,
                         double increment) = 0;
    /**
     * @brief Adiciona um sistema ao modelo.
     *
     * @param system Sistema que será adicionado.
     */
    virtual void add(System *s) = 0;
    /**
     * @brief Adiciona um fluxo ao modelo.
     *
     * @param flow Fluxo que será adicionado.
     */
    virtual void add(Flow *f) = 0;
    /**
     * @brief Remove um sistema do modelo.
     *
     * @param system Sistema que será removido.
     *
     * @return true caso o sistema seja removido.
     */
    virtual bool remove(System *s) = 0;
    /**
     * @brief Remove um fluxo do modelo.
     *
     * @param flow Fluxo que será removido.
     *
     * @return true caso o fluxo seja removido.
     */
    virtual bool remove(Flow *f) = 0;
    /**
     * @brief Obtém os sistemas pertencentes ao modelo.
     *
     * @return Vetor contendo os sistemas cadastrados.
     */
    virtual std::vector<System *> getSystems() const = 0;
    /**
     * @brief Obtém os fluxos pertencentes ao modelo.
     *
     * @return Vetor contendo os fluxos cadastrados.
     */
    virtual std::vector<Flow *> getFlows() const = 0;
    /**
     * @brief Retorna o nome do modelo.
     *
     * @return Nome identificador do modelo.
     */

    virtual std::string getName() const = 0;
    /**
     * @brief Define o nome do modelo.
     *
     * @param name Novo nome do modelo.
     */
    virtual void setName(const std::string &) = 0;
};

#endif