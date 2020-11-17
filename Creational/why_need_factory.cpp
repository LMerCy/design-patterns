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

void Clinet(const Product & product){
    std::cout << "i dont know which product i use, but it doesn't matter, and i don't need a Creator Class :"<<product.Operation() << std::endl;
}

int main(){
    ProductA* productA = new ProductA();
    Clinet(*productA);
    ProductB* productB = new ProductB();
    Clinet(*productB);
    return 0;
}