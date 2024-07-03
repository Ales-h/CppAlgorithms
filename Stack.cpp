//   A<-B<-C<-D<-E
//               |
//               head
// remove and add only at the head (end of the stack)                  
// im using normal pointers to practice memory management

#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

template <typename T>
class Node{
    public:
    Node<T>* p; // previous
    T v; // value

    Node(const T& item): v(item), p(nullptr) {}
};

template <typename T>
class Stack{
    public:

    Node<T>* head;
    Stack(std::initializer_list<T> list): head(nullptr), length(0) {
        for(const T& item: list){
            push(item);
        }
    }
    void push(const T& item){
        Node<T>* node = new Node<T>(item);
        if(head){
            node->p = head;
        }
        head = node;
        length++;
    }
    T pop(){
        if(!head){
            throw std::underflow_error("The Stack is empty or head is nullptr.");
        }
        length = max(0, length-1);

        if(length == 0){
            Node<T>* h = head;
            head = nullptr;
            T value = h->v;
            delete h;
            return value;
        }
        Node<T>* h = head;
        head = head->p;
        T value = h->v;
        delete h;
        return value;

        
    }
    T peek(){
        if(head){
            return head->v;
        } else { 
            return NULL;
        }

    }
    int size(){
        return length;
    }
    private:
    int length;


    
};

int main(){

    Stack<int> st = {3, 2, 1};
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.peek() << endl;
    st.push(32);
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;



    return 0;
}