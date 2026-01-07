#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <limits>

int main(){
    int safeCount = 0;
    std::vector<std::vector<int>> reports;
    std::ifstream file("input.txt");

    while (file.peek() != EOF) {
        std::vector<int> aReport;
        int currNum;
        while (file >> currNum) {
            aReport.push_back(currNum);
            if (file.peek() == '\n' || file.peek() == EOF) break;
        }
        reports.push_back(aReport);
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    for(const auto& aReport : reports){
        bool isSafe = true;
        bool increasing = aReport[1] > aReport[0];
        for (int i = 1; i < aReport.size() ; ++i) {
            int diff = aReport[i] - aReport[i - 1];
            if (increasing && (diff <= 0)) {
                isSafe = false;
                break;
            }
            if (!increasing && (diff >= 0)) {
                isSafe = false;
                break;
            }
            int absDiff = std::abs(diff);
            if (absDiff < 1 || absDiff > 3) {
                isSafe = false;
                break;
            }
        }
        if (isSafe) {safeCount++;}
    }

    std::cout << safeCount << std::endl;
}
