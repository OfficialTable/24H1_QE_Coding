#include <cstdlib>
#include <iostream>
#include <math.h>

bool checkPrime(int input) {
    if (input == 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(input); i++) {
        if (input % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
  unsigned int start_num;
  unsigned int end_num;

  std::cout << "Find prime number within a range:\n";
  std::cout << "--------------------------------------\n";
  std::cout << "-> The start of the range: ";
  // TODO: set start_num
  std::cin >> start_num;

  std::cout << "-> The end of the range: ";
  // TODO: set end_num
  std::cin >> end_num;

  std::cout << "\nThe prime numbers between " << start_num
            << " and " << end_num << " are:" << std::endl;

  // TODO: print prime numbers 
  for (int i = start_num; i <= end_num; i++) {
      bool res = checkPrime(i);
      if (res == true) {
          std::cout << i << " ";
      }
  }

  return EXIT_SUCCESS;
}