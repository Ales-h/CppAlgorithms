#include <iostream>
#include <vector>
#include "BinaryTree.cpp"

template<typename T>
void walk(std::vector<T>& path, BinaryNode<T>* curr){
    // base case
    if(curr == nullptr){
        return;
    }
    //pre
    // recurse
    walk(path, curr->left);
    walk(path, curr->right);
    //post
    path.push_back(curr->value);

}

template<typename T>
std::vector<T> post_order_search(BinaryNode<T>* root){
    std::vector<T> path;
    walk<T>(path, root);
    return path;


}

int main(){
    BinaryNode<int> one = BinaryNode<int>(3);
    BinaryNode<int> two = BinaryNode<int>(10);
    BinaryNode<int> three = BinaryNode<int>(2);
    BinaryNode<int> four = BinaryNode<int>(1);
    BinaryNode<int> five = BinaryNode<int>(9);
    BinaryNode<int> six = BinaryNode<int>(0);
    BinaryNode<int> seven = BinaryNode<int>(5);
    one.right = &two;
    one.left = &three;
    two.left = &four;
    two.right = &five;
    three.left = &six;
    three.right = &seven;

    std::vector<int> traversal = post_order_search(&one);

    for(auto node: traversal){
        std::cout << node << std::endl;
    }
}
