#include<iostream>
template<typename D>
struct Base
{
    static void Fun(){
        D::Imp();
    }
};
struct Derive : public Base<Derive>
{
    static void Imp(){
        std::cout << "implementation from derive class" << std::endl;
    }
};
int main(){
    Derive::Fun();
}
