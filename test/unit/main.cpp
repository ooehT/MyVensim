#include "unit_System.hpp"
#include "unit_Flow.hpp"
#include "unit_Model.hpp"


#include <iostream>

int main()
{
    
    printf("Iniciando testes unitários...\n\n");
    Unit_System::run_unit_tests_System();
    Unit_Flow::run_unit_tests_Flow();
    Unit_Model::run_unit_tests_Model();

    printf("\nTestes unitários concluídos.\n");

    

    return 0;
}