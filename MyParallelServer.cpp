//
// Created by shira on 29.1.2020.
//

#include "MyParallelServer.h"

struct serverData {
  int port;
  int socketfd;
  bool active;
  ClientHandler *clientHandler;
};