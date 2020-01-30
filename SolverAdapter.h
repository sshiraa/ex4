//
// Created by linor on 30/01/2020.
//

#ifndef EX4_SOLVERADAPTER_H
#define EX4_SOLVERADAPTER_H

#include <vector>
#include <string>
#include "Matrix.h"
#include "MatrixFactory.h"
#include "Solver.h"
#include "AstarAlgorithm.h"
#include "Solver.h"
#include "Isearcher.h"
#include "BFSAlgorithm.h"
#include "ISearchable.h"

using namespace std;
class SolverAdapter : public Solver<string, string> {
public:
    virtual string solve(string problem) {
         Matrix m1 = MatrixFactory::createMatrix(problem);
       // matrixProblem = (MatrixFactory:: createMatrix(problem));
        //todo: need to change it to vector of pair<int, int> instead of string as solution
        //todo: maybe changing the return value of matrixProblem to vector of states instead of string
        Isearcher<string, pair<int, int>> *bestFS = new  AstarAlgorithm<string, pair<int, int>>;
        string result = bestFS->search(m1);
      // delete bestFS;
        return result;
    }
};



#endif //EX4_SOLVERADAPTER_H
