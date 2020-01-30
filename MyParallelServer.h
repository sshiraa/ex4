//
// Created by shira on 29.1.2020.
//

#ifndef EX4__MYPARALLELSERVER_H_
#define EX4__MYPARALLELSERVER_H_

#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <strings.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <pthread.h>

using namespace server_side;

#define MAX_CLIENTS

class MyParallelServer : public Server{

};

#endif //EX4__MYPARALLELSERVER_H_
