#include <iostream>
#include <vector>

int partition(std::vector<int>& array, int low, int high){

    const int pivot = array[high];
    int idx = low - 1;
    for(int i = low; i <= high; ++i){
        if(array[i] <= array[high]){
            idx++;
            const int tmp = array[i];
            array[i] = array[idx];
            array[idx] = tmp;
        }
    }

    return idx;


}

void QuickSort(std::vector<int>& array, int low, int high){
    if(low >= high){
        return;
    }

    const int IdxPivot = partition(array, low, high);

    QuickSort(array, low, IdxPivot-1);
    QuickSort(array, IdxPivot+1, high);

}

int main() {

    std::vector<int> a = {3, 6, 8, 9, 4, 13, 7, 4, 3, 4};

    QuickSort(a, 0, 9);

    for(int x: a){
        std::cout << x << std::endl;
    }

    return 0;
}
