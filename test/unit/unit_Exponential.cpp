#include "unit_Exponential.hpp"

#include <cassert>

#include "../../src/Exponential.hpp"
#include "../../src/SystemImpl.hpp"

void unit_Exponential_equation()
{
    System* s1 = new SystemImpl("s1", 100);
    System* s2 = new SystemImpl("s2", 0);

    Exponential e("e", s1, s2);

    assert(e.equation() == 1.0);

    delete s1;
    delete s2;
}

void run_unit_test_Exponential()
{
    unit_Exponential_equation();
}