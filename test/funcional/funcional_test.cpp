#include "funcional_test.hpp"
#include "../../src/Model.hpp"
#include "Exponential.hpp"
#include "Logistic.hpp"
#include "Complex.hpp"
#include <cmath>
#include <cassert>

using namespace std;

void exponentialFuncionalTest()
{
    Model *model = Model::createModel("Exponential Model");

    System *s1 = model->createSystem("s1", 100);

    System *s2 = model->createSystem("s2", 0);

    Flow *exponencial = model->createFlow<Exponential>("fluxo exponencial", s1, s2);

    model->execute(0, 100, 1);

    assert(round(s1->getValue() * 10000) / 10000 == 36.6032);
    assert(round(s2->getValue() * 10000) / 10000 == 63.3968);

    assert(fabs(exponencial->equation() - 0.366032) < 0.0001);
    assert(
    Model::deleteModel("Exponential Model")
);
    
}
void logisticalFuncionalTest()
{
    Model* model = Model::createModel("Logistic Model");
    
    System* s1 = model->createSystem("p1",100 );

    System* s2 = model->createSystem("p2",10);

    Flow* logistico = model->createFlow<Logistic>("fluxo logistico",s1,s2);

    model->execute(0,100,1);

    assert(round(s1->getValue()*10000)/10000 == 88.2167);
    assert(round(s2->getValue()*10000)/10000 == 21.7833);

    assert(fabs(logistico->equation() - 0.150046) <= 0.0001);
    assert(Model::deleteModel("Logistic Model")
);
}

void complexFuncionalTest()
{
    Model* model =Model::createModel("Complex Model");

    System* s1 = model->createSystem("q1",100);
    System* s2 = model->createSystem("q2",0);
    System* s3 = model->createSystem("q3",100);
    System* s4 = model->createSystem("q4",0);
    System* s5 = model->createSystem("q5",0);

    model->createFlow<ComplexFlow>("f",s1,s2);

    model->createFlow<ComplexFlow>("g",s1,s3);

    model->createFlow<ComplexFlow>("r",s2,s5);

    model->createFlow<ComplexFlow>("t",s2,s3);

    model->createFlow<ComplexFlow>("u",s3,s4);

    model->createFlow<ComplexFlow>("v",s4,s1);

    model->execute(0,100,1);

    assert(round(s1->getValue()*10000)/10000 == 31.8513);
    assert(round(s2->getValue()*10000)/10000 == 18.4003);
    assert(round(s3->getValue()*10000)/10000 == 77.1143);
    assert(round(s4->getValue()*10000)/10000 == 56.1728);
    assert(round(s5->getValue()*10000)/10000 == 16.4612);
    assert(
    Model::deleteModel("Complex Model")
);
}