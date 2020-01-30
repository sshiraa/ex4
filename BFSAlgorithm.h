//
// Created by linor on 29/01/2020.
//
#ifndef EX4_BFSALGORITHM_H
#define EX4_BFSALGORITHM_H
#pragma once
#include "State.h"
#include "Isearcher.h"
#include <queue>
#include <stack>
#include <list>
#include <string>
template <class T>
class BFSAlgorithm :public Isearcher<T, string>
{
private:
    list<State<T>*> visitedNodes;
    queue<State<T>*> q;
    int evaluatedNode;
public:
    BFSAlgorithm();
    State<T>* popqList() {
        evaluatedNode++;
        State<T>* n = this->q.top();
        q.pop();
        return n;
    }
    //search Function
    string search(ISearchable<T>* searchable) {
        State<T>* initialState = searchable->getInitialState();
        q.push(initialState);
        visitedNodes.push_back(initialState);
        while (!q.empty()) {
            State<T>* s = popqList();
            visitedNodes.push_back(s);
            if (*s == (searchable->getGoalState())) {
                string toReturn = backTrace(s,searchable->getInitialState);
                return toReturn;
            }
            list<State<T>*> successorsList = searchable->getAllPossibleStates(s);
            int size = successorsList.size();
            for (State<T>* successor : successorsList) {
                if (!ContainedInvisitedNodes(s)) {
                    q.push(successor);
                    visitedNodes.push_back(successor);
                }
            }
        }
    }
    string backTrace(State<T>* current, State<T>* initialState) {
        stack <State<T>*> traceStack;
        State<T> *tempState = current;
        string toReturn = "";
        while (!(*tempState == *initialState)) {
            traceStack.push(tempState);
            tempState = tempState->cameFrom();
        }
        traceStack.push(initialState);
        while (!traceStack.empty()) {
            Direction d = traceStack.top()->getDirection();
            if (d == UP) {
                toReturn += "up,";
            }
            else if (d == DOWN) {
                toReturn += "down,";
            }
            else if (d == LEFT) {
                toReturn += "left,";
            }
            else if (d == RIGHT) {
                toReturn += "right,";
            }
            traceStack.pop();
        }
        toReturn.pop_back();
        return toReturn;
    }
    ~BFSAlgorithm();
    bool ContainedInvisitedNodes(State<T>* element) {
        bool is_in = visitedNodes.find(element) != visitedNodes.end();
        return is_in;
    }
    int getNumberOfNodeEvaluated() {
        return this->evaluatedNode;
    }
};
#endif //EX4_BFSALGORITHM_H
