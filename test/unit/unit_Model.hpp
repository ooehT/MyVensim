#ifndef UNIT_MODEL_HPP
#define UNIT_MODEL_HPP

class Unit_Model {
public:
    static bool unit_Model_defaultConstructor();

    static bool unit_Model_constructor();

    static bool unit_Model_copyConstructor();

    static bool unit_Model_getName();

    static bool unit_Model_setName();

    static bool unit_Model_assignmentOperator();

    static bool unit_Model_addSystem();

    static bool unit_Model_addFlow();

    static bool unit_Model_removeSystem();

    static bool unit_Model_removeFlow();

    static bool unit_Model_beginSystems();

    static bool unit_Model_endSystems();

    static bool unit_Model_beginFlows();

    static bool unit_Model_endFlows();

    static bool unit_Model_execute();

    static bool run_unit_tests_Model();
};

#endif