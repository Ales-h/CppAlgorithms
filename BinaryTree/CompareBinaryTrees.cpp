#include "BinaryTree.cpp"

template<typename T>
bool compare(BinaryNode<T>* a, BinaryNode<T>* b){
    if(a == nullptr && b == nullptr){ //structural check
        return true;
    }
    if(a == nullptr || b == nullptr){ // structural check
        return false;
    }
    if(a->value != b->value){ // value check
        return false;
    }

    return compare(a->left, b->left) && compare(a->right, b->right);

}
