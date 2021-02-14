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
    virtual void dispensen(){};
};

class SoldOutState : public State{
public:
    GumballMachine* machine;
    SoldOutState(GumballMachine * gumballMachine){
        machine = gumballMachine;
    };
    void insertQuater(){
        std::cout << "Sry, gumballs have been sold out" << std::endl;
    };
    void ejectQuater(){
        std::cout << "you havn't inserted a quater" << std::endl;
    };
    void turnCrank(){
        std::cout << "you havn't inserted a quater'" << std::endl;
    };
    void dispensen(){
        std::cout << "you havn't inserted a quater" << std::endl;
    };
};
class NoQuaterState : public State{
public:
    GumballMachine* machine;
    NoQuaterState(GumballMachine * gumballMachine){
        machine = gumballMachine;
    };
    void insertQuater(){
        std::cout << "You have inserted a Quater" << std::endl;
        machine->setState(machine->getHasQuaterState());
    };
    void ejectQuater(){
        std::cout << "Please insert a quater" << std::endl;
    };
    void turnCrank(){
        std::cout << "You turned, but there's no quater" << std::endl;
    };
    void dispensen(){
        std::cout << "Please insert a quater" << std::endl;
    };
};
class HasQuaterState : public State{
public:
    GumballMachine* machine;
    HasQuaterState(GumballMachine * gumballMachine){
        machine = gumballMachine;
    };
    void insertQuater(){
        std::cout << "You can't insert another Quater" << std::endl;
    };
    void ejectQuater(){
        std::cout << "Quater returned!" << std::endl;
        machine->setState(machine->getNoquaterState());
    };
    void turnCrank(){
        std::cout << "Turn ..." << std::endl;
        machine->setState(machine->getSoldState());
    };
    void dispensen(){
        std::cout << "You should turnDrank First!" << std::endl;
    };
};
class SoldState : public State{
public:
    GumballMachine* machine;
    SoldState(GumballMachine *gumballMachine){
        machine = gumballMachine;
    };
    void insertQuater(){
        std::cout << "Please hold, we will give you a gumball" << std::endl;
    };
    void ejectQuater(){
        std::cout << "Sry, you have turned the crank" << std::endl;
    };
    void turnCrank(){
        std::cout << "Wait, you will get a gumball" << std::endl;
    };
    void dispense(){
        machine->releaseBall();
        if(machine->getCount() > 0)
            machine->setState(machine->getNoquaterState());
        else
            machine->setState(machine->getSoldState());
    };
};
class WinnerState : public State{
public:
    GumballMachine* machine;
    std::mt19937 rng;
    std::uniform_int_distribution<uint32_t> uint_dist10((0,10)); // range [0,10]
    WinnerState(GumballMachine *gumballMachine){
        machine = gumballMachine;
    }
    void insertQuater(){
        std::cout << " you have already inserted a quater" << std::endl;
    };
    void ejectQuater(){
        std::cout << "Sry, you have turned the crank" << std::endl;
    };
    void turnCrank(){
        std::cout << "You have turned crank, please wait" << std::endl;
    };
    void dispensen(){
        uint32_t randomnumber;
        rng.seed(100);
        std::uniform_int_distribution<uint32_t> uint_dist10(0,10); // range [0,10]
        randomnumber = uint_dist10(rng);
        if(randomnumber >= 9){
            machine->releaseBall();
            machine->releaseBall();
        }
        else{
            machine->releaseBall();
        }
    };
};
#endif