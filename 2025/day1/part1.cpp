#include <iostream>
#include <cstdint>
#include <fstream>


int main(){
  
    uint16_t current_pos = 50;
    uint16_t zero_count = 0;
    char direction;
    uint16_t distance;


    std::ifstream file("input.txt");
    
    while (file >> direction >> distance) {
      if (direction == 'R') {
        current_pos = (current_pos + distance) % 100;
      }
      else if (direction == 'L') {
        current_pos = (current_pos - distance % 100 + 100) % 100;
      }


      if (current_pos == 0 ) {
      zero_count++;
      }
    }

    

    std::cout << zero_count;


}
