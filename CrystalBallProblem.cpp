// Crystal ball problem: you have 2 crystal balls and 100-floor building, you have to write an algorithm that will find the highest floor where the ball doesnt break if you throw it down.

#include <iostream>
#include <cmath>
#include <array>

using namespace std;

template <std::size_t N>
int crystal_ball(array<bool, N> &arr){
    int size = arr.size();
    int x = 1;
    int y = (int)sqrt((double) size);
    do{
        cout << y*x << endl;
          if(arr[y*x]){
            x += 1;
        } else{
            for (int i = (x-1)*y; i<x*y; i++){
                if(!arr[i]){
                    return i;
                }
            }
            break;
        }
    }while(x<y);
    return x-1;
  
}

int main()
{
    array<bool, 25> a = {true, true, true, true, true,true, true, true, true, true,true, true, true, false, false, false, false, false, false, false,  false, false, false, false, false};;
    
    int f = crystal_ball(a);
    cout << f << endl;
    return 0;
}
