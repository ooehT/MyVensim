#include "Exponential.hpp"

// Construtor Padrão
Exponential::Exponential() : FlowImpl() {}

// Construtor Parametrizado
Exponential::Exponential(const std::string &name, System *input, System *output) 
    : FlowImpl(name, input, output) {}

// Destrutor
Exponential::~Exponential() {}

// Construtor de Cópia (Chama o construtor de cópia do pai)
Exponential::Exponential(const Exponential& copy) : FlowImpl(copy) {}

// Operador de Atribuição (Chama o operador de atribuição do pai)
Exponential& Exponential::operator=(const Exponential& copy) {
    if (this != &copy) {
        FlowImpl::operator=(copy);
    }
    return *this;
}

// Sua equação de taxa exponencial
double Exponential::equation() {
    if (getSource() != nullptr) {
        return getSource()->getValue() * 0.01;
    }
    return 0.0;
}