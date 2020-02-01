
#ifndef EX4_SOLVERADAPTER_H
#define EX4_SOLVERADAPTER_H

#include <vector>
#include <string>
#include "Matrix.h"
#include "MatrixFactory.h"
#include "Solver.h"
#include "Isearcher.h"
#include "BFSAlgorithm.h"
#include "DFSAlgorithm.h"
#include "Isearchable.h"
#include "AstarAlgorithm.h"
#include "BestFirstSearch.h"
#include "iostream"

using namespace std;
class SolverAdapter : public Solver<string, string> {
public:
	string solve(string problem) {
		//string result = "";
		Matrix m1 = MatrixFactory::createMatrix(problem);
		//Matrix m2 = MatrixFactory::createMatrix(problem);
		//Matrix m3 = MatrixFactory::createMatrix(problem);
		//Matrix m4 = MatrixFactory::createMatrix(problem);
		// matrixProblem = (MatrixFactory:: createMatrix(problem));
		/*Isearcher<string, pair<int, int>> *bestFS = new  BFSAlgorithm<string, pair<int, int>>;
		string result = bestFS->search(&m1);
		cout <<"bestFs"+ result << endl<< endl<< endl;*/
		//Isearcher<string, pair<int, int>> *dfsAlgo = new  DFSAlgorithm<string, pair<int, int>>;
		//string result = dfsAlgo->search(&m2);
		//cout <<"dfs"+ result << endl << endl << endl;
		/*Isearcher<string, pair<int, int>> *bestFirstSearch = new  BestFirstSearch<string, pair<int, int>>;
		string result = bestFirstSearch->search(&m3);*/
		//cout << "best" + result << endl << endl << endl;
		Isearcher<string, pair<int, int>> *Astar = new  AstarAlgorithm<string, pair<int, int>>;
		string result = Astar->search(&m1);
		//cout <<"astar"+ result << endl << endl << endl;
	
		return result;
	}
};



#endif //EX4_SOLVERADAPTER_H

