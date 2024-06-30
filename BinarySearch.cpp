#include <iostream>
#include <array>


using namespace std;
template <typename T, size_t N>
 int Binarysearch(array<T, N> &arr,int target)
 {
    int start = 0;
    int end = N-1;
     do{
         int mid = start+(end-start)/2;
         
         int v = arr[mid];
         
         if(v == target){
             return mid;
         }
         else if(v < target){
            start = mid+1;
         } else {
            end = mid;     
         }
     } while(start<end);
     return -1;
 }

int main()
{
    array<int, 10> a = {1, 2, 3, 4, 5 ,6, 7 ,8 ,9, 10};
    
    int x = Binarysearch(a, 1);
    cout << a[x] << endl;

    return 0;
}
