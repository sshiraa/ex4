//
// Created by linor on 29/01/2020.
//

#ifndef EX4_ISEARCHABLE_H
#define EX4_ISEAgit RCHABLE_H
#include "State.h"
#include <vector>
using namespace std;
//interface of all classes we can send to search function
 template <class T>
class ISearchable {
     State<T> *getInitialState();

     State<T> *getGoalState();

     vector<State<T>*> getPossibleNextStates(State<T> &current);

     vector<State<T>*> getPossibleNextStates(State<T> &current, State<T> &goal);
};


#endif //EX4_ISEARCHABLE_H
