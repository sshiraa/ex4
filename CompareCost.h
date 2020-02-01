#pragma once
#include "State.h"
template <class T>
class CompareCost
{
public:
	bool operator()(State<T> *left, State<T> *right) const {
		return left->getCost() < right->getCost();
	};
};

