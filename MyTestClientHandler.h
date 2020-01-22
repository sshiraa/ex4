//
// Created by shira on 19.1.2020.
//
#include "ClientHandler.h"
#ifndef EX4__MYTESTCLIENTHANDLER_H_
#define EX4__MYTESTCLIENTHANDLER_H_

class MyTestClientHandler : public ClientHandler {
 private:
  char *reversString(const char* str);
 public:
  int handleClient(int clientSocket);
};

#endif //EX4__MYTESTCLIENTHANDLER_H_
