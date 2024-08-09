// you are given an 2D array of 1s and 0s, count how many islands of 1s there is.
// example:
// [
// 1, 0, 0, 0, 1
// 1, 1, 0, 0, 0
// 1, 0, 0, 0, 1,
// 0, 0, 0, 0, 1
// ] => in this example there are 3 islands

// implementation

#include <tuple>
#include <array>
#include <iostream>
#include <vector>

std::array<std::pair<int, int>, 4> directions = {
    std::make_pair(1, 0),
    std::make_pair(-1, 0),
    std::make_pair(0, 1),
    std::make_pair(0, -1),
};
void delete_island(std::vector<std::vector<int>>& map, std::vector<std::vector<bool>>& seen,
           int x, int y, int& islands){
    //base case
    if(y >= map.size() || x >= map[0].size()){
        return;
    }
    if(seen[y][x]){
        return;
    }
    seen[y][x] = true;
    if(map[y][x] == 0){
        return;
    }
    for(int i = 0; i<directions.size(); ++i){
        std::pair<int, int> dir = directions[i];
        delete_island(map , seen, x+std::get<0>(dir), y+std::get<1>(dir), islands);
    }
}

int count_islands(std::vector<std::vector<int>> arr){
    std::vector<std::vector<bool>> seen(arr.size(), std::vector<bool>(arr[0].size(), false));
    int islands = 0;
    for(int y = 0; y<arr.size(); ++y){
        for(int x = 0; x<arr[0].size(); ++x){
            if(!seen[y][x] && arr[y][x] == 1){
                ++islands;
                delete_island(arr, seen, x, y, islands);
            }
        }
    }
    return islands;
}

int main(){

    std::vector<std::vector<int>> arr = {
    {1, 0, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 0, 0, 0, 1},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 1, 1},
};

    std::cout << count_islands(arr) << std::endl;
}
