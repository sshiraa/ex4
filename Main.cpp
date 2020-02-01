//
// Created by shira on 27.1.2020.
//

#ifndef EX4__MAIN_H_
#define EX4__MAIN_H_

#include <iostream>
#include <chrono>
#include <thread>
#include <regex>
#include "FileCacheManager.h"
#include "Server.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"

//#include "Main.h"
#include "MyClientHandler.h"
#include "MyParallelServer.h"
#include "SolverAdapter.h"
#include "MySerialServer.h"

int main(int numArg, char *args[]) {

  if (numArg == 2 && regex_match(args[1], regex("^\\d+"))) {
    Server *server = new MyParallelServer();
    server->open(atoi(args[1]), new MyClientHandler(new SolverAdapter(), new FileCacheManager("test3.txt")));
    //this_thread::sleep_for(chrono::milliseconds(100000));
    server->stop();
    delete (server);
  } else {
    throw invalid_argument("Invalid main arguments");
  }
  return 0;
}








/*namespace server_side {
namespace boot {
class Main {
 public:
  static *//*int main(int numArg, char *args[]) {

    if (numArg == 2 && regex_match(args[1], regex("^\\d+"))) {
      Server *server = new MySerialServer();
      server->open(atoi(args[1]),
                   new MyTestClientHandler(new StringReverser, new FileCacheManager("test2.txt")));
      this_thread::sleep_for(chrono::milliseconds(100000));
      server->stop();
      delete (server);
    } else {
      throw invalid_argument("Invalid Main arguments");
    }

    return 0;
  }
*//*};
}
}*/
#endif //EX4__MAIN_H_

