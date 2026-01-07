#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>

int main(){
    int simscore = 0;
    int count = 0;
    int totalscore = 0;
    int curtleft;
    int curright;
    std::vector<int> left;
    std::vector<int> right;

    std::fstream file("input.txt");
    while (file >> curtleft >> curright) {
        left.push_back(curtleft);
        right.push_back(curright);
    }

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    for (int i =0; i < left.size(); ++i) {
        for (int j=0 ; j < right.size(); ++j) {
            if(left[i] == right[j] ) count++;
            simscore = left[i] * count;
        }
        count = 0;
        totalscore += simscore;
    }



    std::cout << totalscore << std::endl;



}
