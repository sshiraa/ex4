//
// Created by shira on 19.1.2020.
//

#ifndef EX4__MYTESTCLIENTHANDLER_H_
#define EX4__MYTESTCLIENTHANDLER_H_

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include <sys/socket.h>
#include <unistd.h>
//#include <string>
//#include <vector>
//#include <fstream>
//#include <cstring>
//#include <map>
//#include <list>
//#include <regex>

class MyTestClientHandler : public ClientHandler {
 private:
  Solver<string, string> *solver;
  CacheManager *cacheManager;
 public:
  MyTestClientHandler(Solver<string, string> *solver, CacheManager *cacheManager) : solver(solver), cacheManager(cacheManager){}
  virtual void handleClient(int clientSocket);
  ~MyTestClientHandler(){
    delete (solver);
    delete (cacheManager);
  }
};

#endif //EX4__MYTESTCLIENTHANDLER_H_
