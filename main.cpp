#include <iostream>
#include "mySerialServer.h"
int main() {
  std::cout << "Hello, World!" << std::endl;
  mySerialServer * server = new mySerialServer();
  ClientHandler client_handler = new MyTestClientHandler();
  server->open(5400, )
  return 0;
}