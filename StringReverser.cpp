//
// Created by shira on 26.1.2020.
//

#include "StringReverser.h"
#include <algorithm>
#include <cstring>

string StringReverser::solve(string problem) {
  reverse(problem.begin(), problem.end());
  return problem;
}



/*
char * reversString(const char* str) {
  char *reversed;
  int strLen = strlen(str);
  for(int i = 0; i < strLen; i++) {
    reversed[i] = str[strLen - i - 1];//reversed.append(1, str[i]);
  }
  reversed[strLen] = '\n';//adding '\n' at the end

  return reversed;
}*/
