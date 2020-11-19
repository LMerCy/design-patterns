#include <iostream>
class QuackInterface{
public:
    virtual void quack() const =0;
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
    virtual void fly() const =0;
    virtual ~FlyInterface(){};
};
class FlyWithWings:public FlyInterface{
    void fly() const override{
        std::cout << "i can fly" << std::endl;
    }
};

class FlyNoWay:public FlyInterface{
    void fly() const override{
        std::cout << "i cant fly" << std::endl;
    }
};

class FlyRoketPowered:public FlyInterface{
    void fly() const override{
        std::cout << "i can fly powered by roket" << std::endl;
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
    void setQuack(QuackInterface *qb){
        quackbehavior = qb;
    };
    void setFly(FlyInterface *fb){
        flybehavior =  fb;
    }

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

class ModelDuck : public Duck{
public:
    ModelDuck(){
        quackbehavior = new Quack();
        flybehavior = new FlyNoWay();
    }
    void display(){
        std::cout << " i am ModelDuck" << std::endl;
    }
};
int main(){
    MallardDuck mduck;
    mduck.display();
    mduck.performFly();
    mduck.performQuack();
    ModelDuck modelduck;
    modelduck.display();
    modelduck.performFly();
    modelduck.setFly(new FlyRoketPowered());
    modelduck.performFly();
    return 0;
}