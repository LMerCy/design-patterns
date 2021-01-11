#include<string>
#include<iostream>
#include<vector>
class Dough{
public:
    Dough(){
        std::cout << "default dough" << std::endl;
    };
};
class ThinCrustDough: public Dough{
public:
    ThinCrustDough(){
        std::cout << "ThinCrustDough" << std::endl;
    };
};
class Sauce{
public:
    Sauce(){
        std::cout << "default Sauce" << std::endl;
    };
};
class MarinaraSauce: public Sauce{
public:
    MarinaraSauce(){
        std::cout << "MarinaraSauce" << std::endl;
    };
};
class Cheese{
public:
    Cheese(){
        std::cout << "default cheese" << std::endl;
    };
};
class ReggianoCheese: public Cheese{
public:
    ReggianoCheese(){
        std::cout << "ReggianoCheese" << std::endl;
    };
};
class Veggies{
public:
    Veggies(){
        std::cout << "defualt veggies" << std::endl;
    };
};
class FreeshVeggies: public Veggies{
public:
    FreeshVeggies(){
        std::cout << "freeesh veggies" << std::endl;
    };
};
class Pepperoni{
public:
    Pepperoni(){
        std::cout << "default pepperoni" << std::endl;
    };
};
class SlicedPepperoni: public Pepperoni{
public:
    SlicedPepperoni(){
        std::cout << "Sliced pepperoni" << std::endl;
    };
};
class Clams{
public:
    Clams(){
        std::cout << "default Clams" << std::endl;
    };
};
class FrozenClams:public Clams{
public:
    FrozenClams(){
        std::cout << "frozenClams" << std::endl;
    };
};
class PizzaIngredientFactory{
public:
    PizzaIngredientFactory(){};
    virtual ~PizzaIngredientFactory(){};
    virtual Dough* createDough() = 0;
    virtual Sauce* createSauce() = 0;
    virtual Cheese* createCheese() = 0;
    // virtual std::vector<Veggies*> createVeggies();
    virtual Pepperoni* createPepperoni() = 0;
    virtual Clams* createClams() = 0;
};
class NYPizzaIngredientFactory : public PizzaIngredientFactory{
public:
    Dough* createDough() override {
        return new ThinCrustDough();
    };
    Sauce* createSauce() override {
        return new MarinaraSauce();
    };
    Cheese* createCheese() override {
        return new ReggianoCheese();
    };
    Pepperoni* createPepperoni() override {
        return new SlicedPepperoni();
    };
    Clams* createClams() override {
        return new FrozenClams();
    };
};
class Pizza{
public:
    std::string name;
    Dough* dough;
    Sauce* sauce;
    Cheese* cheese;
    std::vector<Veggies*> veggies;
    Pepperoni* pepperoni;
    Clams* clams;
    Pizza(){};
    virtual ~Pizza(){};
    virtual void prepare() = 0;
    virtual void bake(){
        std::cout << "Bake for 25 minutess at 350" << std::endl;
    };
    virtual void cut(){
        std::cout << "Cutting the pizza into diagonal slicess" << std::endl;
    };
    virtual void box(){
        std::cout << "Place pizza in official PizzaStore box" << std::endl;
    };
    virtual std::string getName(){
        return name;
    };
};
class CheesePizza:public Pizza{
public:
    PizzaIngredientFactory* pizzaingredient;
    CheesePizza(PizzaIngredientFactory *pg){
        pizzaingredient = pg;
    };
    void prepare(){
        dough = pizzaingredient->createDough();
        sauce = pizzaingredient->createSauce();
        cheese = pizzaingredient->createCheese();
        pepperoni = pizzaingredient->createPepperoni();
        clams = pizzaingredient->createClams();
    };
};
class PizzaStore{
public:
    Pizza *pizza;
    Pizza* orderPizza(std::string type){
        pizza = createPizza(std::string(type));
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        return pizza;
    };
    virtual Pizza* createPizza(std::string type) = 0;    
    virtual ~PizzaStore(){};
};
class NYPizzaStore: public PizzaStore{
public:
    Pizza* createPizza(std::string type){
        PizzaIngredientFactory* pzingredient = new NYPizzaIngredientFactory();
        if(type == "cheese")
            pizza = new CheesePizza(pzingredient);
        else{
            std::cout << "no default cheese, create NYStyleCheesePizza" << std::endl;
            pizza =  new CheesePizza(pzingredient);
        }
        return pizza;
    };
};

// class ChicagoPizzaStore: public PizzaStore{
// public:
//     Pizza * createPizza(std::string type){
//         if(type == "cheese")
//             return new ChicagoStyleCheesePizza();
//         else{
//             std::cout << "no default cheese, create ChicagoStyleCheesePizza" << std::endl;
//             return new ChicagoStyleCheesePizza(); 
//         }
//     }
// };
int main(){
    PizzaStore *ps = new NYPizzaStore();
    // PizzaStore *ps2 = new ChicagoPizzaStore();
    Pizza *pz = ps->orderPizza("cheese");
    // Pizza *pz2 = ps2->orderPizza("cheese");
    std::cout << "order a " << pz->getName() << std::endl;
    // std::cout << "order a " << pz2->getName() <<  std::endl;
    return 0;
}