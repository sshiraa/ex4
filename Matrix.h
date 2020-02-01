#pragma once
#include <vector>
#include "Isearchable.h"
//template <class T>
class Matrix : public  Isearchable<pair<int, int>> {
private:
	vector<vector<int>> mat;
	int matrixSize = 0;
	State<pair<int, int>> initialState;
	State<pair<int, int>> goalState;
public:
	//Matrix(State<pair<int, int>> state);
	//coonstructor
	Matrix(const vector<vector<int>>& matrix, State<pair<int, int>>&initState, State<pair<int, int>> &goalState) {
		this->mat = matrix;
		this->matrixSize = mat.size();
		this->initialState = initState;
		this->goalState = goalState;
	}
	//getters
	State<pair<int, int>> *getInitialState() {
		return &initialState;
	}
	State<pair<int, int>> *getGoalState() {
		return &goalState;
	}
	int getMatrixSize() {
		return matrixSize;
	}
	vector<State<pair<int, int>>*> getPossibleNextStates(State<pair<int, int>> &curState);
	//for AstarAlgorithm
	vector<State<pair<int, int>> *> getPossibleNextStates(State<pair<int, int>> &curState, State<pair<int, int>> &goal);
};
