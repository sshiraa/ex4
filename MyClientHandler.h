//
// Created by shira on 1.2.2020.
//

#ifndef EX4__MYCLIENTHANDLER_H_
#define EX4__MYCLIENTHANDLER_H_

#define END_MESSAGE "end"

#include <vector>
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

namespace server_side {
class MyClientHandler : public ClientHandler {
  /*Solver<string,vector<vector<double >>> *solver;*/
  Solver<string,string> *solver;
  CacheManager *cacheManager;

  vector <double > splitByComma(string str);

 public:
  /*MyClientHandler(Solver<string, vector<vector<double >>> *s, CacheManager *c) : solver(s), cacheManager(c) {}*/
  MyClientHandler(Solver<string, string> *s, CacheManager *c) : solver(s), cacheManager(c) {}

  virtual void handleClient(int socket) ;

  ~MyClientHandler(){
    delete (solver);
    delete (cacheManager);
  }
};
}

#endif //EX4__MYCLIENTHANDLER_H_
