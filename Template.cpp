#include<iostream>
class CaffeineBeverageWithHook{
public:
    void prepareRecipe(){
        boilWater();
        brew();
        poureIncup();
        if(customerWantsCondiments()){
            addCondiments();
        };
    };
    void boilWater(){
        std::cout << "boil water" << std::endl;
    };
    virtual void brew(){};
    virtual void addCondiments(){};
    void poureIncup(){
        std::cout << "poure incup" << std::endl;
    };
    virtual bool customerWantsCondiments(){
        return true;
    };
};

class Tea : public CaffeineBeverageWithHook{
public:
    void brew(){
        std::cout << "drip coffee" << std::endl;
    };
    void addCondiments(){
        std::cout << "add sugar and milk" << std::endl;
    };
    bool customerWantsCondiments(){
        std::string answer = getInput();
        if(answer == "y")
            return true;
        else if(answer == "n")
            return false;
        
    };
    std::string getInput(){
        std::string answer;
        std::cout << "do you want to add condiment?(y/n)" << std::endl;
        std::cin >> answer;
        return answer;
    };
};

int main(){
    CaffeineBeverageWithHook* tea = new Tea();
    tea->prepareRecipe();
    return 0;

}