/**
 * @file unit_Flow.hpp
 * @brief Declaração dos testes unitários da classe FlowImpl.
 */

#ifndef UNIT_FLOW_HPP
#define UNIT_FLOW_HPP

/**
 * @brief Testa o construtor da classe FlowImpl.
 *
 * Verifica se os atributos do fluxo são inicializados
 * corretamente após sua criação.
 */
void unit_Flow_constructor();

/**
 * @brief Testa o método getName().
 *
 * Verifica se o nome do fluxo é retornado
 * corretamente.
 */
void unit_Flow_getName();

/**
 * @brief Testa o método setName().
 *
 * Verifica se o nome do fluxo é alterado e
 * armazenado corretamente.
 */
void unit_Flow_setName();

/**
 * @brief Testa o método getSource().
 *
 * Verifica se o sistema de origem do fluxo
 * é retornado corretamente.
 */
void unit_Flow_getSource();

/**
 * @brief Testa o método setSource().
 *
 * Verifica se o sistema de origem do fluxo
 * é definido corretamente.
 */
void unit_Flow_setSource();

/**
 * @brief Testa o método getTarget().
 *
 * Verifica se o sistema de destino do fluxo
 * é retornado corretamente.
 */
void unit_Flow_getTarget();

/**
 * @brief Testa o método setTarget().
 *
 * Verifica se o sistema de destino do fluxo
 * é definido corretamente.
 */
void unit_Flow_setTarget();

/**
 * @brief Testa o método removeSource().
 *
 * Verifica se a referência ao sistema de origem
 * é removida corretamente.
 */
void unit_Flow_removeSource();

/**
 * @brief Testa o método removeTarget().
 *
 * Verifica se a referência ao sistema de destino
 * é removida corretamente.
 */
void unit_Flow_removeTarget();

/**
 * @brief Executa todos os testes unitários da classe FlowImpl.
 *
 * Chama sequencialmente todos os testes definidos
 * para validar o comportamento da classe.
 */
void run_unit_test_Flow();

#endif