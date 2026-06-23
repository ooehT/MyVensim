/**
 * @file System.hpp
 * @brief Interface abstrata que representa um sistema do simulador.
 */
#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <string>

using namespace std;

/**
 * @class System
 * @brief Representa um sistema contendo um valor associado.
 *
 * A classe System armazena um nome identificador e um valor
 * numérico utilizado durante a simulação.
 */
class System
{
public:
    /** @brief Destrutor virtual da classe. */
    virtual ~System() {}

    /**
     * @brief Obtém o nome do sistema.
     *
     * @return Nome identificador do sistema.
     */

    virtual string getName() const = 0;
    /**
     * @brief Altera o nome do sistema.
     *
     * @param name Novo nome do sistema.
     */
    virtual void setName(const string &) = 0;

    /**
     * @brief Obtém o valor armazenado no sistema.
     *
     * @return Valor atual do sistema.
     */
    virtual double getValue() const = 0;

    /**
     * @brief Modifica o valor armazenado.
     *
     * @param value Novo valor do sistema.
     */
    virtual void setValue(double) = 0;
};

#endif