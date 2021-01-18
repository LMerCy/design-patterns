#include <iostream>
#include<vector>
class Light{
public:
    void on(){
        std::cout << "light on" << std::endl;
    };
    void off(){
        std::cout << "light off" << std::endl;
    };
};
class GarageDoor{
public:
    void up(){
        std::cout << "up" << std::endl;
    };
    void down(){
        std::cout << "down" << std::endl;
    };
    void stop(){
        std::cout << "stop" << std::endl;
    };
    void lighton(){
        std::cout << "GrageDoor open" << std::endl;
    };
    void lightoff(){
        std::cout << "GrageDoor off" << std::endl;
    };
};

class Command{
public:
    Command(){};
    virtual ~Command(){};
    virtual void execute(){};
    virtual void undo(){};
};
class NoCommand: public Command{
public:
    NoCommand(){};
    void execute(){};
    void undo(){};

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
    void undo(){
        light->off();
    };
};
class LightOffCommand : public Command{
public:
    Light* light;
    LightOffCommand(Light* lg){
        light = lg;
    };
    void execute(){
        light->off();
    };
    void undo(){
        light->on();
    };
};
class GarageDoorOpenCommand : public Command{
public:
    GarageDoor* door;
    GarageDoorOpenCommand(GarageDoor* dr){
        door = dr;
    };
    void execute(){
        door->lighton();
    };
    void undo(){
        door->lightoff();
    };
};
class GarageDoorCloseCommand : public Command{
public:
    GarageDoor* door;
    GarageDoorCloseCommand(GarageDoor* dr){
        door = dr;
    };
    void execute(){
        door->lightoff();
    };
    void undo(){
        door->lighton();
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
class RemoteControl{
public:
    std::vector<Command*> oncommand;
    std::vector<Command*> offcommand;
    RemoteControl(){
        oncommand = std::vector<Command*>(7,new NoCommand);
        offcommand = std::vector<Command*>(7, new NoCommand);
    };
    void setCommand(int slot, Command * oncmd, Command * offcmd){
        oncommand[slot] = oncmd;
        offcommand[slot] = offcmd;
    };
    void onButtonPressed(int slot){
        oncommand[slot]->execute();
    };
    void offButtonPressed(int slot){
        offcommand[slot]->execute();
    };
};
class RemoteControlWithUndo{
public:
    std::vector<Command*> oncommands;
    std::vector<Command*> offcommands;
    Command * lastcommand;
    RemoteControlWithUndo(){
        oncommands = std::vector<Command*>(7,new NoCommand);
        offcommands = std::vector<Command*>(7, new NoCommand);
        lastcommand = new NoCommand;
    };
    void setCommand(int slot, Command* oncmd, Command* offcmd){
        oncommands[slot] = oncmd;
        offcommands[slot] = offcmd;
    };
    void onButtonPressed(int slot){
        oncommands[slot]->execute();
        lastcommand = oncommands[slot];
    };
    void offButtonPressed(int slot){
        offcommands[slot]->execute();
        lastcommand = offcommands[slot];
    };
    void undo(){
        lastcommand->undo();
    }
};
int main(){
    // SimpleRemoteControl remctl;
    Light* light;
    LightOnCommand* lightoncmd = new LightOnCommand(light);
    LightOffCommand* lightoffcmd = new LightOffCommand(light);

    GarageDoor* door;
    GarageDoorOpenCommand * doorpencmd = new GarageDoorOpenCommand(door);
    GarageDoorCloseCommand * doorclosecmd = new GarageDoorCloseCommand(door);    
    // simple remotecontrol
    // remctl.setCommand(lightoncmd);
    // remctl.buttonPressed();

    // remctl.setCommand(dooopencmd);
    // remctl.buttonPressed();

    // RemoteControl remotectl;
    RemoteControlWithUndo remotectl;
    remotectl.setCommand(0,lightoncmd,lightoffcmd);
    remotectl.setCommand(1, doorclosecmd,doorclosecmd);

    remotectl.onButtonPressed(0);
    remotectl.undo();
    remotectl.onButtonPressed(1);
    remotectl.undo();
    // remotectl.offButtonPressed(0);
    // remotectl.offButtonPressed(1);
    return 0;
}