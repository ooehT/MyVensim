#include "unit_System.hpp"

#include "../../src/SystemImpl.hpp"

#include <cassert>
bool Unit_System::unit_System_constructor()
{
    SystemImpl s("s1", 100);

    assert(s.getName() == "s1");
    assert(s.getValue() == 100);

    return true;
}
bool Unit_System::unit_System_getName()
{
    SystemImpl s("teste", 0);

    assert(s.getName() == "teste");

    return true;
}
bool Unit_System::unit_System_setName()
{
    SystemImpl s("A", 0);

    s.setName("B");

    assert(s.getName() == "B");

    return true;
}
bool Unit_System::unit_System_getValue()
{
    SystemImpl s("A", 50);

    assert(s.getValue() == 50);

    return true;
}
bool Unit_System::unit_System_setValue()
{
    SystemImpl s("A", 0);

    s.setValue(200);

    assert(s.getValue() == 200);

    return true;
}
bool Unit_System::unit_System_copyConstructor()
{
    SystemImpl s1("s1", 100);

    SystemImpl s2(s1);

    assert(s2.getName() == "s1");
    assert(s2.getValue() == 100);

    return true;
}
bool Unit_System::unit_System_assignmentOperator()
{
    SystemImpl s1("s1", 100);
    SystemImpl s2("s2", 200);

    s2 = s1;

    assert(s2.getName() == "s1");
    assert(s2.getValue() == 100);

    return true;
}
bool Unit_System::run_unit_tests_System()
{
    assert(unit_System_constructor());

    assert(unit_System_getName());

    assert(unit_System_setName());

    assert(unit_System_getValue());

    assert(unit_System_setValue());

    assert(unit_System_copyConstructor());

    assert(unit_System_assignmentOperator());

    return true;
}