//
// Created by linor on 29/01/2020.
//

#ifndef EX4_ISEARCHER_H
#define EX4_ISEARCHER_H
#include "Matrix.h"
#include <string>
using namespace std;
//interface implemented by all the algorithms functions
template <class T,class Solution>
class Isearcher {
public:
    Isearcher();
    virtual string search(Matrix searchable);
    virtual int getNumberOfNodeEvaluated();
    ~Isearcher();
};
#endif //EX4_ISEARCHER_H
