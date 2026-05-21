#include "functional_test.hpp"
#include <cmath>
#include <cassert>

void exponentialFuncionalTest(){
    Model* model = new Model();
    System* s1 = new System("s1", 100);
    System* s2 = new System("s2", 0);
    Flow* exponencial = new Exponential("fluxo exponencial", s1, s2);

    model->add(s1);
    model->add(s2);
    model->add(exponencial);

    model->execute(0, 100, 1);

    assert(fabs(s1->getValue() - 36.6032) < 0.0001);
    assert(fabs(s2->getValue() - 63.3968) < 0.0001);
    assert(fabs(exponencial->execute() - 0.366032) < 0.0001);
}

void logisticalFuncionalTest(){
    Model* model = new Model();
    System* s1 = new System("p1", 100);
    System* s2 = new System("p2", 10);
    Flow* logistico = new Logistic("fluxo logistico", s1, s2);

    model->add(s1);
    model->add(s2);
    model->add(logistico);

    model->execute(0, 100, 1);

    assert(fabs(s1->getValue() - 88.2167) < 0.0001);
    assert(fabs(s2->getValue() - 11.7833) < 0.0001);
    assert(fabs(logistico->execute() - 0.150046) < 0.0001);
}

void complexFuncionalTest(){
    Model* ComplexModel = new Model();
    System* s1 = new System("s1", 100);
    System* s2 = new System("s2", 0);
    System* s3 = new System("s3", 100);
    System* s4 = new System("s4", 0);
    System* s5 = new System("s5", 0);
    Flow* a = new Exponential("a", s1, s2);
    Flow* b = new Exponential("b", s1, s3);
    Flow* c = new Exponential("c", s2, s5);
    Flow* d = new Exponential("d", s2, s3);
    Flow* e = new Exponential("e", s3, s4);
    Flow* f = new Exponential("f", s4, s1);

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

    ComplexModel->execute(0, 100, 1);

    assert(fabs(s1->getValue() - 31.8513) < 0.0001);
    assert(fabs(s2->getValue() - 18.4003) < 0.0001);
    assert(fabs(s3->getValue() - 77.1143) < 0.0001);
    assert(fabs(s4->getValue() - 56.1729) < 0.0001);
    assert(fabs(s5->getValue() - 16.4612) < 0.0001);
}