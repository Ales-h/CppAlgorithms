#include <iostream>
#include <string>
#include <array>
#include <vector>

struct Point {
    int x;
    int y;
};

const std::array<Point, 4> dir = {
    Point{1, 0},
    Point{-1, 0},
    Point{0, 1},
    Point{0, -1}

};

template <size_t N>
bool walk(std::array<std::array<std::string, N>, N>& maze, std::string wall, Point curr, Point end, std::array<std::array<bool, N>, N>& seen, std::vector<Point>& path){

    if (curr.x < 0 || curr.x >= maze[0].size() ||
        curr.y < 0 || curr.y >= maze[0].size()) {
        return false;
    }

    if(maze[curr.y][curr.x] == wall) {
        return false;
    }

    if(curr.x == end.x && curr.y == end.y) {
        path.push_back(end);
        return true;
    }

    if(seen[curr.y][curr.x]){
        return false;
    }

    // recursion
    //pre
    seen[curr.y][curr.x] = true;
    path.push_back(curr);

    for(int i = 0; i < dir.size(); ++i){
        if(walk(maze, wall, {curr.x+dir[i].x, curr.y+dir[i].y}, end, seen, path)){
            return true;
        }
    }
    path.pop_back();

    return false;

}


int main(){

    std::array<std::array<std::string, 5>, 5> m1 = 
    {
        std::array<std::string, 5>{"W", " ", "W", " ", "W"},  
        std::array<std::string, 5>{"W", " ", "W", " ", "W"},
        std::array<std::string, 5>{" ", " ", " ", " ", "W"},
        std::array<std::string, 5>{"W", " ", "W", " ", "W"},
        std::array<std::string, 5>{"W", " ", "W", " ", "W"}
    };


    std::array<std::array<bool, 5>, 5> seen = {};

    for (auto& row: seen){
        for(bool& value: row){
            value = false;
        }
    }

    std::vector<Point> path = {};

    walk(m1, "W", {1, 4}, {3, 0}, seen, path); 

    for(Point p: path){
        std::cout << "[" << p.x << ", " << p.y << "]" << std::endl;
    }
    return 0;
}