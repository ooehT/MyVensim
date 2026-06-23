#ifndef UNIT_FLOW_HPP
#define UNIT_FLOW_HPP

class Unit_Flow {
public:

    static bool unit_Flow_constructor();

    static bool unit_Flow_getName();

    static bool unit_Flow_setName();

    static bool unit_Flow_getSource();

    static bool unit_Flow_setSource();

    static bool unit_Flow_getTarget();

    static bool unit_Flow_setTarget();

    static bool unit_Flow_removeSource();

    static bool unit_Flow_removeTarget();

    static bool unit_Flow_copyConstructor();

    static bool unit_Flow_assignmentOperator();

    static bool run_unit_tests_Flow();
};

#endif