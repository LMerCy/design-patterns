#include<iostream>
struct Node{
    int value;
    Node* left;
    Node* right;
    Node(int i =0):value(i),left(nullptr),right(nullptr){};
};
template<typename T>
class NodeValue{
private:
    T const& ref;
public:
    NodeValue(T const& node):ref(node){};
    friend std::ostream&  operator<< (std::ostream& os, NodeValue<T> s){
        return os<< s.ref->value<<" ";
    } 
};
auto left=&Node::left;
auto right=&Node::right;
template<typename T, typename... TP>
Node* traverse(T np, TP... paths){
    return (np->*...->*NodeValue<TP>(paths));// only support in c++17
}

int main(){
    Node* root = new Node{0};
    root->left = new Node{1};
    root->right = new Node{2};
    root->left->right = new Node{3};
    Node* node = traverse(root,left,right);
    std::cout << node->value << std::endl;
}