#include <iostream>
class Light{
public:
    void on(){
        std::cout << "light on" << std::endl;
    };
};
class Command{
public:
    Command(){};
    virtual ~Command(){};
    virtual void execute(){};
};
class LightOnCommand : public Command{
public:
    Light* light;
    LightOnCommand(Light* lg){
        light = lg;
    };
    void execute(){
        light->on();
    };
};
class SimpleRemoteControl{
public:
    Command * slot;
    SimpleRemoteControl(){};
    void setCommand(Command * sl){
        slot = sl;
    };
    void buttonPressed(){
        slot->execute();
    };
};

int main(){
    SimpleRemoteControl remctl;
    Light* light;
    LightOnCommand* cm = new LightOnCommand(light);
    remctl.setCommand(cm);

    remctl.buttonPressed();
}