//
// Created by shira on 26.1.2020.
//

#ifndef EX4__STRINGREVERSER_H_
#define EX4__STRINGREVERSER_H_

#include "Solver.h"
#include "string"
using namespace std;

class StringReverser : public Solver<string, string> {
 public:
  virtual string solve(string);
 private:
  string reversString(string str);
};


#endif //EX4__STRINGREVERSER_H_