//
// Created by linor on 29/01/2020.
//
#include "Matrix.h"
#include <cmath>
vector<State<pair<int, int>>*> Matrix::getAllPossiblesStates(State<pair<int, int>>&curState) {
    vector<State<pair<int,int>>*> possibleState;
    State<pair<int, int>> *state1,*state2,*state3,*state4;
    double cost = curState.getCost();
    int indexI = curState.getObject().first;
    int indexJ = curState.getObject().second;
    int n = this->matrixSize;
    if (indexI != 1 && mat[indexI - 1][indexJ] != -1) {
        int value = mat[indexI - 1][indexJ];
        double newCost = cost + value;
        state1 = new State<pair<int,int>>(make_pair(indexI - 1, indexJ), newCost, &curState, UP);
        possibleState.push_back(state1);
    }
    if (indexI != n && mat[indexI + 1][indexJ] != -1) {
        int value = mat[indexI + 1][indexJ];
        double newcost =cost + value;
        state2 = new State<pair<int,int>>(make_pair(indexI + 1, indexJ), newcost, &curState, DOWN);
        possibleState.push_back(state2);
    }
    if (indexJ != 1 && mat[indexI][indexJ - 1] != -1) {
        int value = mat[indexI][indexJ - 1];
        double newCost = cost+ value;
        state3 = new State<pair<int, int>>(make_pair(indexI, indexJ-1), newCost, &curState, LEFT);
        possibleState.push_back(state3);
    }
    if (indexJ != n && mat[indexI][indexJ + 1] != -1) {
        int value = mat[indexI][indexJ + 1];
        double newCost = cost + value;
        state4 = new State<pair<int,int>>(make_pair(indexI, indexJ + 1), newCost, &curState, RIGHT);
        possibleState.push_back(state4);
    }
    return possibleState;
}
vector<State<pair<int, int>>*> Matrix::getPossibleNextStates(State<pair<int, int>> &curState, State<pair<int, int>> &goal) {
    vector<State<pair<int, int>> *> result;
    int i = curState.getCameFrom()->getObject().first;
    int j = curState.getCameFrom()->getObject().second;
    int fatherI, fatherJ;
    if (curState.getCameFrom() != NULL) {
        fatherI = curState.getCameFrom()->getObject().first;
        fatherJ = curState.getCameFrom()->getObject().second;
    } else {
        fatherI = fatherJ = -1;
    }
    int manhattanDisCurrent = std::abs(goal.getObject().first - i) + std::abs(goal.getObject().second - j);
    //if the index exist and the value isn't minus one, which is infinity
    if (i < matrixSize - 1 && mat[i + 1][j] >= 0 && fatherI != i + 1) {
        int manhattanDistance = std::abs(goal.getObject().first - (i + 1)) + std::abs(goal.getObject().second - (j));
        manhattanDistance = std::abs(manhattanDistance - manhattanDisCurrent);
        result.push_back(new State<pair<int, int>>(std::make_pair(i + 1, j),
                                                   curState.getCost() + mat[i + 1][j] + manhattanDistance,
                                                   &curState, DOWN));
    }
    if (j < matrixSize - 1 && mat[i][j + 1] >= 0 && fatherJ != j + 1) {
        int manhattanDistance = std::abs(goal.getObject().first - (i)) + std::abs(goal.getObject().second - (j + 1));
        manhattanDistance = std::abs(manhattanDistance - manhattanDisCurrent);
        result.push_back(new State<pair<int, int>>(std::make_pair(i, j + 1),
                                                   curState.getCost() + mat[i][j + 1] + manhattanDistance,
                                                   &curState, RIGHT));
    }
    if (i > 0 && mat[i - 1][j] >= 0 && fatherI != i - 1) {
        int manhattanDistance = std::abs(goal.getObject().first - (i - 1)) + std::abs(goal.getObject().second - (j));
        manhattanDistance = std::abs(manhattanDistance - manhattanDisCurrent);
        result.push_back(new State<pair<int, int>>(std::make_pair(i - 1, j),
                                                   curState.getCost() + mat[i - 1][j] + manhattanDistance,
                                                   &curState, UP));
    }
    return  result;
}