//
// Created by shira on 29.1.2020.
//

#ifndef EX4__MYPARALLELSERVER_H_
#define EX4__MYPARALLELSERVER_H_

#define MAX_CLIENT 10


#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include <thread>
#include <stack>
#include "ClientHandler.h"
#include "Server.h"

class MyParallelServer : public server_side::Server {
  std::stack<pthread_t> threads;
  int sockfd{};
  int port{};
  ClientHandler* clientHandler{};
  bool toStop = false;
 public:
  int open(int port, ClientHandler *cH);
  virtual void startThreadOPeration(){}
  void stop();

  static void *startThreadClient(void *data);

  void start();

  virtual ~MyParallelServer() = default;
};


/*

#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <strings.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <algorithm>
#include <pthread.h>
#include <thread>
#include <sys/socket.h>
#include <vector>
#include "SocketManager.h"
#include "ServerArguments.h"
#include "ClientArguments.h"
#include "SocketManager.h"

using namespace server_side;

class MyParallelServer : public Server{
  volatile bool *is_close;
  int listen_num;
  thread* new_clients_thread;
  int sockettfed;

 public:
  MyParallelServer();

  MyParallelServer(int listion_num);

  virtual int open(int port, ClientHandler *client_handler);

  virtual void stop();

  virtual ~MyParallelServer();

};
*/

#endif //EX4__MYPARALLELSERVER_H_
