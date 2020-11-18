#include <iostream>
class QuackInterface{
public:
    virtual void quack() const{};
    virtual ~QuackInterface(){};
};

class Quack:public QuackInterface{
public:
    void quack() const override{
        std::cout << "quack " << std::endl;
    }
};

class MuteQuack:public QuackInterface{
public:
    void quack() const override {
        std::cout << "< silence > " << std::endl;
    }
};

class Squeak:public QuackInterface{
public:
    void quack() const override{
        std::cout << "squeak " << std::endl;
    }
};
class FlyInterface{
public:
    virtual void fly() const{};
    virtual ~FlyInterface(){};
};
class FlyWithWings:public FlyInterface{
    void fly() const override{
        std::cout << " i can fly" << std::endl;
    }
};

class FlyNoWay:public FlyInterface{
    void fly() const override{
        std::cout << " i dont know which" << std::endl;
    }
};
class Duck{
public:
    QuackInterface* quackbehavior;
    FlyInterface* flybehavior;
    void swim(){
        std::cout << "every duck can swim" << std::endl;
    }
    virtual void display(){};
    void performQuack() const{
        quackbehavior->quack();
    }
    void performFly() const{
        flybehavior->fly();
    }
    virtual ~Duck(){};

};

class MallardDuck:public Duck{
public:
    MallardDuck(){
        quackbehavior = new Quack();
        flybehavior = new FlyWithWings();
    }
    void display(){
        std::cout << " i am MallardDuck" << std::endl;
    }
};
int main(){
    MallardDuck mduck;
    mduck.display();
    mduck.performFly();
    mduck.performQuack();
    return 0;
}