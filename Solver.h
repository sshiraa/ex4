//
// Created by shira on 12.1.2020.
//

#ifndef EX4__SOLVER_H_
#define EX4__SOLVER_H_

template <class Problem, class Solution>
class Solver{
 public:
  virtual Solution solve(Problem problem) = 0;
};

#endif //EX4__SOLVER_H_
