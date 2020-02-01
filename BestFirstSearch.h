#include "Isearcher.h"
#include <queue>
#include <list>
#include <set>
#include <stdbool.h>
#include "State.h"
#include <string>
#include "CompareCost.h"
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

template <class solution, class T>
class BestFirstSearch :public Isearcher<solution, T>
{
private:
	int evaluatedNode;
	multiset <State<T>*, CompareCost<T>> openList;
	set<State<T>*> closed;
public:
	BestFirstSearch() {};
	~BestFirstSearch() {};
	string backTrace(State<T>* current, State<T>* initialState) {
		string toReturn = "";
		stack <State<T>*> traceStack;
		State<T> *tempState = current;
		while (!(*tempState == *initialState)) {
			traceStack.push(tempState);
			tempState = tempState->getCameFrom();
		}
		traceStack.push(initialState);
		int counter = 0;
		while (!traceStack.empty()) {
			counter++;
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
			toReturn += "(" + to_string(traceStack.top()->getCost()) + ")";
			traceStack.pop();
		}
		
		toReturn.pop_back();
		cout << counter << endl;
		return toReturn;
	}

	string search(Isearchable<T>* searchable) {
		this->insertToOpenList(searchable->getInitialState());
		while (this->getOpenListSize() > 0) {
			State<T>* n = popOpenList();
			closed.insert(n);
			if ( *n== *searchable->getGoalState()) {
				return backTrace(n,searchable->getInitialState() );
			}
			vector<State<T>*> successors = searchable->getPossibleNextStates(*n);
			int size = successors.size();
			for (State<T>* s : successors) {
				if (!isInCloseList(s) && !isInOpenList(s)) {
					s->setCameFrom(n);
					openList.insert(s);					
				}
				else if (!isInOpenList(s)) {
					updatePriority(s);
				}
			}
		}
		return "-1";
	}

	//save the node and delete it from the open list.
	State<T>* popOpenList() {
		evaluatedNode++;
		auto iter = this->openList.begin();
		State<T> *result = *iter;
		openList.erase(iter);
		return result;
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
	int getNumberOfNodesEvaluated() {
		return this->evaluatedNode;
	}

};