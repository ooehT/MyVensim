#include "unit_Flow.hpp"

#include <cassert>

#include "../../src/FlowImpl.hpp"
#include "../../src/SystemImpl.hpp"

class FlowTest : public FlowImpl
{
public:
    FlowTest() : FlowImpl() {}

    FlowTest(std::string name, System* source, System* target)
        : FlowImpl(name, source, target) {}

    FlowTest(const FlowTest& other)
        : FlowImpl(other) {}

    double equation() override
    {
        return 0.0;
    }
};
void unit_Flow_constructor()
{
    System* s1 = new SystemImpl("s1", 100);
    System* s2 = new SystemImpl("s2", 0);

    FlowTest f("f", s1, s2);

    assert(f.getName() == "f");
    assert(f.getSource() == s1);
    assert(f.getTarget() == s2);

    delete s1;
    delete s2;
}
void unit_Flow_getName()
{
    FlowTest f;

    f.setName("fluxo");

    assert(f.getName() == "fluxo");
}
void unit_Flow_setName()
{
    FlowTest f;

    f.setName("novo");

    assert(f.getName() == "novo");
}
void unit_Flow_getSource()
{
    System* s = new SystemImpl("s",10);

    FlowTest f;
    f.setSource(s);

    assert(f.getSource() == s);

    delete s;
}
void unit_Flow_setSource()
{
    System* s = new SystemImpl("s",10);

    FlowTest f;
    f.setSource(s);

    assert(f.getSource() == s);

    delete s;
}
void unit_Flow_getTarget()
{
    System* s = new SystemImpl("s",10);

    FlowTest f;
    f.setTarget(s);

    assert(f.getTarget() == s);

    delete s;
}
void unit_Flow_setTarget()
{
    System* s = new SystemImpl("s",10);

    FlowTest f;
    f.setTarget(s);

    assert(f.getTarget() == s);

    delete s;
}
void unit_Flow_removeSource()
{
    System* s = new SystemImpl("s",10);

    FlowTest f;
    f.setSource(s);

    f.removeSource();

    assert(f.getSource() == nullptr);

    delete s;
}
void unit_Flow_removeTarget()
{
    System* s = new SystemImpl("s",10);

    FlowTest f;
    f.setTarget(s);

    f.removeTarget();

    assert(f.getTarget() == nullptr);

    delete s;
}
void unit_Flow_copyConstructor()
{
    System* s1 = new SystemImpl("s1",100);
    System* s2 = new SystemImpl("s2",0);

    FlowTest f1("fluxo", s1, s2);

    FlowTest f2(f1);

    assert(f2.getName() == "fluxo");
    assert(f2.getSource() == s1);
    assert(f2.getTarget() == s2);

    delete s1;
    delete s2;
}
void unit_Flow_assignmentOperator()
{
    System* s1 = new SystemImpl("s1",100);
    System* s2 = new SystemImpl("s2",0);

    FlowTest f1("fluxo", s1, s2);
    FlowTest f2;

    f2 = f1;

    assert(f2.getName() == "fluxo");
    assert(f2.getSource() == s1);
    assert(f2.getTarget() == s2);

    delete s1;
    delete s2;
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
    unit_Flow_copyConstructor();
    unit_Flow_assignmentOperator();
}