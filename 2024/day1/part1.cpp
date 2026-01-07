#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>

int main(){
    int totaldis = 0;
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
        totaldis += abs(left[i] - right[i]);
    }

    std::cout << totaldis << std::endl;



}
