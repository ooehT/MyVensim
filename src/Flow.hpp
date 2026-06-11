/**
 * @file Flow.hpp
 * @brief Interface abstrata que representa um fluxo entre sistemas.
 */
#ifndef FLOW_HPP
#define FLOW_HPP

#include <string>

/**
 * @class Flow
 * @brief Interface que define um fluxo da simulação.
 *
 * Um Flow representa uma transferência de valores entre dois sistemas.
 * Possui um sistema de origem, um sistema de destino e uma equação
 * responsável por calcular a taxa de transferência.
 *
 * As classes concretas devem implementar o cálculo da equação.
 */
class System;

class Flow
{
public:
    /**
     * @brief Destrutor virtual.
     *
     * Permite a destruição correta de objetos derivados.
     */
    virtual ~Flow() {}
    /**
     * @brief Calcula a taxa do fluxo.
     *
     * Método abstrato que representa a regra matemática
     * do fluxo.
     *
     * @return Valor calculado pela equação do fluxo.
     */
    virtual double equation() = 0;
    /**
     * @brief Define o sistema de origem do fluxo.
     *
     * @param source Sistema de origem.
     */
    virtual void setSource(System *) = 0;
    /**
     * @brief Retorna o sistema de origem.
     *
     * @return Ponteiro para o sistema de origem.
     */
    virtual System *getSource() const = 0;
    /**
     * @brief Define o sistema de destino do fluxo.
     *
     * @param target Sistema de destino.
     */

    virtual void setTarget(System *) = 0;
    /**
     * @brief Retorna o sistema de destino.
     *
     * @return Ponteiro para o sistema de destino.
     */
    virtual System *getTarget() const = 0;
    /**
     * @brief Retorna o nome do fluxo.
     *
     * @return Nome identificador do fluxo.
     */
    virtual std::string getName() const = 0;
    /**
     * @brief Define o nome do fluxo.
     *
     * @param name Novo nome do fluxo.
     */
    virtual void setName(const std::string &) = 0;
    /**
     * @brief Remove a referência ao sistema de origem.
     */
    virtual void removeSource() = 0;
    /**
     * @brief Remove a referência ao sistema de destino.
     */
    virtual void removeTarget() = 0;
};

#endif