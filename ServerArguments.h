//
// Created by shira on 1.2.2020.
//

#ifndef EX4__SERVERARGUMENTS_H_
#define EX4__SERVERARGUMENTS_H_
#include "ClientHandler.h"
struct ServerArguments {
  int socket_id;
  ClientHandler* client_handler;
  struct sockaddr_in cli_addr;
  int clilen;
  volatile bool * is_close;

  ServerArguments(int socket_id, ClientHandler *client_handler, const sockaddr_in &cli_addr, int clilen,
                  volatile bool *is_close) : socket_id(socket_id), client_handler(client_handler),
                                             cli_addr(cli_addr), clilen(clilen), is_close(is_close) {}

};

#endif //EX4__SERVERARGUMENTS_H_
