//
// Created by linor on 29/01/2020.
//

#ifndef EX4_BESTFIRSTSEARCHALGORITHM_H
#define EX4_BESTFIRSTSEARCHALGORITHM_H
#include "Isearcher.h"
#include <queue>
#include <list>
#include <set>
#include <stdbool.h>
#include "State.h"
#include <string>
#include "CompareCost.h"
//#include "CompareCost.h"
using namespace std;

template <class T>
class BestFirstSearch :public Isearcher<T, string>
{
private:
    int evaluatedNode;
    multiset <State<T>*, CompareCost<T>> openList;
    set<State<T>*> closed;
public:
    BestFirstSearch();
    ~BestFirstSearch();

    string search(ISearchable<T>* searchable) {
        this->insertToOpenList(searchable->getInitialState);
        while (this->getOpenListSize() > 0) {
            State<T>* n = popOpenList();
            closed.insert(n);
            if (searchable->getGoalState()) {
                //return backTrace();
            }
            list<State<T>*> successors = searchable->getAllPossibleStates(n);
            int size = successors.size();
            for(State<T>* s : successors){
                if (!isInCloseList(s)&&!isInOpenList(s)) {
                    s->setCameFrom(n);
                    closed.insert(s);
                }
                else if(!isInOpenList(s)) {
                    updatePriority(s);
                }
            }
        }
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
        for (auto elements : closed) {
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
                   // delete element;
                    openList.insert(stateForUpdate);
                }
            }
        }
    }
};



#endif //EX4_BESTFIRSTSEARCHALGORITHM_H
