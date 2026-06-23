/**
 * @file SystemImpl.hpp
 * @brief Implementação concreta da interface System.
 */
#ifndef SYSTEMIMPL_HPP
#define SYSTEMIMPL_HPP

#include "System.hpp"
/**
 * @class SystemImpl
 * @brief Implementação concreta de um sistema da simulação.
 *
 * Armazena internamente o nome e o valor do sistema.
 * Implementa todos os métodos definidos pela interface System.
 */

class SystemImpl : public System
{
private:
    /**
     * @brief Valor atual armazenado pelo sistema.
     */
    double value;
    /**
     * @brief Nome identificador do sistema.
     */
    string name;

public:
    /**
     * @brief Construtor padrão.
     * Inicializa um sistema com nome e valor padrão.
     */
    SystemImpl();
    /**
     * @brief Construtor parametrizado.
     *
     * @param name Nome do sistema.
     * @param value Valor inicial.
     */

    SystemImpl(string name, double value);

    /**
     * @brief Construtor de cópia.
     *
     * Cria um novo sistema copiando os dados
     * de outro objeto SystemImpl.
     *
     * @param copy Sistema que será copiado.
     */
    SystemImpl(const SystemImpl &);
    /**
     * @brief Operador de atribuição.
     *
     * Copia os valores de outro sistema para este objeto.
     *
     * @param copy Sistema que será atribuído.
     * @return Referência para o próprio objeto.
     */
    SystemImpl &operator=(const SystemImpl &);
    /**
     * @brief Destrutor.
     */
    virtual ~SystemImpl();

    /**
     * @brief Retorna o nome do sistema.
     */
    string getName() const;
    /**
     * @brief Define o nome do sistema.
     *
     * @param name Novo nome do sistema.
     */
    void setName(const string &);
    /**
     * @brief Retorna o valor atual do sistema.
     *
     * @return Valor armazenado.
     */
    double getValue() const;
    /**
     * @brief Define o valor do sistema.
     *
     * @param value Novo valor armazenado.
     */
    void setValue(double);
};

#endif