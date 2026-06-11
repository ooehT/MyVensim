#include "unit_Flow.hpp"

#include <cassert>

#include "../../src/Exponential.hpp"
#include "../../src/SystemImpl.hpp"

void unit_Flow_constructor()
{
    System* s1 = new SystemImpl("s1",100);
    System* s2 = new SystemImpl("s2",0);

    Exponential f("f",s1,s2);

    assert(f.getName() == "f");
    assert(f.getSource() == s1);
    assert(f.getTarget() == s2);
}

void unit_Flow_getName()
{
    Exponential f;
    f.setName("fluxo");

    assert(f.getName() == "fluxo");
}

void unit_Flow_setName()
{
    Exponential f;

    f.setName("novo");

    assert(f.getName() == "novo");
}

void unit_Flow_getSource()
{
    System* s = new SystemImpl("s",10);

    Exponential f;
    f.setSource(s);

    assert(f.getSource() == s);
}

void unit_Flow_setSource()
{
    System* s = new SystemImpl("s",10);

    Exponential f;
    f.setSource(s);

    assert(f.getSource() == s);
}

void unit_Flow_getTarget()
{
    System* s = new SystemImpl("s",10);

    Exponential f;
    f.setTarget(s);

    assert(f.getTarget() == s);
}

void unit_Flow_setTarget()
{
    System* s = new SystemImpl("s",10);

    Exponential f;
    f.setTarget(s);

    assert(f.getTarget() == s);
}

void unit_Flow_removeSource()
{
    System* s = new SystemImpl("s",10);

    Exponential f;
    f.setSource(s);

    f.removeSource();

    assert(f.getSource() == nullptr);
}

void unit_Flow_removeTarget()
{
    System* s = new SystemImpl("s",10);

    Exponential f;
    f.setTarget(s);

    f.removeTarget();

    assert(f.getTarget() == nullptr);
}

void run_unit_test_Flow()
{
    unit_Flow_constructor();
    unit_Flow_getName();
    unit_Flow_setName();
    unit_Flow_getSource();
    unit_Flow_setSource();
    unit_Flow_getTarget();
    unit_Flow_setTarget();
    unit_Flow_removeSource();
    unit_Flow_removeTarget();
}