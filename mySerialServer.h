//
// Created by shira on 13.1.2020.
//
#include "Server.h"
#ifndef EX4__MYSERIALSERVER_H_
#define EX4__MYSERIALSERVER_H_

class mySerialServer : public Server {
  int open(int port, ClientHandler c);
  int stop();
  void openConnection();
};

#endif //EX4__MYSERIALSERVER_H_
