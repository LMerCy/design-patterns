#include<string>
#include<iostream>
#include<vector>
class Pizza{
public:
    std::string name;
    std::string dough;
    std::string sauce;
    std::vector<std::string> toppings;

    void prepare(){
        std::cout << "Preparing " << name << std::endl;
        std::cout << "Tossing dough..." << std::endl;
        std::cout << "Addinng sauce..." << std::endl;
        std::cout << "Adding topping: ";
        for(auto i:toppings)
            std::cout << " " << i <<std::endl;
    };
    void bake(){
        std::cout << "Bake for 25 minutess at 350" << std::endl;
    };
    void cut(){
        std::cout << "Cutting the pizza into diagonal slicess" << std::endl;
    };
    void box(){
        std::cout << "Place pizza in official PizzaStore box" << std::endl;
    };
    std::string getName(){
        return name;
    };
};
class NYStyleCheesePizza : public Pizza{
public:
    NYStyleCheesePizza(){
        name = "NY Style Sauce and cheese pizza";
        dough = "Thin Crust Dough";
        sauce = "Marinara Saucee";
        toppings.push_back("Grated Reggiano Cheese");
    };
};
class ChicagoStyleCheesePizza : public Pizza{
public:
    ChicagoStyleCheesePizza(){
        name = "Chicago Style Deep Dish cheese pizza";
        dough = "Extra Thick Crust Dough";
        sauce = "Plum Tomato Sauce";
        toppings.push_back("Shredded Mozzarella Cheese");
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
        if(type == "cheese")
            return new NYStyleCheesePizza();
    };
};

int main(){
    PizzaStore *ps = new NYPizzaStore();
    Pizza *pz = ps->orderPizza("cheese");
    std::cout << "order a " << pz->getName() << std::endl;
    return 0;
}