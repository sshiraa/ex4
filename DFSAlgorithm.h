//
// Created by linor on 29/01/2020.
//
#ifndef EX4_DFSALGORITHM_H
#define EX4_DFSALGORITHM_H
#include "Isearcher.h"
#include <string>
#include <list>
#include <stack>
#include "algorithm"
template <class T>
class DFSAlgorithm :public Isearcher<T,string>
{
private:
    int evaluatedNodes;
    stack<State<T>*> closeList;
    list<State<T>*> openList;

public:
    DFSAlgorithm();
    //search function
    string search(ISearchable<T>* searchable) {
        this->addToOpenList(searchable->getInitialState());
        //as long there is a node in the queue
        while (this->getOpenListSize() > 0) {
            State<T> *currentNode = this->popOpenList();
            State<T> *goalState = *searchable->getGoalState();
            if (*currentNode == *goalState) {
                string result = this->backTrace(currentNode, searchable->getInitialState());
              //  this->deleteEverything();
                return result;
            }
            if (!this->isInClosedList(currentNode)) {
                this->closedList.push_back(currentNode);
            }
            //vector of all successors of current node
            vector<State<T>*> successors = searchable->getPossibleNextStates(*currentNode);
            for (auto s: successors) {
                if (!this->isInClosedList(s) && !this->isInOpenList(s)) {
                    this->addToOpenList(s);
                }
            }
        }
        //this->deleteAll();
        return "-1";
    }
    //return true if an element in close list. else,return false
    bool isInClosedList(State<T>* checkIfInCloseList) {
        bool found = (std::find(closeList.begin(), closeList.end(), *checkIfInCloseList) != closeList.end());
        return found;
    }
    ~DFSAlgorithm();
    //return the string of the way
    string backTrace(State<T>* current, State<T>* initialState) {
        string toReturn = "";
        stack <State<T>*> traceStack;
        State<T> *tempState = current;
        while (!(*tempState == *initialState)) {
            traceStack.push(tempState);
            tempState = tempState->getCameFrom();
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
};

#endif //EX4_DFSALGORITHM_H
