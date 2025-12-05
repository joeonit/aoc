#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <string>

bool hasPattern(long long num){
  static const std::regex pattern(R"(^(.+)\1$)");
  std::string s = std::to_string(num);
  return std::regex_match(s, pattern);
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

