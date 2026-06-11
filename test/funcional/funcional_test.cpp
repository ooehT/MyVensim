#include "funcional_test.hpp"
#include <cmath>
#include <cassert>

void exponentialFuncionalTest()
{
    Model *model = new ModelImpl();
    System *s1 = new SystemImpl("s1", 100);
    System *s2 = new SystemImpl("s2", 0);
    Flow *exponencial = new Exponential("fluxo exponencial", s1, s2);

    model->add(s1);
    model->add(s2);
    model->add(exponencial);

    model->execute(0, 100, 1);

    assert(round(s1->getValue() * 10000) / 10000 == 36.6032);
    assert(round(s2->getValue() * 10000) / 10000 == 63.3968);
    assert(fabs(exponencial->equation() - 0.366032) < 0.0001);
}

void logisticalFuncionalTest()
{
    Model *model = new ModelImpl();
    System *s1 = new SystemImpl("p1", 100);
    System *s2 = new SystemImpl("p2", 10);
    Flow *logistico = new Logistic("fluxo logistico", s1, s2);

    model->add(s1);
    model->add(s2);
    model->add(logistico);

    model->execute(0, 100, 1);

    assert(round(s1->getValue() * 10000) / 10000 == 88.2167);
    assert(round(s2->getValue() * 10000) / 10000 == 21.7833);
    assert(fabs(logistico->equation() - 0.150046) <= 0.0001);
}

void complexFuncionalTest()
{
    Model *ComplexModel = new ModelImpl();
    System *s1 = new SystemImpl("s1", 100);
    System *s2 = new SystemImpl("s2", 0);
    System *s3 = new SystemImpl("s3", 100);
    System *s4 = new SystemImpl("s4", 0);
    System *s5 = new SystemImpl("s5", 0);
    Flow *a = new Exponential("a", s1, s2);
    Flow *b = new Exponential("b", s1, s3);
    Flow *c = new Exponential("c", s2, s5);
    Flow *d = new Exponential("d", s2, s3);
    Flow *e = new Exponential("e", s3, s4);
    Flow *f = new Exponential("f", s4, s1);

    ComplexModel->add(s1);
    ComplexModel->add(s2);
    ComplexModel->add(s3);
    ComplexModel->add(s4);
    ComplexModel->add(s5);
    ComplexModel->add(a);
    ComplexModel->add(b);
    ComplexModel->add(c);
    ComplexModel->add(d);
    ComplexModel->add(e);
    ComplexModel->add(f);
    // m = ComplexModel;
    ComplexModel->execute(0, 100, 1);

    assert(round(s1->getValue() * 10000) / 10000 == 31.8513);
    assert(round(s2->getValue() * 10000) / 10000 == 18.4003);
    assert(round(s3->getValue() * 10000) / 10000 == 77.1143);
    assert(round(s4->getValue() * 10000) / 10000 == 56.1728);
    assert(round(s5->getValue() * 10000) / 10000 == 16.4612);
}