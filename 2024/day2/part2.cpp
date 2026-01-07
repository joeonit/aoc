#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>


bool isReportsafe(std::vector<int> aReport){
    bool isSafe = true;
    bool increasing = aReport[1] > aReport[0];
    for (int i = 1; i < aReport.size() ; ++i) {
        int diff = aReport[i] - aReport[i - 1];

        if (increasing && (diff <= 0)) { isSafe = false; break; }
        if (!increasing && (diff >= 0)) { isSafe = false; break; }


        int absDiff = std::abs(diff);
        if (absDiff < 1 || absDiff > 3) {
            isSafe = false;
            break;
        }
    }
    return isSafe;
}

int safeCount(const std::vector<std::vector<int> > reports){
    int safeCount = 0;
    for(auto& aReport : reports){

        if (isReportsafe(aReport)) safeCount++;
        else {
            bool safeFound = false;
            for (int i = 0 ; i < aReport.size(); ++i) {

                std::vector<int> temp = aReport;
                temp.erase(temp.begin() + i);

                if(isReportsafe(temp)){
                    safeCount++;
                    safeFound = true;
                    break;
                }

            }
        }

    }

    return safeCount;

}


int main(){

    std::vector<std::vector<int> > reports;


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


std::cout << safeCount(reports) << std::endl;

}
