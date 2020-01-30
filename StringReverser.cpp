//
// Created by shira on 26.1.2020.
//

#include "StringReverser.h"
#include <algorithm>
#include <iostream>

string StringReverser::solve(string problem) {
  std::cout << problem << std::endl;
  //reverse the string
  problem = (string)reversString(problem);
  std::cout << problem << std::endl;
  return problem;
}

string StringReverser::reversString(string str) {
    int strLen = str.length();
    // Swap character from edges to middle
    for (int i = 0; i < strLen / 2; i++)
      swap(str[i], str[strLen - i - 1]);
  return str;
}
