#include<iostream>
class DuckInterface{
public:
    virtual void quack() =0;
    virtual void fly() =0;
};

class MallardDuck: public DuckInterface{
public:
    void quack(){
        std::cout << "Quack" << std::endl;
    };
    void fly(){
        std::cout << "Fly" << std::endl;
    };
};

class TurkeyInterface{
public:
    virtual void gobble() =0;
    virtual void fly() =0;
};

class WildTurkey: public TurkeyInterface{
public:
    void gobble(){
        std::cout << "Gobble" << std::endl;
    };
    void fly(){
        std::cout << "Fly" << std::endl;
    };
};

class TurkeyAdapter: public DuckInterface{
public:
    TurkeyInterface * turkey;
    TurkeyAdapter(TurkeyInterface *tk){
        turkey = tk;
    };
    void quack(){
        turkey->gobble();
    };
    void fly(){
        for(int i=0;i<5;i++)
            turkey->fly();
    };
};
void testDuck(DuckInterface * duck){
    duck->quack();
    duck->fly();
};
int main(){
    DuckInterface * mduck = new MallardDuck();
    TurkeyInterface * turkey = new WildTurkey();
    testDuck(mduck);
    DuckInterface* fakeDuck = new TurkeyAdapter(turkey);
    testDuck(fakeDuck);
    return 0;
}