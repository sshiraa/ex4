//
// Created by shira on 27.1.2020.
//

#ifndef EX4__FILECACHEMANAGER_H_
#define EX4__FILECACHEMANAGER_H_

#include <map>
#include "CacheManager.h"

class FileCacheManager : public CacheManager{
  map<string, string> solutionMap;
  string fileName;
  pthread_mutex_t mutex;
 public:
  FileCacheManager(string fileName);
  virtual bool isExist(string problem);
  virtual void insertSolution(string solution, string problem);
  virtual string getSolution(string problem);
  ~FileCacheManager(){
    pthread_mutex_destroy(&mutex);
  }
};

#endif //EX4__FILECACHEMANAGER_H_
