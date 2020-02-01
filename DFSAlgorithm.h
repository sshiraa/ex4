#pragma once
#include "Isearcher.h"
#include <string>
#include <list>
#include <stack>
#include "algorithm"
#include <iostream>
//template <class T>
template <class solution, class T>
class DFSAlgorithm :public Isearcher<solution, T>
{
private:
	int evaluatedNode;
	stack<State<T>*>  openList ;
	vector<State<T>*> closedList;
public:
	DFSAlgorithm() {};
	int getOpenListSize() { return this->openList.size(); }
	//search function
	string search(Isearchable<T>* searchable) {
		this->addToOpenList(searchable->getInitialState());
		//as long there is a node in the queue
		while (this->getOpenListSize() > 0) {
			State<T> *currentNode = this->popOpenList();
			State<T> *goalState = searchable->getGoalState();
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
			for (auto s : successors) {
				if (!this->isInClosedList(s) && !this->isInOpenList(s)) {
					this->addToOpenList(s);
				}
			}
		}
		//this->deleteAll();
		return "-1";
	}
	bool isInOpenList(State<T> *current) {
		bool isFound = false;
		stack<State<T>*> temp;
		while (!openList.empty()) {
			if (*openList.top() == *current) {
				isFound = true;
				break;
			}
			temp.push(openList.top());
			openList.pop();
		}
		while (!temp.empty()) {
			openList.push(temp.top());
			temp.pop();
		}
		return isFound;
	}

	/*bool isInOpenList(State<T>* s) {
		for (auto elements : openList) {
			if (*s == *elements) {
				return true;
			}
		}
		return false;
	}*/
	void addToOpenList(State<T> *current) {
		openList.push(current);
	}
	//return true if an element in close list. else,return false
	//bool isInClosedList(State<T>* checkIfInCloseList) {
	//	bool found = true;
	//	//bool found = (std::find(closedList.begin(), closedList.end(), *checkIfInCloseList) != closedList.end());
	//	return found;
	//}
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
		State<T>* n = this->openList.top();
		this->openList.pop();
		return n;
	}
	~DFSAlgorithm() {};
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
		int counter = 0;
		while (!traceStack.empty()) {
			Direction d = traceStack.top()->getDirection();
			counter++;
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
		cout << counter << endl;
		toReturn.pop_back();
		return toReturn;
	}
	int getNumberOfNodesEvaluated() {
		return this->evaluatedNode;
	}
};
