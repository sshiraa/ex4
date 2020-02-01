//
// Created by shira on 1.2.2020.
//

#ifndef EX4__CLIENTARGUMENTS_H_
#define EX4__CLIENTARGUMENTS_H_
#include "ClientHandler.h"
struct ClientArguments {
  ClientHandler *client_handler;
  int socket_id;

  ClientArguments(ClientHandler *client_handler, int socket_id) : client_handler(client_handler),
                                                                  socket_id(socket_id) {}

};

#endif //EX4__CLIENTARGUMENTS_H_
