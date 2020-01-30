//
// Created by shira on 19.1.2020.
//

#include "MyTestClientHandler.h"
void MyTestClientHandler::handleClient ( int clientSocket ) {
  string problem = "";
  string solution;
  while(true) {
    //reading from client to buffer
    char buffer[1024] = {0};
    int numRead = read(clientSocket, buffer, 1024);
    if (numRead > 0) {
      for(int i = 0; i < numRead; i++) {
        char currentChar = buffer[i];
        if (currentChar == '\n') {
          if(problem.length() > 0) {
            if(problem.compare("end")==0) {
              //we reached the end
              close(clientSocket);
              return;
            }
            //search for it in the cache
            if (cacheManager->isExist(problem)) {
              solution = cacheManager->getSolution(problem);
            } else {
              solution = solver->solve(problem);
              cacheManager->insertSolution(problem, solution);
            }
            solution = solution + '\n';//add '\n' at the end

            //writing back to client
            int size = send(clientSocket, solution.c_str(), solution.length(), 0);
            if (size < 0) {
              close(clientSocket);
              return;
            }
            problem = "";
            solution = "";
          }
        } else problem += currentChar;
      }
    }  else {
      if (errno == EWOULDBLOCK) {
        continue;
      }
      close(clientSocket);
      return;
    }
  }

/*  std::cout << buffer << std::endl;

//writing back to client
  char *rev = reversString(buffer);//reversing the buffer content
  send(clientSocket, rev, strlen(rev), 0);
  std::cout << "Reversed message sent\n" << std::endl;*/
}




/*
char * MyTestClientHandler::reversString(const char* str) {
  char *reversed;
  int strLen = strlen(str);
  for(int i = 0; i < strLen; i++) {
    reversed[i] = str[strLen - i - 1];//reversed.append(1, str[i]);
  }
  reversed[strLen] = '\n';//adding '\n' at the end

  return reversed;
}*/
