//
// Created by shira on 12.1.2020.
//

#ifndef EX4__CACHEMANAGER_H_
#define EX4__CACHEMANAGER_H_

#include <string>
using namespace std;
class CacheManager {
 public:
  virtual bool isExist(string problem)=0;
  virtual void insertSolution(string solution, string problem)=0;
  virtual string getSolution(string problem) = 0;
  virtual ~CacheManager(){}
};

#endif //EX4__CACHEMANAGER_H_
