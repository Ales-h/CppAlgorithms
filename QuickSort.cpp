#include <iostream>
#include <array>

template <typename T, size_t N>
int partition(std::array<T, N>& arr, int low, int high) {

    const T pivot = arr[high];

    int idx = low - 1;

    for(int i = low; i < high; ++i) {
        if (arr[i] <= pivot) {
            idx++;
            const T tmp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = tmp;
        }
    }
    idx++;
    arr[high] = arr[idx];
    arr[idx] = pivot;

    return idx;
}


template <typename T, size_t N>
void QuickSort(std::array<T, N>& arr, int low, int high) {
    if (low >= high) {
        return;
    }

    const int pivotIdx = partition(arr, low, high);

    QuickSort(arr, low, pivotIdx-1);
    QuickSort(arr, pivotIdx+1, high);

}


int main() {

    std::array<int, 10> a = {3, 6, 8, 9, 4, 13, 7, 4, 3, 4};

    QuickSort(a, 0, 9);

    for(int x: a){
        std::cout << x << std::endl;
    }

    return 0;
}
