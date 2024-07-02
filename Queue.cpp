#include <iostream>
#include <optional>

using namespace std;

template<typename T>
class Node{
    public:
    T v;
    Node* n;
    Node(T item): v(item), n(nullptr){}
};

template<typename T>
class Queue{
    public:
    Node<T>* head;
    Node<T>* tail;
    Queue(const std::initializer_list<T> list): head(nullptr), tail(nullptr), length(0){
        for(const T& item: list)
        {
            enqueue(item);
        }
        
    }
    void enqueue(T item){
        Node<T>* node = new Node<T>(item);
        if(!tail){
            head = node;
            
        } else {
        tail->n = node;
        }
        tail = node;
        length++;
        
    }
    T deque(){
        if(!head){
            return NULL;
        }
        length--;
        Node<T>* dequed_node = head;
        T value = dequed_node->v;
        head = head->n;

        if (length == 0){
            tail = nullptr;
        }

        delete dequed_node;
        return value;
    }
    std::optional<T> peek(){
        if(head){
            return head->v;
        } else {
            return std::nullopt;
        }
    }
    private:
    int length;
};

int main() {

    Queue<int> qu = {3, 4 ,5 ,6};

    cout << qu.deque() << endl;
    cout << qu.deque() << endl;
    cout << qu.deque() << endl;
    cout << qu.deque() << endl;


}