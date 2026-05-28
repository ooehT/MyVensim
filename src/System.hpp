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
class System {
    protected:
        double value; /**< Valor armazenado pelo sistema. */
        string name;  /**< Nome identificador do sistema. */

    public:

        /** @brief Operador de atribuição. */
        System &operator=(const System&);

        /** @brief Construtor de cópia. */
        System(const System& sys);

        /** @brief Construtor padrão. */
        System();

        /**
         * @brief Construtor parametrizado.
         * 
         * @param name Nome do sistema.
         * @param value Valor inicial do sistema.
         */
        System(string name, double value);

        /** @brief Destrutor virtual da classe. */
        virtual ~System();

        /**
         * @brief Retorna o nome do sistema.
         * 
         * @return Nome do sistema.
         */
        string getName() const;

        /**
         * @brief Define o nome do sistema.
         * 
         * @param value Novo nome do sistema.
         */
        void setName(const string &value);

        /**
         * @brief Retorna o valor armazenado no sistema.
         * 
         * @return Valor atual do sistema.
         */
        double getValue() const;

        /**
         * @brief Define um novo valor para o sistema.
         * 
         * @param value Novo valor do sistema.
         */
        void setValue(double value);

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