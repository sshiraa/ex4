#pragma once

#include <vector>
#include "State.h"

using namespace std;

template <class T>

class Isearchable {

public:

	virtual State<T> *getInitialState() = 0;

	virtual State<T> *getGoalState() = 0;

	virtual vector<State<T>*> getPossibleNextStates(State<T> &current) = 0;

	virtual vector<State<T>*> getPossibleNextStates(State<T> &current, State<T> &goal) = 0;
};

