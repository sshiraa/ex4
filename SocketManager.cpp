//
// Created by shira on 1.2.2020.
//


#include "SocketManager.h"

SocketManager::SocketManager(int sockfd) : sockfd(sockfd) {}


std::string SocketManager::getMsg() {
  char buffer[BUFFER_SIZE];
  /* If connection is established then start communicating */
  bzero(buffer, BUFFER_SIZE);
  int n = read(sockfd, buffer, BUFFER_SIZE - 1);

  if (n < 0) {
    throw "error getting massage from socket";
  }

  return std::string(buffer);
}

std::string SocketManager::getLine() {
  std::string answer = extra_data;
  //get at least 1 set of data
  while (answer.find("\n") == std::string::npos) {
    answer += getMsg();
  }
  //put the rest of the data to be a part of the next set
  extra_data = answer.substr(answer.find_first_of('\n') + 1, answer.size() - 1);

  //get exactly one set of data
  answer = answer.substr(0, answer.find_first_of('\n'));


  while (answer[0] == '\n') {
    answer = answer.substr(1, answer.size() - 1);
  }
  return answer;

}

void SocketManager::sendMsg(std::string &msg) {
  /* Send message to the server */
  int n = write(sockfd, msg.c_str(), msg.length());

  if (n < 0) {
    throw "error sending throw socket";
  }


}
