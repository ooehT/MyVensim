/**
 * @file logistic.hpp
 * @brief Declaração da classe Logistic, que representa um fluxo com variação logística.
 */

#ifndef Logistic_HPP
#define Logistic_HPP

#include "FlowImpl.hpp"
#include "System.hpp"

#include <string>

using namespace std;

/**
 * @class Logistic
 * @brief Classe que define um comportamento de fluxo logístico baseado na capacidade do sistema alvo.
 *
 * A classe Logistic herda de Flow e implementa a equação matemática correspondente
 * ao crescimento logístico em sistemas dinâmicos.
 */
class Logistic : public FlowImpl
{
public:
    /**
     * @brief Construtor padrão da classe Logistic.
     */
    Logistic();

    /**
     * @brief Construtor parametrizado.
     * @param name Nome do fluxo.
     * @param source Ponteiro para o sistema de origem (input).
     * @param target Ponteiro para o sistema de destino (output).
     */
    Logistic(string name, System *source, System *target);

    /**
     * @brief Destrutor virtual.
     */
    virtual ~Logistic();

    /**
     * @brief Construtor de cópia.
     *
     * @param copy Fluxo logístico que será copiado.
     */
    Logistic(const Logistic &copy);

    /**
     * @brief Operador de atribuição.
     * @param copy Fluxo logístico que será atribuído.
     * @return RReferência para o próprio objeto.
     */
    Logistic &operator=(const Logistic &copy);

    /**
     * @brief Calcula a taxa de variação usando a equação logística.
     * @return O resultado do cálculo da taxa (double).
     *
     * Baseia-se no valor atual do sistema alvo e em uma constante limitante.
     */
    virtual double equation();
};

#endif // Logistic_HPP