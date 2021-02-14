#ifndef STATE_H
#define STATE_H
#include<iostream>
#include<random>
#include "Machine.h"
class GumballMachine;
class State{
public:
    GumballMachine* machine;
    State(){};
    virtual ~State(){};
    virtual void insertQuater(){};
    virtual void ejectQuater(){};
    virtual void turnCrank(){};
    virtual void dispense(){};
};

class SoldOutState : public State{
public:
    GumballMachine* machine;
    SoldOutState(GumballMachine * gumballMachine);
    void insertQuater();
    void ejectQuater();
    void turnCrank();
    void dispense();
};
class NoQuaterState : public State{
public:
    GumballMachine* machine;
    NoQuaterState(GumballMachine * gumballMachine);
    void insertQuater();
    void ejectQuater();
    void turnCrank();
    void dispense();
};
class HasQuaterState : public State{
public:
    GumballMachine* machine;
    HasQuaterState(GumballMachine * gumballMachine);
    void insertQuater();
    void ejectQuater();
    void turnCrank();
    void dispense();
};
class SoldState : public State{
public:
    GumballMachine* machine;
    SoldState(GumballMachine *gumballMachine);
    void insertQuater();
    void ejectQuater();
    void turnCrank();
    void dispense();
};
class WinnerState : public State{
public:
    GumballMachine* machine;
    std::mt19937 rng;
    // static std::uniform_int_distribution<uint32_t> uint_dist10(0,10); // range [0,10]
    WinnerState(GumballMachine *gumballMachine);
    void insertQuater();
    void ejectQuater();
    void turnCrank();
    void dispense();
};
#endif