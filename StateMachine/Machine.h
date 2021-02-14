#ifndef MACHINE_H
#define MACHINE_H
#include "State.h"
class State;
class GumballMachine{
public:
    State *soldOutState;
    State *noQuaterState;
    State *hasQuaterState;
    State *soldState;

    State *state;
    int count;
    GumballMachine(int numberGumballs){
        count = numberGumballs;
        soldOutState = new SoldOutState(this);
        noQuaterState = new NoQuaterState(this);
        hasQuaterState = new HasQuaterState(this);
        soldState = new SoldState(this);
        if(count > 0)
            state = noQuaterState;
        else
            state = soldOutState;
        
    };
    void insertQuater(){
        state->insertQuater();
    };
    void ejectQuater(){
        state->ejectQuater();
    };
    void turnCrank(){
        state->turnCrank();
        state->dispensen();
    };
    void setState(State *newstate){
        state = newstate;
    };
    void releaseBall(){
        if(count > 0){
            count--;
            std::cout << "A gumball comes rolling out the slot..." << std::endl;
        }else{
            std::cout << "No enough gumball" << std::endl;
        }
    };
    int getCount(){
        return count;
    };
    State* getNoquaterState(){
        return noQuaterState;
    };
    State* getSoldOutState(){
        return soldOutState;
    };
    State* getHasQuaterState(){
        return hasQuaterState;
    };
    State* getSoldState(){
        return soldState;
    };
};
#endif
