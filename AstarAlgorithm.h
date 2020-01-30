//
// Created by linor on 29/01/2020.
//
#ifndef EX4_ASTARALGORITHM_H
#define EX4_ASTARALGORITHM_H
#include <string>
#include "ISearchable.h"
#include "CompareCost.h"
#include "Isearcher.h"
#include <set>
using namespace std;
template <class Solution,class T>
class AstarAlgorithm:public Isearcher<Solution,T> {
private:
    int evaluatedNode{};
    multiset<State<T>*, CompareCost<T>> openList;
    vector<State<T>*> closedList;
public:
    AstarAlgorithm(){
        this->evaluatedNode = 0;
    }
    std::string search(ISearchable<T>* searchable){
        //adding the initalState to the open list.
        this->addToOpenList(searchable->getInitialState());
        while (this->getOpenListSize() > 0) {
            //start develop the node
            State<T> *nodeToDevelop = this->popOpenList();
            this->closedList.push_back(nodeToDevelop);
            //if we got to the goal
            if (*nodeToDevelop == *searchable->getGoalState()) {
                string result = this->backTrace(nodeToDevelop, searchable);
                //this->deleteEverything();
                return result;
            }
            std::vector<State<T>*> successors = searchable->getPossibleNextStates(*nodeToDevelop, *searchable->getGoalState());
            for (auto successor : successors) {
                if (!this->isInClosedList(successor) && !this->isInOpenList(successor)) {
                    this->addToOpenList(successor);
                } else if (!this->isInOpenList(successor)) {
                    this->updateStatePriority(successor);
                }
            }
        }
        //this->deleteEverything();
        return "-1";
    }
    //save the node and delete it from the open list.
    State<T>* popOpenList() {
        evaluatedNode++;
        State<T>* n = this->openList.top();
        this->openList.pop();
        return n;
    }
    void insertToOpenList(State<T>* stateForInsert) {
        this->openList.insert(stateForInsert);
    }
    int getOpenListSize() {
        return this->openList.size();
    }
    bool isInOpenList(State<T>* s) {
        for (auto elements : openList) {
            if (*s == *elements) {
                return true;
            }
        }
        return false;
    }
    bool isInCloseList(State<T>* s) {
        for (auto elements : closedList) {
            if (*s == *elements) {
                return true;
            }
        }
        return false;
    }
    void updatePriority(State<T>* stateForUpdate) {
        int flag = 0;
        for (auto element : this->openList) {
            if (*stateForUpdate == *element) {
                flag = 1;
                if (stateForUpdate->getCost() < element->getCost()) {
                    openList.erase(element);
                  //  delete element;
                    openList.insert(stateForUpdate);
                }
            }
        }
    }

};


#endif //EX4_ASTARALGORITHM_H
