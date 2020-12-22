/* 
beverage --description cost
condiment--
*/
#include<string>
#include<iostream>
class Beverage{
public:
    std::string description = "unkown beverage";
    std::string getDescription(){
        return description;
    }
    virtual float cost() = 0;
    virtual ~Beverage(){};
};

class Condiment : public Beverage{
protected:
    Beverage* beverage;
public:
    Condiment(Beverage* bev):beverage(bev){}; 
    virtual std::string getDescription() = 0;
};

class Espresso : public Beverage{
public:
    Espresso(){
        description = "Espresso";
    }
    float cost() override{
        return 1.99;
    }
};

class mocha : public Condiment{
public:
    mocha(Beverage* bev): Condiment(bev){};
    std::string getDescription() override{
        std::cout << "get in " << std::endl;
        std::cout << beverage->getDescription()  + " add mocha" << std::endl;
        return beverage->getDescription() + " add mocha";
    };
    float cost() override{
        return beverage->cost() + 0.99;
    }
};

int main(){
    Beverage *bv = new Espresso();
    std::cout << bv->getDescription() << bv->cost() << std::endl;
    std::cout << bv << std::endl;
    bv = new mocha(bv);
    std::cout << bv << std::endl;
    std::cout << bv->getDescription() << bv->cost() << std::endl;
    return 0;
}