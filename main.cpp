#include <iostream>
#include "mySerialServer.h"
int main() {
  std::cout << "Hello, World!" << std::endl;
  mySerialServer * server = new mySerialServer();
  return 0;
}