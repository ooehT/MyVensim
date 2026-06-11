#include "unit_System.hpp"
#include "unit_Flow.hpp"
#include "unit_Model.hpp"
#include "unit_Exponential.hpp"
#include "unit_Logistic.hpp"

#include <iostream>

int main()
{
    

    run_unit_test_System();
    run_unit_test_Flow();
    run_unit_test_Model();
    run_unit_test_Exponential();
    run_unit_test_Logistic();

    

    return 0;
}