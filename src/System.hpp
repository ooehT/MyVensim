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
     * @brief Retorna o nome do sistema.
     *
     * @return Nome do sistema.
     */
    virtual string getName() const = 0;
    /**
     * @brief Define o nome do sistema.
     *
     * @param value Novo nome do sistema.
     */
    virtual void setName(const string &) = 0;

    /**
     * @brief Retorna o valor armazenado no sistema.
     *
     * @return Valor atual do sistema.
     */
    virtual double getValue() const = 0;

    /**
     * @brief Define um novo valor para o sistema.
     *
     * @param value Novo valor do sistema.
     */
    virtual void setValue(double) = 0;

    /**
     * @brief Sobrecarga do operador de saída.
     *
     * @param out Fluxo de saída.
     * @param s Sistema a ser exibido.
     * @return Referência para o fluxo de saída.
     */
    friend ostream &operator<<(ostream &out, const System &s);
};

#endif