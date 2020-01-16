//
// Created by shira on 12.1.2020.
//

#ifndef EX4_CMAKE_BUILD_DEBUG_SEARCHABLE_H_
#define EX4_CMAKE_BUILD_DEBUG_SEARCHABLE_H_

template <T> class Searchable {
  State<T> getInitialState();
  bool isGoalState(State<T>);
  State<T>[] getAllPossibleStates(State<T>);

};

#endif //EX4_CMAKE_BUILD_DEBUG_SEARCHABLE_H_
