#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

bool hasPattern(long long num){
  long long temp = num;
  int digits = 0;

  while(temp > 0){
    temp /= 10;
    digits++;
  }

  for (int len = 1 ; len <= digits/2 ; len++) { //len is possible patterns length
     if (digits % len == 0 ) {
       long long divisor = 1;
       for(int i =0; i < len; i++) divisor *= 10;
       long long suspect_pattern = num % divisor;
       long long current_num = num;
       bool is_match = true;

       while (current_num > 0 ) {
         long long current_chunk = current_num % divisor;
         if (current_chunk != suspect_pattern) {
           is_match = false;
           break;
         }
         current_num /= divisor;
       }

       if(is_match) return true;
     }
  }
  return false;
}

int main(){
  std::ifstream file("input.txt");
  std::string line;
  std::getline(file,line);

  std::replace(line.begin(), line.end(), ',', ' ');
  std::replace(line.begin(), line.end(), '-', ' ');

  std::istringstream iss(line);
  long long start, end;
  long long sum = 0;

  while (iss >> start >> end) {
    for (long long i = start; i <= end; i++) {
      if(hasPattern(i)) sum += i;
    }
  }


  std::cout << sum;


}
