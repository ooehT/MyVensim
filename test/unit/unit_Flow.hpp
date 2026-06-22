/**
 * @file unit_Flow.hpp
 * @brief Testes unitários da classe Flow.
 */

#ifndef UNIT_FLOW_HPP
#define UNIT_FLOW_HPP

/**
 * @brief Testa o construtor.
 */
void unit_Flow_constructor();

/**
 * @brief Testa getName().
 */
void unit_Flow_getName();

/**
 * @brief Testa setName().
 */
void unit_Flow_setName();

/**
 * @brief Testa getSource().
 */
void unit_Flow_getSource();

/**
 * @brief Testa setSource().
 */
void unit_Flow_setSource();

/**
 * @brief Testa getTarget().
 */
void unit_Flow_getTarget();

/**
 * @brief Testa setTarget().
 */
void unit_Flow_setTarget();

/**
 * @brief Testa removeSource().
 */
void unit_Flow_removeSource();

/**
 * @brief Testa removeTarget().
 */
void unit_Flow_removeTarget();

/**
 * @brief Testa o construtor de cópia.
 */
void unit_Flow_copyConstructor();

/**
 * @brief Testa o operador de atribuição.
 */
void unit_Flow_assignmentOperator();

/**
 * @brief Executa todos os testes unitários de Flow.
 */
void run_unit_test_Flow();

#endif