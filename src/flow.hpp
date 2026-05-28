#ifndef FLOW_HPP
#define FLOW_HPP

#include <string>
#include "System.hpp"

/**
 * @class Flow
 * @brief Classe abstrata que representa um fluxo entre sistemas.
 * 
 * A classe Flow define a estrutura básica para fluxos
 * responsáveis por transferir valores entre sistemas
 * durante a simulação.
 */
class Flow {
    protected:
        string name;     /**< Nome identificador do fluxo. */
        System* source;  /**< Sistema de origem do fluxo. */
        System* target;  /**< Sistema de destino do fluxo. */

    public:

        /** @brief Construtor padrão. */
        Flow();

        /**
         * @brief Construtor parametrizado.
         * 
         * @param name Nome do fluxo.
         * @param source Sistema de origem.
         * @param target Sistema de destino.
         */
        Flow(string name, System* source, System* target);

        /** @brief Construtor de cópia. */
        Flow(const Flow &f);

        /** @brief Operador de atribuição. */
        Flow &operator=(const Flow &f);

        /** @brief Destrutor virtual da classe. */
        virtual ~Flow();

        /**
         * @brief Executa a equação do fluxo.
         * 
         * Método abstrato responsável pelo cálculo
         * da taxa de transferência do fluxo.
         * 
         * @return Valor calculado do fluxo.
         */
        virtual double equation() = 0;

        /**
         * @brief Define o sistema de origem.
         * 
         * @param source Ponteiro para o sistema de origem.
         */
        void setSource(System* source);

        /**
         * @brief Retorna o sistema de origem.
         * 
         * @return Ponteiro para o sistema de origem.
         */
        System* getSource() const;

        /**
         * @brief Define o sistema de destino.
         * 
         * @param target Ponteiro para o sistema de destino.
         */
        void setTarget(System* target);

        /**
         * @brief Retorna o sistema de destino.
         * 
         * @return Ponteiro para o sistema de destino.
         */
        System* getTarget() const;

        /**
         * @brief Retorna o nome do fluxo.
         * 
         * @return Nome do fluxo.
         */
        string getName() const;

        /**
         * @brief Define o nome do fluxo.
         * 
         * @param value Novo nome do fluxo.
         */
        void setName(const string &value);

        /** @brief Remove o sistema de origem do fluxo. */
        void removeSource();

        /** @brief Remove o sistema de destino do fluxo. */
        void removeTarget();
};

#endif