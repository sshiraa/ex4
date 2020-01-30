//
// Created by linor on 29/01/2020.
//

#include <vector>
#include "ISearchable.h"
//template <class T>
class Matrix: public  ISearchable<pair<int,int>> {
private:
    vector<vector<int>> mat;
    int matrixSize;
    State<pair<int, int>> initialState;
    State<pair<int, int>> goalState;
public:
    Matrix(State<pair<int, int>> state);
    Matrix(const vector<vector<int>>& matrix, State<pair<int, int>>&initState, State<pair<int, int>> &goalState){
        this->mat = matrix;
        this->matrixSize = mat.size();
        this->initialState = initState;
        this->goalState = goalState;
    }
    virtual State<pair<int, int>> *getInitialState() {
        return &initialState;
    }
    virtual State<pair<int, int>> *getGoalState() {
        return &goalState;
    }
    int getMatrixSize() {
        return matrixSize;
    }
    vector<State<pair<int, int>>*> getAllPossiblesStates(State<pair<int, int>> &curState);

    vector<State<pair<int, int>> *> getPossibleNextStates(State<pair<int, int>> &curState, State<pair<int, int>> &goal);
};

