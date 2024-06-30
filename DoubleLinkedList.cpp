// creating a double linked list

#include <iostream>

using namespace std;

class LinkedListNode {
    public:
        int v;
        LinkedListNode* p;
        LinkedListNode* n;

        LinkedListNode(int item): v(item), p(nullptr), n(nullptr) {}
    };
    



int main(){

    LinkedListNode a = LinkedListNode(2);    
    LinkedListNode b = LinkedListNode(5); 
    LinkedListNode c = LinkedListNode(3); 

    a.n = &b;
    b.p = &a;
    b.n = &c;
    c.p = &b;
    
    LinkedListNode* current = &a;
    for(int i = 0; i<3; i++){

        cout << current->v << endl;

        current = current->n;

    }

    return 0;
}