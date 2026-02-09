#include <fstream>
#include <iostream>
#include <string>
#include <vector>


int countGrid(const std::vector<std::string>& grid, int row, int col){
    int count = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    if (row > 0 && col > 0 && grid[row-1][col-1] == '@') count++;    //topleft
    if (row > 0 && grid[row-1][col] == '@') count++;        //top
    if (row > 0 && col < cols-1 && grid[row-1][col+1] == '@') count++; //topright
    if (col > 0 && grid[row][col-1] == '@') count++; //left
    if (col < cols-1 && grid[row][col+1] == '@') count++; //right
    if (row < rows-1 && col > 0 && grid[row+1][col-1] == '@') count++; //buttomleft
    if (row < rows-1 && grid[row+1][col] == '@') count++; //buttom
    if (row < rows-1 && col < cols-1 && grid[row+1][col+1] == '@') count++; //buttomright
    return count;
}

int main(){
    std::vector<std::string > grid;
    std::ifstream file("input.txt");
    std::string line;

    while (std::getline(file, line)) {
        grid.push_back(line);
    }


    int accessible_cout = 0;
    for (int row = 0; row < grid.size() ; ++row) {
        for (int col = 0; col < grid[row].size(); ++col) {
            if (grid[row][col] == '@') {
                int adjacentcount = countGrid(grid,row,col);
                if(adjacentcount < 4){
                    accessible_cout++;
                }
            }
        }
    }

    std::cout << accessible_cout << std::endl;



}
