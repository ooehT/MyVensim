#include "unit_Logistic.hpp"

#include <cassert>
#include <cmath>

#include "../../src/Logistic.hpp"
#include "../../src/SystemImpl.hpp"

void unit_Logistic_equation()
{
    System* s1 = new SystemImpl("s1", 100);
    System* s2 = new SystemImpl("s2", 10);

    Logistic l("l", s1, s2);

    assert(fabs(l.equation() - 0.0857143) < 0.000001);

    delete s1;
    delete s2;
}

void run_unit_test_Logistic()
{
    unit_Logistic_equation();
}