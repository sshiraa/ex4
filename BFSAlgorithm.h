#pragma once
#include <string>
#include <queue>
#include <stack>
#include <list>
#include "Isearcher.h"
#include <unordered_set>
#include <set>
#include <iostream>
//#include <iterator>
using namespace std;
template <class solution, class T>
class BFSAlgorithm:public Isearcher<solution, T>
{
private:
	unordered_set<State<T>*>visitedNodes;
	queue<State<T>*> q;
	int evaluatedNode=0;
public:
	BFSAlgorithm() { };
	State<T>* popqList() {
		evaluatedNode++;
		State<T>* n = this->q.front();
		q.pop();
		return n;
	}
	~BFSAlgorithm() {};
	string search(Isearchable<T>* searchable) {
		State<T>* initialState = searchable->getInitialState();
		q.push(initialState);
		//visitedNodes.insert(initialState);
		while (!q.empty()) {
			//the first element at qlist
			State<T>* s = popqList();
			if (*s == *searchable->getGoalState()) {
				string toReturn = backTrace(s, searchable->getInitialState());
				return toReturn;
			}
			//visitedNodes.insert(s);
			
			//list of current's successors
			
			vector<State<T>*> successorsList = searchable->getPossibleNextStates(*s);
			int size = successorsList.size();
			if (size > 0) {
				for (State<T>* successor : successorsList) {
					if (!ContainedInvisitedNodes(successor)) {
						q.push(successor);
						visitedNodes.insert(successor);
					}
				}
			}
		}
		return "-1";
	}
	//return the solution string 
	string backTrace(State<T>* current, State<T>* initialState) {
		stack <State<T>*> traceStack;
		State<T> *tempState = current;
		string toReturn = "";
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
		cout << counter << endl;
		toReturn.pop_back();
		return toReturn;
	}
	bool ContainedInvisitedNodes(State<T>* element) {
		for (auto node : visitedNodes) {
			if (*element == *node) {
				return true;
			}
		}
		return false;
	}
	//get the num of node evaluated
	int getNumberOfNodesEvaluated() {
		return this->evaluatedNode;
	}
};

