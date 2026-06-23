/**
 * @file Exponential.hpp
 * @brief Declaração da classe Exponential.
 */
#ifndef EXPONENTIAL_HPP
#define EXPONENTIAL_HPP

#include "../../src/FlowImpl.hpp"
#include <string>

/**
 * @class Exponential
 * @brief Representa um fluxo com comportamento exponencial.
 *
 * A classe Exponential implementa um fluxo cuja taxa de transferência
 * depende proporcionalmente do valor atual do sistema de origem.
 *
 * A equação utilizada é:
 *
 * fluxo = origem * 0.01
 *
 * Esta classe herda a estrutura básica de FlowImpl e sobrescreve
 * apenas o cálculo da equação.
 */
class Exponential : public FlowImpl
{
public:
    /**
     * @brief Construtor padrão.
     *
     * Inicializa um fluxo exponencial sem sistemas associados.
     */
    Exponential();
    /**
     * @brief Construtor parametrizado.
     *
     * @param name Nome identificador do fluxo.
     * @param source Sistema de origem.
     * @param target Sistema de destino.
     */
    Exponential(const std::string &name, System *source, System *target);

    /**
     * @brief Construtor de cópia.
     *
     * @param copy Fluxo exponencial que será copiado.
     */
    Exponential(const Exponential &copy);
    /**
     * @brief Operador de atribuição.
     *
     * @param copy Fluxo exponencial que será atribuído.
     *
     * @return Referência para o próprio objeto.
     */
    Exponential &operator=(const Exponential &);
    /**
     * @brief Destrutor.
     */
    virtual ~Exponential();/**
                                    * @brief Calcula a taxa exponencial do fluxo.
                                    *
                                    * Utiliza o valor atual do sistema de origem
                                    * para calcular a transferência.
                                    *
                                    * @return Valor calculado da taxa do fluxo.
                                    */
    virtual double equation() override;
};

#endif