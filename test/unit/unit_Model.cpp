#include "unit_Model.hpp"

#include <cassert>

#include "../../src/ModelImpl.hpp"
#include "../../src/SystemImpl.hpp"
#include "../funcional/Exponential.hpp"

void unit_Model_constructor()
{
    ModelImpl m;

    assert(m.name == "");
    assert(m.systems.empty());
    assert(m.flows.empty());
}