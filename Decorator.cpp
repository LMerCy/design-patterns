/* 
beverage --description cost
condiment--
*/
#include<string>
class Beverage{
public:
    std::string description;
    std::string getDescription(){
        return description;
    }
    virtual float cost(){};
    virtual ~Beverage(){};
};

class Condiment : public Beverage{
    virtual std::string getDescription(){};
};