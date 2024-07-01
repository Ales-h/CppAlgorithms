// creating a double linked list

#include <iostream>

using namespace std;


template <typename T>
class LinkedListNode {
    public:
        T v;
        shared_ptr<LinkedListNode<T>> p;
        shared_ptr<LinkedListNode<T>> n;
        LinkedListNode(T item): v(item), p(nullptr), n(nullptr) {}
    };

template <typename T>
class LinkedList {
    public:
        shared_ptr<LinkedListNode<T>> head;
        shared_ptr<LinkedListNode<T>> tail;

        LinkedList(const std::initializer_list<T> list) {
            for(const T& item: list){
                append(item);
            }
        }

    void append(T item){
        shared_ptr<LinkedListNode<T>> node_ptr = make_shared<LinkedListNode<T>>(item);
        if(tail) {
            node_ptr->p = tail;
            tail->n = node_ptr;
        } else {
            head = node_ptr;
        }
        tail = node_ptr;
        this->length += 1;
    }
    void print(){
        shared_ptr<LinkedListNode<T>> current = head;
        for(int i = 0; i<this->length; i++){
            cout << current->v << endl;
            current = current->n;
        }
    }
    int size(){
        return this->length;
    }
    private:
        int length;
    
        
};
    



int main(){

    LinkedList<int> list = {3, 2, 1, 5, 6, 7, 2};
    
    std::cout << list.size() << endl;
    list.print();
    std::cout << list.size() << endl;
    list.append(3);
    list.append(15);
    list.print();    
    std::cout << list.size() << endl;
    return 0;
}