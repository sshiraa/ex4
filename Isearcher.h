#pragma once

#include <string>
#include "Isearchable.h"

template <class solution, class T>
class Isearcher {
public:

	virtual string search(Isearchable<T> *searchable) = 0;

	virtual int getNumberOfNodesEvaluated() = 0;

	virtual ~Isearcher() {};
};
