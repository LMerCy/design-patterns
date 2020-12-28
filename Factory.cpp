#include<string>
class Pizza{
public:
    void prepare(){};
    void bake(){};
    void cut(){};
    void box();
};
class PizzaStore{
public:
    Pizza *pizza;
    Pizza orderPizza(std::string type){
        pizza = createPizza(std::string(type));
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
    };
    virtual Pizza* createPizza(std::string type){};    
    virtual ~PizzaStore(){};
};
class NYPizzaStore: public PizzaStore{
public:
    Pizza* createPizza(std::string tyep){
        
    };
};