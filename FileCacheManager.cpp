//
// Created by shira on 27.1.2020.
//

#include "FileCacheManager.h"
#include <fstream>

FileCacheManager::FileCacheManager(string fileName) {
  string problem, solution;
  this->fileName=fileName;
  ifstream myfile(fileName);
  if (myfile.is_open()) {
    while (getline(myfile, problem)) {
      if( getline(myfile, solution)){
        solutionMap[problem]=solution;
      }else{
        throw invalid_argument("invalid number of line in file");
      }
    }
    myfile.close();
  }
}

bool FileCacheManager::isExist(string problem) {
  pthread_mutex_lock(&mutex);
  map<string, string>::iterator it = solutionMap.find(problem);
  pthread_mutex_unlock(&mutex);
  return it != solutionMap.end();
}

void FileCacheManager::insertSolution(string solution, string problem) {
  pthread_mutex_lock(&mutex);
  solutionMap[problem]=solution;
  ofstream myfile;
  myfile.open(fileName,std::ios::app);
  if (myfile.is_open()) {
    myfile << problem+"\n"+solution+"\n";
  }else{
    throw invalid_argument("invalid file");
  }
  myfile.close();
  pthread_mutex_unlock(&mutex);
}

string FileCacheManager::getSolution(string problem) {
  if(isExist(problem)) {
    return  solutionMap[problem];
  }else{
    throw invalid_argument("try to get a solution to a problem that not exist in the cache");
  }
}