#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

bool hasPattern(long long num){
  long long temp = num;
  long long divisor = 1;
  int digits = 0;

  while(temp > 0){
    temp /= 10;
    digits++;
  }

  if (digits % 2 != 0) return false;
  
  for (int i = 0; i < digits/2; i++) {
    divisor *= 10;
  }

  long long first_half = num / divisor;
  long long second_half = num % divisor;


  return first_half == second_half;
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
