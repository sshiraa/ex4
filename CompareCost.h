//
// Created by linor on 29/01/2020.
//

#ifndef EX4_COMPARECOST_H
#define EX4_COMPARECOST_H
#include "State.h"
template <class T>
class CompareCost
{
public:
    bool operator()(State<T> *left, State<T> *right) const {
        return left->getCost() < right->getCost();
    };
};


#endif //EX4_COMPARECOST_H
