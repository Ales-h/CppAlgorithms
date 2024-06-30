#include <iostream>
#include <array>

using namespace std;


template <typename T, std::size_t N>
void Bubblesort(array<T, N>& arr){
int n = arr.size();

for(int i = 0; i<n; ++i)
{
    for(int j = 0; j<n - 1 -i; ++j)
    {
        if(arr[j]>arr[j+1])
        {
            int tmp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = tmp;
        }
    }
}

}

int main(){
    array<int, 9> arr = {3, 4 ,5 ,6 , 7, 9, 8, 1, 2};
    int size = arr.size();
    for(int i; i<size; i++)
    {
        cout << arr[i] << endl;
    }

    Bubblesort(arr);

    for(int j=0; j<size; j++)
    {
        cout << arr[j] << endl;
    }

    return 0;
}