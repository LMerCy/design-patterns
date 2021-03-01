#include<iostream>
template<unsigned int input>
constexpr unsigned int OnesCount = (input % 2) + OnesCount<(input/2)>;

template <> constexpr unsigned int OnesCount<0> = 0;

template <unsigned int...Inputs>
constexpr unsigned int Accumulate = 0;

template <unsigned int CurInput, unsigned int...Inputs>
constexpr unsigned int Accumulate<CurInput, Inputs...> = CurInput + Accumulate<Inputs...>;

template <unsigned int ... values>
constexpr unsigned int fun(){
    return (0 + ... + values);
}

template <unsigned int ... values>
unsigned int fun2(){
    if constexpr(values == 0)
        return 0;
    else
    {
        return fun<values...>();
    }
    
}
int main(){
    constexpr unsigned int res = OnesCount<45>;
    std::cout << res<< std::endl;
    constexpr unsigned int res2 = Accumulate<1,2,3,4,5>;
    std::cout << res2 << std::endl;
    constexpr unsigned int res3 = fun<1,2,3,4,5>();
    std::cout << res3 << std::endl;
    unsigned int res4 = fun2<1,2,3,4,5>();
    std::cout << res4 << std::endl;
    return 0;
}
