#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ifstream file ("input.txt");
    std:: string line;
    int total = 0;


    while(std::getline(file, line)){
        int firstMax = -1;
        int secondMax = -1;
        int i = 0;
        int firstMaxPos = 0;

        while(i < line.length()){
            int digit = line[i] - '0';
            if(digit > firstMax){
                firstMax = digit;
                firstMaxPos = i;
            }
            i++;

        }
        i = firstMaxPos + 1;
        while(i < line.length()){
            int digit = line[i] - '0';
            if(digit > secondMax){
                secondMax = digit;
            }
            i++;
        }
        total += firstMax * 10 + secondMax;
    }
    std::cout << total << std::endl;
}
