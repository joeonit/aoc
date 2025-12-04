#include <iostream>
#include <cstdint>
#include <fstream>


int main(){
  
    int16_t current_pos = 50;
    int16_t next_pos = 0;
    int16_t zero_count = 0;
    char direction;
    int16_t distance;
    std::ifstream file("input.txt");

    
    while (file >> direction >> distance) {
      if (distance >= 100) {
        zero_count += distance/100;
        distance = distance % 100;
      }

      if (direction == 'R') {
        next_pos = current_pos + distance;
        if (next_pos >= 100) {
          if (next_pos != 100) {
            zero_count++;
          }
          next_pos = next_pos % 100;
        }
        current_pos = next_pos;
      }
     else {
        next_pos = current_pos - distance;
        if (next_pos < 0 ) {
          if (current_pos > 0)  {
            zero_count++;
          }
          next_pos = 100 + next_pos;
        }
        current_pos = next_pos;
      } 


      if (current_pos == 0 ) {
         zero_count++;
      }
    }

    

    std::cout << zero_count;


}
