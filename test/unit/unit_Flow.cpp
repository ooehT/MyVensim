#include "unit_Flow.hpp"

#include <cassert>

#include "../../src/FlowImpl.hpp"
#include "../../src/SystemImpl.hpp"

class FlowTest : public FlowImpl
{
public:
    FlowTest() : FlowImpl() {}

    FlowTest(std::string name, System *source, System *target)
        : FlowImpl(name, source, target) {}

    FlowTest(const FlowTest &other)
        : FlowImpl(other) {}
    FlowTest &operator=(const FlowTest &other)
    {
        if (this != &other)
        {
            FlowImpl::operator=(other);
        }

        return *this;
    }

    double equation() override
    {
        return 0.0;
    }
};

bool Unit_Flow::unit_Flow_constructor()
{
    System *s1 = new SystemImpl("s1", 100);
    System *s2 = new SystemImpl("s2", 0);

    FlowTest f("f", s1, s2);

    assert(f.getName() == "f");
    assert(f.getSource() == s1);
    assert(f.getTarget() == s2);

    delete s1;
    delete s2;

    return true;
}

bool Unit_Flow::unit_Flow_getName()
{
    FlowTest f;

    f.setName("fluxo");

    assert(f.getName() == "fluxo");

    return true;
}

bool Unit_Flow::unit_Flow_setName()
{
    FlowTest f;

    f.setName("novo");

    assert(f.getName() == "novo");

    return true;
}

bool Unit_Flow::unit_Flow_getSource()
{
    System *s = new SystemImpl("s", 10);

    FlowTest f;
    f.setSource(s);

    assert(f.getSource() == s);

    delete s;

    return true;
}

bool Unit_Flow::unit_Flow_setSource()
{
    System *s = new SystemImpl("s", 10);

    FlowTest f;
    f.setSource(s);

    assert(f.getSource() == s);

    delete s;

    return true;
}

bool Unit_Flow::unit_Flow_getTarget()
{
    System *s = new SystemImpl("s", 10);

    FlowTest f;
    f.setTarget(s);

    assert(f.getTarget() == s);

    delete s;

    return true;
}

bool Unit_Flow::unit_Flow_setTarget()
{
    System *s = new SystemImpl("s", 10);

    FlowTest f;
    f.setTarget(s);

    assert(f.getTarget() == s);

    delete s;

    return true;
}

bool Unit_Flow::unit_Flow_removeSource()
{
    System *s = new SystemImpl("s", 10);

    FlowTest f;
    f.setSource(s);

    f.removeSource();

    assert(f.getSource() == nullptr);

    delete s;

    return true;
}

bool Unit_Flow::unit_Flow_removeTarget()
{
    System *s = new SystemImpl("s", 10);

    FlowTest f;
    f.setTarget(s);

    f.removeTarget();

    assert(f.getTarget() == nullptr);

    delete s;

    return true;
}

bool Unit_Flow::unit_Flow_copyConstructor()
{
    System *s1 = new SystemImpl("s1", 100);
    System *s2 = new SystemImpl("s2", 0);

    FlowTest f1("fluxo", s1, s2);

    FlowTest f2(f1);

    assert(f2.getName() == "fluxo");
    assert(f2.getSource() == s1);
    assert(f2.getTarget() == s2);

    delete s1;
    delete s2;

    return true;
}

bool Unit_Flow::unit_Flow_assignmentOperator()
{
    System *s1 = new SystemImpl("s1", 100);
    System *s2 = new SystemImpl("s2", 0);

    FlowTest f1("fluxo", s1, s2);
    FlowTest f2;

    f2 = f1;

    assert(f2.getName() == "fluxo");
    assert(f2.getSource() == s1);
    assert(f2.getTarget() == s2);

    delete s1;
    delete s2;

    return true;
}

bool Unit_Flow::run_unit_tests_Flow()
{
    assert(unit_Flow_constructor());

    assert(unit_Flow_getName());

    assert(unit_Flow_setName());

    assert(unit_Flow_getSource());

    assert(unit_Flow_setSource());

    assert(unit_Flow_getTarget());

    assert(unit_Flow_setTarget());

    assert(unit_Flow_removeSource());

    assert(unit_Flow_removeTarget());

    assert(unit_Flow_copyConstructor());

    assert(unit_Flow_assignmentOperator());

    return true;
}