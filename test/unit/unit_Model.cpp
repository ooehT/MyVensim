#include "unit_Model.hpp"

#include "../../src/ModelImpl.hpp"
#include "../../src/SystemImpl.hpp"
#include "../../src/FlowImpl.hpp"

#include <cassert>
#include <cmath>

class FlowTestM : public FlowImpl
{
public:
    FlowTestM()
        : FlowImpl() {}

    FlowTestM(std::string name,
             System *source,
             System *target)
        : FlowImpl(name, source, target) {}

    double equation() override
    {
        return getSource()->getValue() * 0.1;
    }
};
/// @brief Verifica se o construtor padrão inicializa o modelo vazio.
bool Unit_Model::unit_Model_defaultConstructor()
{

    ModelImpl model;

    assert(model.name == "");
    assert(model.systems.empty());
    assert(model.flows.empty());

    return true;
}

bool Unit_Model::unit_Model_constructor()
{

    ModelImpl model;

    assert(model.name == "");
    assert(model.systems.empty());
    assert(model.flows.empty());

    return true;
}

bool Unit_Model::unit_Model_copyConstructor()
{

    SystemImpl s1("s1", 100);
    SystemImpl s2("s2", 50);

    FlowTestM f("f", &s1, &s2);

    ModelImpl origin;

    origin.name = "Original";

    origin.systems.push_back(&s1);
    origin.systems.push_back(&s2);

    origin.flows.push_back(&f);

    ModelImpl copy(origin);

    assert(copy.name == origin.name);
    assert(copy.systems == origin.systems);
    assert(copy.flows == origin.flows);

    return true;
}
bool Unit_Model::unit_Model_getName()
{
    ModelImpl model;

    model.setName("ModeloTeste");

    assert(model.getName() == "ModeloTeste");

    return true;
}
bool Unit_Model::unit_Model_setName()
{
    ModelImpl model;

    model.setName("NovoNome");

    assert(model.getName() == "NovoNome");

    return true;
}
bool Unit_Model::unit_Model_assignmentOperator()
{

    SystemImpl s1("s1", 100);
    SystemImpl s2("s2", 50);

    FlowTestM f("f", &s1, &s2);

    ModelImpl origin;

    origin.name = "Original";

    origin.systems.push_back(&s1);
    origin.systems.push_back(&s2);

    origin.flows.push_back(&f);

    ModelImpl assigned;

    assigned = origin;

    assert(assigned.name == origin.name);
    assert(assigned.systems == origin.systems);
    assert(assigned.flows == origin.flows);

    return true;
}
bool Unit_Model::unit_Model_addSystem()
{

    SystemImpl s("s", 100);

    ModelImpl model;

    model.add(&s);

    assert(model.systems.size() == 1);
    assert(model.systems[0] == &s);

    return true;
}
bool Unit_Model::unit_Model_addFlow()
{

    SystemImpl s1("s1", 100);
    SystemImpl s2("s2", 0);

    FlowTestM f("f", &s1, &s2);

    ModelImpl model;

    model.add(&f);

    assert(model.flows.size() == 1);
    assert(model.flows[0] == &f);

    return true;
}

bool Unit_Model::unit_Model_removeSystem()
{

    SystemImpl s("s", 100);

    ModelImpl model;

    model.add(&s);

    assert(model.remove(&s));

    assert(model.systems.empty());

    return true;
}
bool Unit_Model::unit_Model_removeFlow()
{

    SystemImpl s1("s1", 100);
    SystemImpl s2("s2", 0);

    FlowTestM f("f", &s1, &s2);

    ModelImpl model;

    model.add(&f);

    assert(model.remove(&f));

    assert(model.flows.empty());

    return true;
}
bool Unit_Model::unit_Model_beginSystems()
{

    SystemImpl s("s", 100);

    ModelImpl model;

    model.systems.push_back(&s);

    assert(*model.beginSystems() == &s);

    return true;
}
bool Unit_Model::unit_Model_endSystems()
{

    SystemImpl s("s", 100);

    ModelImpl model;

    model.systems.push_back(&s);

    assert(model.endSystems() == model.systems.end());

    return true;
}
bool Unit_Model::unit_Model_beginFlows()
{

    SystemImpl s1("s1", 100);
    SystemImpl s2("s2", 0);

    FlowTestM f("f", &s1, &s2);

    ModelImpl model;

    model.flows.push_back(&f);

    assert(*model.beginFlows() == &f);

    return true;
}
bool Unit_Model::unit_Model_endFlows()
{

    SystemImpl s1("s1", 100);
    SystemImpl s2("s2", 0);

    FlowTestM f("f", &s1, &s2);

    ModelImpl model;

    model.flows.push_back(&f);

    assert(model.endFlows() == model.flows.end());

    return true;
}
bool Unit_Model::unit_Model_execute()
{

    SystemImpl source("source", 100.0);
    SystemImpl target("target", 0.0);

    FlowTestM flow("flow", &source, &target);

    ModelImpl model;

    model.add(&source);
    model.add(&target);
    model.add(&flow);

    model.execute(0, 1, 1);

    assert(std::round(source.getValue() * 10000) == std::round(90.0 * 10000));

    assert(std::round(target.getValue() * 10000) == std::round(10.0 * 10000));

    return true;
}
bool Unit_Model::run_unit_tests_Model()
{

    assert(unit_Model_defaultConstructor());

    assert(unit_Model_constructor());

    assert(unit_Model_getName());

    assert(unit_Model_setName());

    assert(unit_Model_copyConstructor());

    assert(unit_Model_assignmentOperator());

    assert(unit_Model_addSystem());

    assert(unit_Model_addFlow());

    assert(unit_Model_removeSystem());

    assert(unit_Model_removeFlow());

    assert(unit_Model_beginSystems());

    assert(unit_Model_endSystems());

    assert(unit_Model_beginFlows());

    assert(unit_Model_endFlows());

    assert(unit_Model_execute());

    return true;
}