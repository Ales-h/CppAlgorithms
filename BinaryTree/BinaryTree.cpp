template<typename T>
class BinaryNode{
public:
    T value;
    BinaryNode* left;
    BinaryNode* right;
    BinaryNode(T v): value(v), left(nullptr), right(nullptr){}
    ~BinaryNode(){
// delete left;
   //     delete right;
    }
};


