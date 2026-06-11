/**
 * @file unit_System.hpp
 * @brief Declaração dos testes unitários da classe SystemImpl.
 */

#ifndef UNIT_SYSTEM_HPP
#define UNIT_SYSTEM_HPP

/**
 * @brief Testa o construtor da classe SystemImpl.
 *
 * Verifica se os atributos são inicializados corretamente
 * após a criação de um objeto.
 */
void unit_System_constructor();

/**
 * @brief Testa o método getName().
 *
 * Verifica se o nome armazenado no sistema é retornado
 * corretamente.
 */
void unit_System_getName();

/**
 * @brief Testa o método setName().
 *
 * Verifica se o nome do sistema é alterado e armazenado
 * corretamente.
 */
void unit_System_setName();

/**
 * @brief Testa o método getValue().
 *
 * Verifica se o valor armazenado no sistema é retornado
 * corretamente.
 */
void unit_System_getValue();

/**
 * @brief Testa o método setValue().
 *
 * Verifica se o valor do sistema é alterado e armazenado
 * corretamente.
 */
void unit_System_setValue();

/**
 * @brief Executa todos os testes unitários da classe SystemImpl.
 *
 * Chama sequencialmente todos os testes definidos para
 * validar o comportamento da classe.
 */
void run_unit_test_System();

#endif