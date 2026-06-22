/**
 * @file unit_Model.hpp
 * @brief Testes unitários da classe Model.
 */

#ifndef UNIT_MODEL_HPP
#define UNIT_MODEL_HPP

/**
 * @brief Testa o construtor padrão.
 */
void unit_Model_constructor();

/**
 * @brief Testa getName().
 */
void unit_Model_getName();

/**
 * @brief Testa setName().
 */
void unit_Model_setName();

/**
 * @brief Testa o construtor de cópia.
 */
void unit_Model_copyConstructor();

/**
 * @brief Testa o operador de atribuição.
 */
void unit_Model_assignmentOperator();

/**
 * @brief Testa add(System*).
 */
void unit_Model_addSystem();

/**
 * @brief Testa remove(System*).
 */
void unit_Model_removeSystem();

/**
 * @brief Testa add(Flow*).
 */
void unit_Model_addFlow();

/**
 * @brief Testa remove(Flow*).
 */
void unit_Model_removeFlow();

/**
 * @brief Testa execute().
 */
void unit_Model_execute();

/**
 * @brief Executa todos os testes unitários de Model.
 */
void run_unit_test_Model();

#endif