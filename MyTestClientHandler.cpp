//
// Created by shira on 19.1.2020.
//

#include "MyTestClientHandler.h"
int MyTestClientHandler::handleClient ( int clientSocket ) {
  //reading from client
  char buffer[1024] = {0};
  int valread = read(clientSocket, buffer, 1024);
  std::cout << buffer << std::endl;

//writing back to client
  char *rev = reversString(buffer);//reversing the buffer content
  send(clientSocket, rev, strlen(rev), 0);
  std::cout << "Reversed message sent\n" << std::endl;
}

char * MyTestClientHandler::reversString(const char* str) {
  char *reversed;
  int strLen = strlen(str);
  for(int i = 0; i < strLen; i++) {
    reversed[i] = str[strLen - i - 1];//reversed.append(1, str[i]);
  }
  reversed[strLen] = '\n';//adding '\n' at the end

  return reversed;
}