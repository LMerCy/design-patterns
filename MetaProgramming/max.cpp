#include<iostream>
#include<type_traits>
#include<typeinfo>
template<typename T1, typename T2, typename T3>
T3 max(T1 a, T2 b){
    return a>b?a:b;
}
// only c++ 14 support
// template<typename T1, typename T2>
// auto max2(T1 a, T2 b){
//     return a>b?a:b;
// }
// for c++11, but return param cannot be reference type
template<typename T1, typename T2>
auto max3(T1 a, T2 b) -> decltype(a>b?a:b){
    return a>b?a:b;
}
// for c++11, return param can be reference type
template<typename T1, typename T2>
auto max4(T1 a, T2 b) -> typename std::decay<decltype(a>b?a:b)>::type {
    return a>b?a:b;
}
// for c++14 with constexpr and auto
template<typename T1, typename T2>
constexpr auto max5(T1 a, T2 b){
    return a>b?a:b;
}
int main() {
    // std::cout << max<double,int,double>(52.6,44) << std::endl;
    int a = 44;
    float b = 52.6;
    float &c = b;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    // auto h = max2(c,a);
    // h = 17;
    auto f = max4(c,a);
    f = 19;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    auto k = max5(a,b);
    std::cout << k << std::endl;
    return 0;
}