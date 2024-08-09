#include <iostream>
#include <vector>

class MinHeap{
public:

    int length;
    MinHeap(){
        this->length = 0;
    }
    void insert(int value){
        this->data[this->length] = value;
        this->heapifyUp(this->length);
        this->length++;
    }

    int remove(){
        if(this->length == 0){
            return -1;
        }
        const int v = this->data[0];
        this->length--;
        if(this->length==0){
            this->data.pop_back();
            return v;
        }

        this->data[0] = this->data[this->length];
        this->data.pop_back();
        heapifyDown(0);
        return v;
    }

private:
    std::vector<int> data;

    int parent(int idx){
        return ((idx-1)/2);
    }
    int leftChild(int idx){
        return idx * 2 + 1;
    }
    int rightChild(int idx){
        return idx * 2 + 2;
    }
    void heapifyUp(int idx){
        if(idx == 0){
            return;
        }

        const int p = this->parent(idx);
        const int pv = this->data[p];
        const int v = this->data[idx];

        if(pv > v){
            this->data[idx] = pv;
            this->data[p] = v;
            this->heapifyUp(p);
        }
    }
    void heapifyDown(int idx){
        const int lIdx = this->leftChild(idx);
        const int rIdx = this->rightChild(idx);
        if(idx >= this->length || lIdx >= this->length){
            return;
        }
        const int lV = this->data[lIdx];
        const int rV = this->data[rIdx];
        const int v = this->data[idx];
        if(lV > rV && v > rV){

            this->data[idx] = rV;
            this->data[rIdx] = v;
            this->heapifyDown(rIdx);
        } else if(rV > lV && v > lV){
            this->data[idx] = lV;
            this->data[lIdx] = v;
            this->heapifyDown(lIdx);
        }
    }
};
