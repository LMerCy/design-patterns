#include <iostream>
using namespace std;
class Product{
public:
    virtual ~Product(){}
    virtual std::string Operation() const = 0;
    
};

class ProductA: public Product{
public:
    std::string Operation() const override {
        return "result of ProductA";
    }
};

class ProductB: public Product{
public:
    std::string Operation() const override {
        return "result of ProductB";
    }
};

class Creator{
public:
    virtual ~Creator(){};
    // do stufff
    virtual std::string dostuff() const{
        Product* product = this->create();
        std::string result = "do some stuff by " + product->Operation();
        delete product;
        return result;
    }
    // create product
    virtual Product* create() const =0;
};

class CreatorA: public Creator{
public:
    Product* create() const override{
        return new ProductA();
    }
};

class CreatorB: public Creator{
public:
    Product* create() const override{
        return new ProductB();
    }
};

void Clinet(const Creator & creator){
    std::cout << "i dont know which creator i use : but it doesn't matter"<<creator.dostuff() << std::endl;
}

int main(){
    Creator* creator1 = new CreatorA();
    Clinet(*creator1);
    Creator* creator2 = new CreatorB();
    Clinet(*creator2);
    return 0;
}