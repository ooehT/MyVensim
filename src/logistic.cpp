#include "logistic.hpp"

// Construtor Padrão
Logistic::Logistic() : Flow() {}

// Construtor Parametrizado
Logistic::Logistic(string name, System *input, System *output)
    : Flow(name, input, output) {}

// Destrutor
Logistic::~Logistic() {}

// Construtor de Cópia (Chama o construtor de cópia do pai)
Logistic::Logistic(const Logistic &copy) : Flow(copy) {}

// Operador de Atribuição (Chama o operador de atribuição do pai)
Logistic &Logistic::operator=(const Logistic &copy)
{
    if (this != &copy)
    {
        Flow::operator=(copy);
    }
    return *this;
}

// Sua equação de taxa exponencial
double Logistic::execute()
{
    if (getSource() != nullptr)
    {
        double p = target->getValue();
        return 0.01 * p * (1 - p / 70.0);
}
return 0.0;
}