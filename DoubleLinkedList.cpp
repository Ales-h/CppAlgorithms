// creating a double linked list

#include <iostream>
#include <stdexcept>

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
        length += 1;
    }

    void prepend(T item){
        shared_ptr<LinkedListNode<T>> node_ptr = make_shared<LinkedListNode<T>>(item);
        if(head) {
            node_ptr->n = head;
            head->p = node_ptr;
        } else {
            tail = node_ptr;
        }
        head = node_ptr;
        length += 1;
    }

    void insertAt(T item, int index){
        if (index<0 || length-1<index){
            throw std::out_of_range("Index is out of range. Range: 0-" + std::to_string(length-1));
        }
        if(head == nullptr){
            throw std::logic_error("The list is empty.");
        }
        shared_ptr<LinkedListNode<T>> current = head;
        shared_ptr<LinkedListNode<T>> node_ptr = make_shared<LinkedListNode<T>>(item);

        for(int i = 0; i<index; ++i){
            current = current->n;
        }
        node_ptr->p = current->p;
        node_ptr->n = current;
        current->p->n = node_ptr;
        current->p = node_ptr;
        length += 1;
    }
    
    int size(){
        return this->length;
    }
    private:
        int length;
    
        
};
template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list){
    os << "[";

    shared_ptr<LinkedListNode<T>> current = list.head;
    while(current != nullptr){
        os << current->v;
        if(current->n != nullptr){
            os << ", ";
        }
        current = current->n;
    }    
    os << "]";

    return os;
}
    



int main(){

    LinkedList<int> list = {3, 2, 1, 5, 6, 7, 2};
    
    std::cout << list.size() << endl;
    cout << list << endl;
    list.append(3);
    list.append(15);
    cout << list << endl;
    list.prepend(345);
    cout << list << endl;
    list.insertAt(22, 3);
    cout << list << endl;
    list.insertAt(10, 15);
    cout << list << endl;
    std::cout << list.size() << endl;
    return 0;
}