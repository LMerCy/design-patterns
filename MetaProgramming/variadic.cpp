#include<iostream>
void print(){};
template<typename T, typename... Types>
void print(T firstarg, Types... args){
    std::cout << firstarg << std::endl;
    std::cout << sizeof...(args) << std::endl;
    // this is wrong, because two branches of if would be instantiate, but instantiate happens during complile time. Which branch would
    // be use determined during runtime.
    // c++17 support if-during-compile
    // if(sizeof...(args) >0 )
    //     print(args...);
}
template<typename T>
class AddSpace{
private:
    T const& ref;
public:
    AddSpace(T const& value):ref(value){};
    friend std::ostream&  operator<< (std::ostream& os, AddSpace<T> s){
        return os<< s.ref<<" ";
    } 
};
template<typename... Types>
void print17(Types... args){
    (std::cout << ... << AddSpace<Types>(args) ) << std::endl;
}
int main(){
    std::string s("word");
    print17(7.0, "hello",s);
    return 0;
}