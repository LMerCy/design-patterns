
#include<iostream>
template<bool isFeedback, typename T,
            std::enable_if_t<isFeedback>* = nullptr>
auto FeedbackOut(T&&){std::cout << 3 << std::endl;}

template<bool isFeedback, typename T,
            std::enable_if_t<!isFeedback>* = nullptr>
auto FeedbackOut(T&&){std::cout << 4 << std::endl;}

template<bool Check> 
auto fun(){
    if constexpr (Check){ //only c++17 support
        return (int)0;
    }else{
        return (float)0.4;
    }
}
int main(){
    FeedbackOut<false,int>(5);
    std::cout << fun<false>() << std::endl;
    return 0;
}