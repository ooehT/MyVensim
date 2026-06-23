#ifndef COMPLEXFLOW_HPP
#define COMPLEXFLOW_HPP

#include "../../src/FlowImpl.hpp"

/**
 * @brief Fluxo complexo utilizado nos testes funcionais.
 *
 * Transfere 1% do valor atual do sistema de origem a cada iteração.
 */
class ComplexFlow : public FlowImpl {
public:

    /**
     * @brief Construtor padrão.
     */
    ComplexFlow();

    /**
     * @brief Construtor parametrizado.
     *
     * @param name Nome do fluxo.
     * @param source Sistema de origem.
     * @param target Sistema de destino.
     */
    ComplexFlow(std::string name,
                System* source,
                System* target);

    /**
     * @brief Construtor de cópia.
     */
    ComplexFlow(const ComplexFlow& flow);

    /**
     * @brief Operador de atribuição.
     */
    ComplexFlow& operator=(const ComplexFlow& flow);

    /**
     * @brief Destrutor.
     */
    virtual ~ComplexFlow();

    /**
     * @brief Calcula o valor transferido.
     *
     * @return 1% do valor do sistema de origem.
     */
    double equation() override;
};

#endif