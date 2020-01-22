//
// Created by shira on 12.1.2020.
//
#include <stdio.h>
#include <cstring>
#include <sys/socket.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <thread>
#include <pthread.h>
#ifndef EX4__CLIENTHANDLER_H_
#define EX4__CLIENTHANDLER_H_
using namespace std;

class ClientHandler {
  public:
  int handleClient(int clientSocket);
};

#endif //EX4__CLIENTHANDLER_H_
