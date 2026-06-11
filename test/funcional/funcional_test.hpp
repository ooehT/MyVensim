/**
 * @file funcional_test.hpp
 * @brief Arquivo contendo as assinaturas dos testes funcionais da simulação.
 */

#ifndef FUNCIONAL_TEST_HPP
#define FUNCIONAL_TEST_HPP

#include "../../src/ModelImpl.hpp"
#include "../../src/SystemImpl.hpp"
#include "../../src/Exponential.hpp"
#include "../../src/Logistic.hpp"

/**
 * @brief Executa o teste funcional para fluxos exponenciais simples.
 * 
 * Cria um modelo contendo dois sistemas (s1 com 100, s2 com 0) ligados por um fluxo 
 * exponencial e valida se as equações de decaimento condizem com as asserções matemáticas.
 */
void exponentialFuncionalTest();

/**
 * @brief Executa o teste funcional para dinâmica de fluxos logísticos.
 * 
 * Configura um ambiente de teste simulando restrição de crescimento logístico.
 */
void logisticalFuncionalTest();

/**
 * @brief Executa um teste funcional complexo unindo múltiplos sistemas interconectados.
 * 
 * Cria uma malha de 5 sistemas e 6 fluxos exponenciais simultâneos para validar o 
 * comportamento concorrente das equações do modelo.
 */
void complexFuncionalTest();

#endif