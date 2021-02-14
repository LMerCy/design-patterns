#ifndef MACHINE_H
#define MACHINE_H
#include "State.h"
class State;
class SoldOutState;
class NoQuaterState;
class HasQuaterState;
class SoldState;
class GumballMachine{
public:
    State* soldOutState;
    State* noQuaterState;
    State* hasQuaterState;
    State* soldState;
    State* state;
    int count;
    GumballMachine(int numberGumballs);
    void insertQuater();
    void ejectQuater();
    void turnCrank();
    void setState(State *newstate);
    void releaseBall();
    int getCount();
    State* getNoquaterState();
    State* getSoldOutState();
    State* getHasQuaterState();
    State* getSoldState();
};
#endif
