// https://ksp.mff.cuni.cz/kurz/#task/29-Z1-2
// variation of the fizzbuzz problem

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

const int fizz = 3; // print #
const int buzz = 5; // print O
 // when both print nothing
// else print the number

int main(){
    std::ifstream inFile;
    std::ofstream outFile;

    inFile.open("01.in");
    std::string input;
    std::getline(inFile, input);
    inFile.close();

    std::stringstream ss(input);
    int n, end;
    ss >> n >> end;
    outFile.open("output.txt");
    for(int i = n; i < end; ++i) {
        if(i % fizz == 0 && i % buzz == 0){
        }
        else if(i % fizz == 0){
            outFile << "# ";
        } else if(i % buzz == 0){
            outFile << "O ";
        } else {
            outFile << i;
            outFile << " ";
        }
    }
}
