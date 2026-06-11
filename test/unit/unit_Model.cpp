#include "unit_Model.hpp"

#include <cassert>

#include "../../src/ModelImpl.hpp"
#include "../../src/SystemImpl.hpp"
#include "../../src/Exponential.hpp"

void unit_Model_constructor()
{
    ModelImpl model;

    assert(model.getSystems().size() == 0);
    assert(model.getFlows().size() == 0);
}

void unit_Model_addSystem()
{
    ModelImpl model;

    System* s = new SystemImpl("s",100);

    model.add(s);

    assert(model.getSystems().size() == 1);
}

void unit_Model_addFlow()
{
    ModelImpl model;

    System* s1 = new SystemImpl("s1",100);
    System* s2 = new SystemImpl("s2",0);

    Flow* f = new Exponential("f",s1,s2);

    model.add(f);

    assert(model.getFlows().size() == 1);
}

void unit_Model_removeSystem()
{
    ModelImpl model;

    System* s = new SystemImpl("s",100);

    model.add(s);
    model.remove(s);

    assert(model.getSystems().size() == 0);
}

void unit_Model_removeFlow()
{
    ModelImpl model;

    System* s1 = new SystemImpl("s1",100);
    System* s2 = new SystemImpl("s2",0);

    Flow* f = new Exponential("f",s1,s2);

    model.add(f);
    model.remove(f);

    assert(model.getFlows().size() == 0);
}

void unit_Model_getSystems()
{
    ModelImpl model;

    System* s = new SystemImpl("s",100);

    model.add(s);

    assert(model.getSystems()[0] == s);
}

void unit_Model_getFlows()
{
    ModelImpl model;

    System* s1 = new SystemImpl("s1",100);
    System* s2 = new SystemImpl("s2",0);

    Flow* f = new Exponential("f",s1,s2);

    model.add(f);

    assert(model.getFlows()[0] == f);
}

void unit_Model_getName()
{
    ModelImpl model;

    model.setName("modelo");

    assert(model.getName() == "modelo");
}

void unit_Model_setName()
{
    ModelImpl model;

    model.setName("teste");

    assert(model.getName() == "teste");
}

void run_unit_test_Model()
{
    unit_Model_constructor();
    unit_Model_addSystem();
    unit_Model_addFlow();
    unit_Model_removeSystem();
    unit_Model_removeFlow();
    unit_Model_getSystems();
    unit_Model_getFlows();
    unit_Model_getName();
    unit_Model_setName();
}