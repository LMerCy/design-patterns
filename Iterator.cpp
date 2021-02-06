#include<string>
#include<vector>
#include<iostream>
template<class T>
class Iterator{
public:
    Iterator(){};
    virtual ~Iterator(){};
    virtual bool hasNext()=0;
    virtual T* next()=0;
};

class MenuItem{
public:
    std::string name;
    std::string description;
    bool vegetarian;
    double price;
    MenuItem(std::string na, std::string des,bool veg, double pri){
        name = na;
        description = des;
        vegetarian = veg;
        price = pri;
    };
    std::string getName(){
        return name;
    };
    std::string getDescription(){
        return description;
    };
    bool isVegetarian(){
        return vegetarian;
    };
    double getPrice(){
        return price;
    };
};
class Menu{
public:
    Menu(){};
    virtual ~Menu(){};
    virtual Iterator<MenuItem>* createIterator()=0;
};
class DinerMenuIterator: public Iterator<MenuItem>{
public:
    std::vector<MenuItem*> menuItems;
    int position;
    DinerMenuIterator(std::vector<MenuItem*> mitems){
        menuItems = mitems;
        position = 0;
    };
    MenuItem* next(){
        MenuItem* retMenuItem = menuItems[position];
        position++;
        return retMenuItem;
    };
    bool hasNext(){
        if(position >= menuItems.size() || menuItems[position] == 0)
            return false;
        else
            return true;
    };
};
class PancakeHouseMenuIterator : public Iterator<MenuItem>{
public:
    MenuItem** menuItems;
    int position;
    PancakeHouseMenuIterator(MenuItem** mitems){
        menuItems = mitems;
        position = 0;
    };
    MenuItem* next(){
        MenuItem* retMenuItem = menuItems[position];
        position++;
        return retMenuItem;
    };
    bool hasNext(){
        if(menuItems[position] == 0)
            return false;
        else
            return true;
    };
};



class DinerMenu : public Menu{
public:
    std::vector<MenuItem*> menuItems;
    DinerMenu(){
        addItem("K&B's Pancake Breakfast","Pancakes with scrambled eggs, and toast",true,2.99);
		addItem("Regular Pancake Breakfast","Pancake with fried eggs， sausage",false,2.99);
		addItem("Blueberry Pancake","Pancake made with fresh blueberries",true,3.49);
		addItem("Waffles","Waffles, with your cchoice of blueberries or strawberries",true,3.59);
    };
    void addItem(std::string name, std::string description, bool isVegetarian, double price){
        MenuItem* item = new MenuItem(name, description, isVegetarian, price);
        menuItems.push_back(item);
    };
    std::vector<MenuItem*> getMenuItems(){
        return menuItems;
    };
    Iterator<MenuItem>* createIterator(){
        Iterator<MenuItem>* it = new DinerMenuIterator(menuItems);
        return it;
    };
};

class PancakeHouseMenu : public Menu{
public:
    MenuItem** menuItems;
    static const int MAX_ITEMS=7;
    int numberOfItems;
    PancakeHouseMenu(){
        menuItems = new MenuItem*[MAX_ITEMS+1];
        for(int i=0; i<MAX_ITEMS; i++){
            menuItems[i] = 0;
        }
        numberOfItems = 0;
        addItem("Vegtarian BLT","(Fakin) Bacon with lettuce & tomato on whole wheat",true, 2.99);
		addItem("BLT","Bacon with lettuce & tomato on while wheat",false,2.99);
		addItem("Soup of the day","Soup of the day,with a side of potato aalad",false,3.29);
		addItem("Hotdog","A hot dog,with saurkraut, relish, onions, topped with cheese",false,3.05);
		addItem("Steamed Veggies and Brown Rice", "Steamed vegetables over brown rice", true, 3.99);
		addItem("Pasta", "Spaghetti with Marinara Sauce, and a slice of sourdough bread", true, 3.89);
    };
    ~PancakeHouseMenu(){
        delete menuItems;
    };
    void addItem(std::string name, std::string description, bool isVegetarian, double price){

        MenuItem* item = new MenuItem(name, description, isVegetarian, price);
        menuItems[numberOfItems++] = item;
    };
    MenuItem** getMenuItems(){
        return menuItems;
    };
    Iterator<MenuItem>* createIterator(){
        Iterator<MenuItem>* it = new PancakeHouseMenuIterator(menuItems);
        return it;
    };

};
class waitress{
public:
    Menu* pancakeHousemenu;
    Menu* dinerMenu;
    waitress(Menu* pancake, Menu* diner){
        pancakeHousemenu = pancake;
        dinerMenu = diner;
    };
    void printMenu(){
        Iterator<MenuItem>* pancakeIt = pancakeHousemenu->createIterator();
        Iterator<MenuItem>* dinerIt = dinerMenu->createIterator();
        printmenu(pancakeIt);
        printmenu(dinerIt);
    };
private:
    void printmenu(Iterator<MenuItem>* it){
        while(it->hasNext()){
            MenuItem* menu= it->next();
            std::cout << menu->getName() << std::endl;
            std::cout << menu->getDescription() << std::endl;
            std::cout << menu->getPrice() << std::endl;
        }
    };
};

int main(){
    Menu* pancakemenu = new PancakeHouseMenu();
    Menu* dinermenu = new DinerMenu();
    waitress* wait = new waitress(pancakemenu,dinermenu);
    wait->printMenu();
    return 1;
}