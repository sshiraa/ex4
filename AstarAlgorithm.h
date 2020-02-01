#pragma once
#include <string>
#include "Isearchable.h"
#include "CompareCost.h"
#include "Isearcher.h"
#include <set>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
template <class Solution, class T>
class AstarAlgorithm :public Isearcher<Solution, T> 
{
private:
	int evaluatedNode{};
	multiset<State<T>*, CompareCost<T>> openList;
	vector<State<T>*> closedList;
public:
	AstarAlgorithm() {
		this->evaluatedNode = 0;
	}
	void addToOpenList(State<T> *current) {
		openList.insert(current);
	}
	//get searchable and return the path of AstarAlgorithm
	string search(Isearchable<T>* searchable) {
		//adding the initalState to the open list.
		addToOpenList(searchable->getInitialState());
		while (this->getOpenListSize() > 0) {
			//start develop the node
			State<T> *nodeToDevelop = this->popOpenList();
			this->closedList.push_back(nodeToDevelop);
			//if we reach the goal state
			if (*nodeToDevelop == *searchable->getGoalState()) {
				string result = this->backTrace(nodeToDevelop, searchable->getInitialState());
				//this->deleteEverything();
				return result;
			}
			//get the successors of current node
			std::vector<State<T>*> successors = searchable->getPossibleNextStates(*nodeToDevelop, *searchable->getGoalState());
			//for all of them
			for (auto successor : successors) {
				if (!this->isInClosedList(successor) && !this->isInOpenList(successor)) {
					this->addToOpenList(successor);
				}
				else if (!this->isInOpenList(successor)) {
					this->updatePriority(successor);
				}
			}
		}
		//this->deleteEverything();
		return "-1";
	};
	
	bool isInClosedList(State<T> *current) {
		for (auto node : closedList) {
			if (*current == *node) {
				return true;
			}
		}
		return false;
	}


	State<T>* popOpenList() {
		evaluatedNode++;
		auto iter = this->openList.begin();
		State<T> *n = *iter;
		this->openList.erase(iter);
		return n;
	}
	void insertToOpenList(State<T>* stateForInsert) {
		this->openList.insert(stateForInsert);
	}
	int getOpenListSize() {
		return this->openList.size();
	}
	//return true if element in openList,else false
	bool isInOpenList(State<T>* s) {
		for (auto elements : openList) {
			if (*s == *elements) {
				return true;
			}
		}
		return false;
	}
	//return true if element in closeList,else false
	bool isInCloseList(State<T>* s) {
		for (auto elements : closedList) {
			if (*s == *elements) {
				return true;
			}
		}
		return false;
	}
	void deleteEverything() {
		while (!openList.empty()) {
			auto item = openList.front();
			openList.pop();
			delete item;
		}
		closedList.clear();
	}
	string backTrace(State<T>* current, State<T>* initialState) {
		string toReturn="";
		stack<State<T>*> traceStack;
		State<T>* tempState = current;
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
		//	
		}
		toReturn.pop_back();
		cout << counter << endl;
		return toReturn;
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
	~AstarAlgorithm() {}
	int getNumberOfNodesEvaluated() { return this->evaluatedNode; }
};