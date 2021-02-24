static int call_count=3;
constexpr int func2(int a){
    // return a+(call_count); //error
    return a+1;
}
int main(){
    return 0;
}