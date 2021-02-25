#include<iostream>
template<typename T> // input is T,output is Fun_<T>::type
struct Fun_{using type = T;};

template< >
struct Fun_<int> {using type = unsigned int;};

template< >
struct Fun_<long> {using type = unsigned long;};

template<typename T>
using Fun = typename Fun_<T>::type;

std::remove_reference<int &>::type h1=5;
std::remove_reference_t<int &> h2 = 6;

template<int a,int b> //depend on Add_
struct Add_{
    constexpr static int value = a + b;
};

template<int a,int b> //independent function
constexpr int Add = a + b;

int main(){
    Fun_<int>::type h = 3;
    Fun<int> l = 4;
    std::cout << h << l << std::endl;
    std::cout << h1 << h2 << std::endl;
    std::cout << Add_<3,4>::value << std::endl;
    std::cout << Add<7,5> << std::endl;
    return 0;
}
