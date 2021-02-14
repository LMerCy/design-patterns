#include<iostream>
#include<random>
#include "Machine.h"
#include "State.h"
SoldOutState::SoldOutState(GumballMachine * gumballMachine){
    machine = gumballMachine;
};
void SoldOutState::insertQuater(){
    std::cout << "Sry, gumballs have been sold out" << std::endl;
};
void SoldOutState::ejectQuater(){
    std::cout << "you havn't inserted a quater" << std::endl;
};
void SoldOutState::turnCrank(){
    std::cout << "you havn't inserted a quater'" << std::endl;
};
void SoldOutState::dispense(){
    std::cout << "you havn't inserted a quater" << std::endl;
};


NoQuaterState::NoQuaterState(GumballMachine * gumballMachine){
    machine = gumballMachine;
};
void NoQuaterState::insertQuater(){
    std::cout << "You have inserted a Quater" << std::endl;
    machine->setState(machine->getHasQuaterState());
};
void NoQuaterState::ejectQuater(){
    std::cout << "Please insert a quater" << std::endl;
};
void NoQuaterState::turnCrank(){
    std::cout << "You turned, but there's no quater" << std::endl;
};
void NoQuaterState::dispense(){
    std::cout << "Please insert a quater" << std::endl;
};


HasQuaterState::HasQuaterState(GumballMachine * gumballMachine){
    machine = gumballMachine;
};
void HasQuaterState::insertQuater(){
    std::cout << "You can't insert another Quater" << std::endl;
};
void HasQuaterState::ejectQuater(){
    std::cout << "Quater returned!" << std::endl;
    machine->setState(machine->getNoquaterState());
};
void HasQuaterState::turnCrank(){
    std::cout << "Turn ..." << std::endl;
    machine->setState(machine->getSoldState());
};
void HasQuaterState::dispense(){
    std::cout << "You should turnDrank First!" << std::endl;
};


SoldState::SoldState(GumballMachine *gumballMachine){
    machine = gumballMachine;
};
void SoldState::insertQuater(){
    std::cout << "Please hold, we will give you a gumball" << std::endl;
};
void SoldState::ejectQuater(){
    std::cout << "Sry, you have turned the crank" << std::endl;
};
void SoldState::turnCrank(){
    std::cout << "Wait, you will get a gumball" << std::endl;
};
void SoldState::dispense(){
    machine->releaseBall();
    if(machine->getCount() > 0)
        machine->setState(machine->getNoquaterState());
    else
        machine->setState(machine->getSoldOutState());
};


WinnerState::WinnerState(GumballMachine *gumballMachine){
    machine = gumballMachine;
}
void WinnerState::insertQuater(){
    std::cout << " you have already inserted a quater" << std::endl;
};
void WinnerState::ejectQuater(){
    std::cout << "Sry, you have turned the crank" << std::endl;
};
void WinnerState::turnCrank(){
    std::cout << "You have turned crank, please wait" << std::endl;
};
void WinnerState::dispense(){
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
