#include <iostream>
#include <queue>
#include "BinaryTree.cpp"

template<typename T>
bool bfs(BinaryNode<T>* head, T needle){

    std::queue<BinaryNode<T>*> q;
    q.push(head);

    while(q.size()> 0){

        BinaryNode<T>* curr = q.front();
        q.pop();

        if(curr == nullptr){
            continue;
        }

        if(curr->value == needle){
            return true;
        }

        q.push(curr->left);
        q.push(curr->right);
    }

    return false;
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


    std::cout << bfs(&one, 9) << std::endl;
}
