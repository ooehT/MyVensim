#ifndef Logistic_HPP
#define Logistic_HPP

#include "flow.hpp"
#include <string>

using namespace std;

class Logistic : public Flow {
    public:
        // 1. Construtor Padrão
        Logistic();

        // Construtor com parâmetros (específico da sua regra de negócio)
        Logistic(string name, System *source, System *target);

        // 2. Destrutor (virtual para garantir a correta destruição na herança)
        virtual ~Logistic();

        // 3. Construtor de Cópia
        Logistic(const Logistic& copy);

        // 4. Operador de Atribuição
        Logistic& operator=(const Logistic& copy);

        // Método que executa a equação (herdado da classe Flow)
        virtual double execute();
};

#endif // Logistic_HPP