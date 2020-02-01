/*#pragma once
#include "Isolver.h"
#include <string>
class SearcherSolver:public ISolver<string,string>
{
public:
	SearcherSolver();
	virtual string solve(string problem) {
		MyMatrixSearchable matrixProblem = SearchableMatrixFactory::createMatrix(problem);
		//todo: need to change it to vector of pair<int, int> instead of string as solution
		//todo: maybe changing the return value of matrixProblem to vector of states instead of string
		ISearcher<string, pair<int, int>> *bestFS = new AStarSearcher<string, pair<int, int>>();
		string result = bestFS->search(&matrixProblem);
		delete bestFS;
		return result;
	}
	~SearcherSolver();
};

*/