#include "unit_System.hpp"

#include <cassert>

#include "../../src/SystemImpl.hpp"

void unit_System_constructor()
{
    SystemImpl s("s1", 100);

    assert(s.getName() == "s1");
    assert(s.getValue() == 100);
}

void unit_System_getName()
{
    SystemImpl s("teste", 0);

    assert(s.getName() == "teste");
}

void unit_System_setName()
{
    SystemImpl s("A", 0);

    s.setName("B");

    assert(s.getName() == "B");
}

void unit_System_getValue()
{
    SystemImpl s("A", 50);

    assert(s.getValue() == 50);
}

void unit_System_setValue()
{
    SystemImpl s("A", 0);

    s.setValue(200);

    assert(s.getValue() == 200);
}

void run_unit_test_System()
{
    unit_System_constructor();
    unit_System_getName();
    unit_System_setName();
    unit_System_getValue();
    unit_System_setValue();
}