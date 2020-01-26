//
// Created by shira on 12.1.2020.
//

#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <thread>
#include <pthread.h>



#ifndef EX4__SERVER_H_
#define EX4__SERVER_H_

#include "ClientHandler.h"
namespace server_side {
  class Server {
   public:
    virtual int open(int port, ClientHandler clientHandler) = 0;
    virtual int stop() = 0;
    virtual ~Server() {}
  };
}

#endif //EX4__SERVER_H_
