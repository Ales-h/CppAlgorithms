#include <iostream>

using namespace std;

 int search(int start, int end, int arr[], int target)
 {
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
    int a[10] = {1, 2, 3, 4, 5 ,6, 7 ,8 ,9, 10};
    
    int x = search(0, 9, a, 1);
    cout << a[x] << endl;

    return 0;
}
