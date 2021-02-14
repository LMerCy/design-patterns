#include "State.h"
#include "Machine.h"
GumballMachine::GumballMachine(int numberGumballs){
        count = numberGumballs;
        soldOutState = new SoldOutState(this);
        noQuaterState = new NoQuaterState(this);
        hasQuaterState = new HasQuaterState(this);
        soldState = new SoldState(this);
        winnerState = new WinnerState(this);
        if(count > 0)
            state = noQuaterState;
        else
            state = soldOutState;
        
    };
void GumballMachine::insertQuater(){
    state->insertQuater();
}
void GumballMachine::ejectQuater(){
    state->ejectQuater();
};
void GumballMachine::turnCrank(){
    state->turnCrank();
    state->dispense();
};
void GumballMachine::setState(State *newstate){
    state = newstate;
};
void GumballMachine::releaseBall(){
    if(count > 0){
        count--;
        std::cout << "A gumball comes rolling out the slot..." << std::endl;
    }else{
        std::cout << "No enough gumball" << std::endl;
    }
};
int GumballMachine::getCount(){
    return count;
};
State* GumballMachine::getNoquaterState(){
    return noQuaterState;
};
State* GumballMachine::getSoldOutState(){
    return soldOutState;
};
State* GumballMachine::getHasQuaterState(){
    return hasQuaterState;
};
State* GumballMachine::getSoldState(){
    return soldState;
};
State* GumballMachine::getWinnerState(){
    return winnerState;
};
