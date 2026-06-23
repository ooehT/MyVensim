#ifndef EXPONENTIAL_HPP
#define EXPONENTIAL_HPP

#include "flow.hpp"
#include <string>

using namespace std;

/**
 * @class Exponential
 * @brief Implementa um fluxo exponencial.
 *
 * A classe Exponential define um fluxo cuja equação
 * é baseada em crescimento ou decaimento exponencial.
 */
class Exponential : public Flow
{
public:
    /** @brief Construtor padrão. */
    Exponential();

    /**
     * @brief Construtor parametrizado.
     *
     * @param name Nome do fluxo.
     * @param source Sistema de origem.
     * @param target Sistema de destino.
     */
    Exponential(string name, System *source, System *target);

    /** @brief Destrutor virtual da classe. */
    virtual ~Exponential();

    /** @brief Construtor de cópia. */
    Exponential(const Exponential &copy);

    /** @brief Operador de atribuição. */
    Exponential &operator=(const Exponential &copy);

    /**
     * @brief Executa a equação exponencial do fluxo.
     *
     * @return Valor calculado pela equação.
     */
    virtual double equation();
};

#endif // EXPONENTIAL_HPP