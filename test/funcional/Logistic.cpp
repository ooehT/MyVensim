#include "Logistic.hpp"

// Construtor Padrão
Logistic::Logistic() : FlowImpl() {}

// Construtor Parametrizado
Logistic::Logistic(string name, System *input, System *output)
    : FlowImpl(name, input, output) {}

// Destrutor
Logistic::~Logistic() {}

// Construtor de Cópia (Chama o construtor de cópia do pai)
Logistic::Logistic(const Logistic &copy) : FlowImpl(copy) {}

// Operador de Atribuição (Chama o operador de atribuição do pai)
Logistic &Logistic::operator=(const Logistic &copy)
{
    if (this != &copy)
    {
        FlowImpl::operator=(copy);
    }
    return *this;
}

// Sua equação de taxa exponencial
double Logistic::equation()
{
    if (getSource() != nullptr)
    {
        double p = getTarget()->getValue();
        return 0.01 * p * (1 - p / 70.0);
    }
    return 0.0;
}