#include "Machine.h"
int main(){
    GumballMachine machine(5);
    machine.insertQuater();
    machine.ejectQuater();
    machine.insertQuater();
    machine.turnCrank();
    return 0;
}