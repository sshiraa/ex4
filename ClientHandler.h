//
// Created by shira on 12.1.2020.
//
#include <ios>
/*#include <stdio.h>
#include <cstring>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <thread>
#include <pthread.h>*/

#ifndef EX4__CLIENTHANDLER_H_
#define EX4__CLIENTHANDLER_H_
#include <iostream>
using namespace std;

class ClientHandler {
  public:
  virtual void handleClient(int clientSocket)=0;
  virtual ~ClientHandler(){}
};

#endif //EX4__CLIENTHANDLER_H_
