#include <array>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>


int main(){

    std::ifstream inputFile("input.txt");

    if(!inputFile.is_open()){
        std::cerr << "Error in opening file" << std::endl;
        return 1;
    }

    std::string line;
    int sum = 0;
    std::array<std::string , 9> numbers = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    while(std::getline(inputFile, line)){
        std::string number;
        for(int i = 0; i < line.size(); ++i){
            if(number.size() == 1){
                break;
            }
            if(std::isdigit(line[i])){
                number += line[i];
            } else {
                for(int j = 0; j<numbers.size(); ++j){
                    if(line.substr(0, i+1).find(numbers[j]) != std::string::npos){
                        number += std::to_string(j+1);
                    }
                }
            }
        }
        for(int i = line.size(); 0 <= i ; --i){
            if(number.size() == 2){
                break;
            }
            if(std::isdigit(line[i])){
                number += line[i];
            } else {
                for(int j = 0; j<numbers.size(); ++j){
                    if(line.substr(i, line.size()).find(numbers[j]) != std::string::npos){
                        number += std::to_string(j+1);
                    }
                }
            }
        }
        //std::cout << number << std::endl;
        sum += std::atoi(number.c_str());
    }
    std::cout << sum << std::endl;
    return 0;
}
