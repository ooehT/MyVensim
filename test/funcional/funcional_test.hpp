/**
 * @file funcional_test.hpp
 * @brief Arquivo contendo as assinaturas dos testes funcionais da simulação.
 */

#ifndef FUNCIONAL_TEST_HPP
#define FUNCIONAL_TEST_HPP

<<<<<<< HEAD:test/funcional_test.hpp
<<<<<<< HEAD
#include "model.hpp"
#include "System.hpp"
#include "exponential.hpp"
#include "logistic.hpp" 
=======
#include "../src/model.hpp"
#include "../src/System.hpp"
#include "../src/exponential.hpp"
#include "../src/logistic.hpp" 
>>>>>>> 790b4b62ccd1d7b2f7c9d98a163a6e1cdd990d10
=======
#include "../../src/ModelImpl.hpp"
#include "../../src/SystemImpl.hpp"
#include "Exponential.hpp"
#include "Logistic.hpp"
>>>>>>> dc02b4f64e7811a1372d94719e5761d5de1464ea:test/funcional/funcional_test.hpp

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