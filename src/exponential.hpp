#ifndef EXPONENTIAL_HPP
#define EXPONENTIAL_HPP

#include "flow.hpp"
#include <string>

using namespace std;

class Exponential : public Flow {
    public:
        // 1. Construtor Padrão
        Exponential();

        // Construtor com parâmetros (específico da sua regra de negócio)
        Exponential(string name, System *input, System *output);

        // 2. Destrutor (virtual para garantir a correta destruição na herança)
        virtual ~Exponential();

        // 3. Construtor de Cópia
        Exponential(const Exponential& copy);

        // 4. Operador de Atribuição
        Exponential& operator=(const Exponential& copy);

        // Método que executa a equação (herdado da classe Flow)
        virtual double execute();
};

#endif // EXPONENTIAL_HPP