/**
 * @file unit_Model.hpp
 * @brief Declaração dos testes unitários da classe ModelImpl.
 */

#ifndef UNIT_MODEL_HPP
#define UNIT_MODEL_HPP

/**
 * @brief Testa o construtor da classe ModelImpl.
 *
 * Verifica se os atributos do modelo são inicializados
 * corretamente após sua criação.
 */
void unit_Model_constructor();

/**
 * @brief Testa o método addSystem().
 *
 * Verifica se um sistema é adicionado corretamente
 * à coleção de sistemas do modelo.
 */
void unit_Model_addSystem();

/**
 * @brief Testa o método addFlow().
 *
 * Verifica se um fluxo é adicionado corretamente
 * à coleção de fluxos do modelo.
 */
void unit_Model_addFlow();

/**
 * @brief Testa o método removeSystem().
 *
 * Verifica se um sistema é removido corretamente
 * da coleção de sistemas do modelo.
 */
void unit_Model_removeSystem();

/**
 * @brief Testa o método removeFlow().
 *
 * Verifica se um fluxo é removido corretamente
 * da coleção de fluxos do modelo.
 */
void unit_Model_removeFlow();

/**
 * @brief Testa o método getSystems().
 *
 * Verifica se a coleção de sistemas é retornada
 * corretamente.
 */
void unit_Model_getSystems();

/**
 * @brief Testa o método getFlows().
 *
 * Verifica se a coleção de fluxos é retornada
 * corretamente.
 */
void unit_Model_getFlows();

/**
 * @brief Testa o método getName().
 *
 * Verifica se o nome do modelo é retornado
 * corretamente.
 */
void unit_Model_getName();

/**
 * @brief Testa o método setName().
 *
 * Verifica se o nome do modelo é alterado e
 * armazenado corretamente.
 */
void unit_Model_setName();

/**
 * @brief Executa todos os testes unitários da classe ModelImpl.
 *
 * Chama sequencialmente todos os testes definidos
 * para validar o comportamento da classe.
 */
void run_unit_test_Model();

#endif